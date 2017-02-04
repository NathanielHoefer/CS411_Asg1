//==============================================================================
// Assignment 1 - Trip Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#include "Trip.hpp"
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;


//==============================================================================
// CONSTRUCTORS / DESTRUCTORS
//==============================================================================


Trip::Trip(Vehicle &vehicle, Parameters &parms)
{
	mParms = parms;
	mVehicle = vehicle;
	mFuelPurchased = 0.0;
	mFuelConsumed = 0.0;
	mCityMiles = 0;
	mHighwayMiles = 0;
	mDriveTime = 0;
	mGStationCnt = 0;
	mTripTime = 0;
}


//==============================================================================
// ACCESSORS / MUTATORS
//==============================================================================


Vehicle Trip::getVehicle() 		{ return mVehicle; }

double Trip::getFuelPurchased() 	{ return mFuelPurchased; }

double Trip::getFuelConsumed() 	{ return mFuelConsumed; }

double Trip::getCityMiles() 		{ return mCityMiles; }

double Trip::getHighwayMiles()		{ return mHighwayMiles; }

int Trip::getDriveTime() 			{ return mDriveTime; }

int Trip::gStationCount() 		{ return mGStationCnt; }


//==============================================================================
// MEMBER FUNCTIONS
//==============================================================================


void Trip::runTrip(vector<TripLeg> &legs)
{

	double milesTravelled = 0;
	double gasDistance = mParms.getGasDistance();

	for (int i = 0; i < (int)legs.size(); i++) {

		// Sets MPG for the trip leg
		int mpg = mVehicle.getMPG(legs.at(i).getRoadType());
		int legDistance = legs.at(i).getDistance();
		TripLeg::RoadType roadType = legs.at(i).getRoadType();

		cout << "MPG: " << mpg;


		// Sets to remaining miles until gas station
		double legTravelled;		// The miles travelled in the current leg
		legTravelled = fmod((gasDistance - milesTravelled),gasDistance);
		mVehicle.consumeFuel(legTravelled / mpg);
		bool isNextStationInLeg = true;

		cout << " legTravelled: " << legTravelled << " Tank: "
				<< mVehicle.getCurrentFuel() << endl;


		// Travel until end of leg
		while (legTravelled < legDistance) {

			// Station in next leg?
			if ((legTravelled + gasDistance) > legDistance) {
				isNextStationInLeg = false;
			}

			// Will it make it to the next gas station?
			bool isEnoughGasUntilStation = true;
			if (isNextStationInLeg) {

				double fuelConsumed = mVehicle.calcFuelConsumed(gasDistance, roadType);
				if (fuelConsumed > mVehicle.getCurrentFuel()) {
					isEnoughGasUntilStation = false;
				}
			} else {
				// TODO Calculate fuel to next station
			}


			// Stopping at gas station if needed
			if (!isEnoughGasUntilStation) {
				increaseFuelPurchased();
				mVehicle.fillTank();
				mGStationCnt++;
			}

			// Update current local travel and getVehicle tank
			if (isNextStationInLeg) {
				legTravelled += gasDistance;
				mVehicle.consumeFuel(gasDistance / mpg);
			} else {
				double remainder = legDistance - legTravelled;
				legTravelled += remainder;
				mVehicle.consumeFuel(remainder / mpg);
			}
		}

		// End of tripleg calculations
		mFuelConsumed += mVehicle.calcFuelConsumed(legDistance, roadType);
		mDriveTime += calcDriveTime(legDistance, roadType);
		if (roadType == TripLeg::CITY) {
			mCityMiles += legDistance;
		} else if (roadType == TripLeg::HIGHWAY) {
			mHighwayMiles += legDistance;
		}
	}

	// Calculate Total Time
	int refuelTime, restroomTime, sleepTime;
	refuelTime = calcRefuelTime();
	restroomTime = calcRestroomTime();
	sleepTime = calcSleepTime();
	mTripTime = mDriveTime + refuelTime + restroomTime + sleepTime;

}


//==============================================================================


void Trip::printTripDetails()
{
	// Calculations for centering title
	int titleLen = mVehicle.getMake().size() + mVehicle.getModel().size() + 1;
	int leftTitleSpace = (56 - titleLen) / 2;


	// Calculations for formatted time
	int days, hours, minutes, remainingTime;
	remainingTime = mTripTime;
	days = mTripTime / (24 * 60);
	remainingTime = mTripTime % (24 * 60);
	hours = remainingTime / 60;
	minutes = remainingTime % 60;

	cout << "========================================================" << endl;
	cout << setw(leftTitleSpace) << "";
	cout << mVehicle.getMake() << " " << mVehicle.getModel() 		   << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << left << fixed << setprecision(2);
	cout << "Tank Size = " << setw(9) << mVehicle.getTankSize();
	cout << "City MPG = " << setw(8) << mVehicle.getCityMPG();
	cout << "Highway MPG = " << mVehicle.getHighwayMPG() << endl;;
	cout << "--------------------------------------------------------" << endl;
	cout << "Trip time(minutes) = " << setw(7) << mTripTime;
	cout << "Trip time(d.hh:mm) = " << days << "." << setfill('0') << right
			<< setw(2) << hours << ":" << setw(2) << minutes << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << left << setfill(' ');
	cout << "Trip cost based on fuel added = $" << calcGasCost(true) << endl;
	cout << "Trip cost based on fuel used  = $" << calcGasCost(false) << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Fuel added = " << setw(15) << setprecision(4) << mFuelPurchased;
	cout << "Fuel remaining = "
			<< mVehicle.getTankSize() - mVehicle.getCurrentFuel() << endl;
	cout << "Fuel used  = " << setw(15) << mFuelConsumed;
	cout << "Fuel stops     = " << mGStationCnt << endl;;
	cout << "========================================================" << endl;
	cout << endl;
}


//==============================================================================


int Trip::calcDriveTime(double miles, TripLeg::RoadType roadType)
{
	int mph;

	if (roadType == TripLeg::CITY) {
		mph = mParms.getCityMph();
	} else if (roadType == TripLeg::HIGHWAY) {
		mph = mParms.getHighwayMph();
	}

	return (miles / mph) * 60;
}


//==============================================================================


int Trip::calcRefuelTime()
{
	return mGStationCnt * mParms.getRefuelTime();
}


//==============================================================================


int Trip::calcRestroomTime()
{
	return mGStationCnt * mParms.getRestroomTime();
}


//==============================================================================


int Trip::calcSleepTime()
{
	double numOfNaps = mDriveTime / mParms.getAwakeTime();

	// Checks to see if arrival is exactly at nap time
	if ((int)numOfNaps % mParms.getNapTime() == 0) {
		numOfNaps--;
	}

	return (int)numOfNaps * mParms.getNapTime();
}


//==============================================================================


double Trip::calcGasCost(bool isFuelAdded)
{
	double cost;

	if (isFuelAdded) {
		cost = mFuelPurchased * mParms.getFuelPrice();
	} else {
		cost = mFuelConsumed * mParms.getFuelPrice();
	}

	return cost;
}


//==============================================================================


void Trip::increaseFuelConsumed(double miles, TripLeg::RoadType roadType)
{
	double gallons = mVehicle.calcFuelConsumed(miles, roadType);

	mFuelConsumed += gallons;
}


//==============================================================================


void Trip::increaseFuelPurchased()
{
	mFuelPurchased += mVehicle.getTankSize() - mVehicle.getCurrentFuel();
}
