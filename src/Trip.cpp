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

int Trip::getTripTime()			{ return mTripTime; }

int Trip::gStationCount() 		{ return mGStationCnt; }


//==============================================================================
// MEMBER FUNCTIONS
//==============================================================================


void Trip::runTrip(vector<TripLeg> &legs)
{

	double milesTravelled = 0;
	double gasDistance = mParms.getGasDistance();

	for (int i = 0; i < (int)legs.size(); i++) {

		cout << "Leg: " << i;

		// Sets MPG for the trip leg
		int mpg = mVehicle.getMPG(legs.at(i).getRoadType());
		double legDistance = legs.at(i).getDistance();
		TripLeg::RoadType roadType = legs.at(i).getRoadType();

		cout << " MPG: " << mpg;


		// Sets to remaining miles until gas station
		double legTravelled;		// The miles travelled in the current leg
		legTravelled = milesTravelled;
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
			double fueltoStation;
			if (isNextStationInLeg) {
				fueltoStation = mVehicle.calcFuelConsumed(gasDistance, roadType);
			} else {
				fueltoStation = calcFuelUntilStation(legs, i, legTravelled);
			}


			// Stopping at gas station if needed
			if (fueltoStation > mVehicle.getCurrentFuel()) {
				cout << "-------Before Refuel Tank: " << mVehicle.getCurrentFuel() << endl;
				increaseFuelPurchased();
				mVehicle.fillTank();
				mGStationCnt++;

				cout << "---Gas Stop: " << mGStationCnt << " Leg: " << i
						<< " leg Travelled: " << legTravelled << endl;
			}

			// Update current local travel and getVehicle tank
			if (isNextStationInLeg) {
				legTravelled += gasDistance;
				mVehicle.consumeFuel(gasDistance / mpg);
			} else {
				double remainder = legDistance - legTravelled;
				legTravelled += remainder;
				milesTravelled = gasDistance - remainder;
				mVehicle.consumeFuel(remainder / mpg);
			}

			cout << "-----Leg: " << i << " Leg Travelled: " << legTravelled
					<< " Tank: " << mVehicle.getCurrentFuel() << endl;
		}

		// End of tripleg calculations
		mFuelConsumed += mVehicle.calcFuelConsumed(legDistance, roadType);
		mDriveTime += round(calcDriveTime(legDistance, roadType));
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

	cout << "RefuelT = " << refuelTime << " RestRT = " << restroomTime << " SleepT = " << sleepTime << endl;

	mTripTime = mDriveTime + refuelTime + restroomTime + sleepTime;

	cout << "City Miles = " << mCityMiles << " Highway Miles = " << mHighwayMiles
			<< " Total Miles = " << mCityMiles + mHighwayMiles << endl << endl;
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
	cout << "Fuel stops     = " << mGStationCnt << endl;
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
	return (mGStationCnt * mParms.getRestroomTime()) / 2;
}


//==============================================================================


int Trip::calcSleepTime()
{
	int numOfNaps = mDriveTime / mParms.getAwakeTime();

	// Checks to see if arrival is exactly at nap time
	if (numOfNaps != 0 && numOfNaps % mParms.getNapTime() == 0) {
		numOfNaps--;
	}

	return numOfNaps * mParms.getNapTime();
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


//==============================================================================


double Trip::calcFuelUntilStation(vector<TripLeg> &tripLegs,
								  int currLeg, double legTravelled)
{
	double cityMiles, highwayMiles;
	cityMiles = highwayMiles = 0;
	TripLeg::RoadType type = tripLegs.at(currLeg).getRoadType();

	double gasDist = mParms.getGasDistance();

	// Add remaining miles in current trip
	if (type == TripLeg::CITY) {
		cityMiles += tripLegs.at(currLeg).getDistance() - legTravelled;
	} else if (type == TripLeg::HIGHWAY) {
		highwayMiles += tripLegs.at(currLeg).getDistance() - legTravelled;
	}

	// Loop until next gas station is found
	for (int i = currLeg + 1; i < (int)tripLegs.size(); i++) {
		double tripDist = tripLegs.at(i).getDistance();
		TripLeg::RoadType type = tripLegs.at(i).getRoadType();
		double distance = cityMiles + highwayMiles;


		if (distance < gasDist) {
			// Gas station is in current trip leg
			if ((distance + tripDist) > gasDist) {
				// Add the remainder of the distance
				if (type == TripLeg::CITY) {
					cityMiles += gasDist - distance;
				} else if (type == TripLeg::HIGHWAY) {
					highwayMiles += gasDist - distance;
				}
			} else {
				// Trip leg doesn't contain gas station
				if (type == TripLeg::CITY) {
					cityMiles += tripDist;
				} else if (type == TripLeg::HIGHWAY) {
					highwayMiles += tripDist;
				}
			}
		} else {
			// To exit loop
			i = tripLegs.size();
		}
	}

	double gallons = mVehicle.calcFuelConsumed(cityMiles, TripLeg::CITY) +
					 mVehicle.calcFuelConsumed(highwayMiles, TripLeg::HIGHWAY);

	return gallons;
}
