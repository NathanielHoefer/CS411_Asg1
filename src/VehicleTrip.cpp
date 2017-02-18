//==============================================================================
// Assignment 1 - VehicleTrip Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#include "VehicleTrip.hpp"

#include <math.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

VehicleTrip::VehicleTrip(Vehicle &vehicle, Parameters &parms)
{
	mParms = 		parms;
	mVehicle = 		vehicle;
	mFuelPurchased = 0.0;
	mFuelConsumed = 0.0;
	mCityMiles = 	0;
	mHighwayMiles = 0;
	mDriveTime = 	0;
	mGStationCnt = 	0;
	mTripTime = 	0;
}

Parameters VehicleTrip::getParms()			{ return mParms; }
Vehicle VehicleTrip::getVehicle() 			{ return mVehicle; }
double 	VehicleTrip::getFuelPurchased() 	{ return mFuelPurchased; }
double 	VehicleTrip::getFuelConsumed() 		{ return mFuelConsumed; }
double 	VehicleTrip::getCityMiles() 		{ return mCityMiles; }
double 	VehicleTrip::getHighwayMiles()		{ return mHighwayMiles; }
int 	VehicleTrip::getDriveTime() 		{ return mDriveTime; }
int 	VehicleTrip::getTripTime()			{ return mTripTime; }
int 	VehicleTrip::getGStationCount() 	{ return mGStationCnt; }

void VehicleTrip::runTrip(vector<TripLeg> &legs)
{

	double milesTravelled = 0;
	double gasDistance = mParms.getGasDistance();

	int gasStations = 0;

	for (int i = 0; i < (int)legs.size(); i++) {

		cout << "Leg: " << i+1;

		// Sets MPG for the trip leg
		int mpg = mVehicle.getMPG(legs.at(i).getRoadType());
		double legDistance = legs.at(i).getDistance();
		TripLeg::RoadType roadType = legs.at(i).getRoadType();

		cout << "	  MPG: " << mpg;


		// Sets to remaining miles until gas station
		double legTravelled;		// The miles travelled in the current leg

		if (milesTravelled > legDistance) {
			legTravelled = legDistance;
		} else {
			legTravelled = milesTravelled;
		}

		mVehicle.consumeFuel(legTravelled / mpg);
		bool isNextStationInLeg = true;

		cout << "	legTravelled: " << setw(7) << legTravelled << "	Tank: "
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

				cout << "---Gas Stop: " << mGStationCnt << "	Leg: " << i
						<< "	leg Travelled: " << legTravelled << endl;
			}

			cout << "-----Gas Station: " << gasStations << "	Mile: " << milesTravelled;
			gasStations++;

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

			cout << "	Leg: " << i << "	Leg Travelled: " << legTravelled
					<< "	Tank: " << mVehicle.getCurrentFuel() << endl;
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

std::ostream & operator <<(std::ostream &lhs, VehicleTrip &rhs)
{
	std::stringstream stream;

	lhs << rhs.mVehicle;
	stream << rhs.mTripTime;
	lhs << stream.str() + ",";
	stream.str("");
	stream.clear();
	stream << rhs.mFuelPurchased;
	lhs << stream.str() + ",";
	stream.str("");
	stream.clear();
	stream << rhs.mFuelConsumed;
	lhs << stream.str() + ",";
	stream.str("");
	stream.clear();
	stream << rhs.mGStationCnt;
	lhs << stream.str();

	return lhs;
}

int VehicleTrip::calcDriveTime(double miles, TripLeg::RoadType roadType)
{
	int mph;
	if (roadType == TripLeg::CITY) {
		mph = mParms.getCityMph();
	} else if (roadType == TripLeg::HIGHWAY) {
		mph = mParms.getHighwayMph();
	}
	return (miles / mph) * 60;
}

int VehicleTrip::calcRefuelTime()
{
	return mGStationCnt * mParms.getRefuelTime();
}

int VehicleTrip::calcRestroomTime()
{
	return (mGStationCnt * mParms.getRestroomTime()) / 2;
}

int VehicleTrip::calcSleepTime()
{
	int numOfNaps = mDriveTime / mParms.getAwakeTime();

	// Checks to see if arrival is exactly at nap time
	if (numOfNaps != 0 && numOfNaps % mParms.getNapTime() == 0)
		numOfNaps--;

	cout << "Awake Time = " << mParms.getAwakeTime() << " Number of naps = " << numOfNaps << " Nap Time = " << mParms.getNapTime() << endl;
	return numOfNaps * mParms.getNapTime();
}

void VehicleTrip::increaseFuelConsumed(double miles, TripLeg::RoadType roadType)
{
	double gallons = mVehicle.calcFuelConsumed(miles, roadType);
	mFuelConsumed += gallons;
}

void VehicleTrip::increaseFuelPurchased()
{
	mFuelPurchased += mVehicle.getTankSize() - mVehicle.getCurrentFuel();
}

double VehicleTrip::calcFuelUntilStation(vector<TripLeg> &tripLegs, int currLeg, double legTravelled)
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


