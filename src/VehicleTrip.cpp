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

	double milesUntilStation = 0;
	double gasDistance = mParms.getGasDistance();	// Distance between each station

	// Process each trip leg
	for (int i = 0; i < (int)legs.size(); i++) {

		// Sets MPG for the trip leg
		int mpg = mVehicle.getMPG(legs.at(i).getRoadType());
		double legDistance = legs.at(i).getDistance();
		TripLeg::RoadType roadType = legs.at(i).getRoadType();

		// Sets to remaining miles until gas station
		double legTravelled;		// The miles travelled in the current leg

		// Is station in next leg?
		if (milesUntilStation > legDistance) {
			legTravelled = legDistance;
			milesUntilStation -= legDistance;
		} else {
			legTravelled = milesUntilStation;
		}

		mVehicle.consumeFuel(legTravelled / mpg);
		bool isNextStationInLeg = true;

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
				milesUntilStation = gasDistance - remainder;
				mVehicle.consumeFuel(remainder / mpg);
			}
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
	refuelTime = round(calcRefuelTime());
	restroomTime = round(calcRestroomTime());
	sleepTime = round(calcSleepTime());

	mTripTime = mDriveTime + refuelTime + restroomTime + sleepTime;
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

double VehicleTrip::calcDriveTime(double miles, TripLeg::RoadType roadType)
{
	int mph;
	if (roadType == TripLeg::CITY) {
		mph = mParms.getCityMph();
	} else if (roadType == TripLeg::HIGHWAY) {
		mph = mParms.getHighwayMph();
	}
	return (miles / mph) * 60;
}

double VehicleTrip::calcRefuelTime()
{
	return mGStationCnt * mParms.getRefuelTime();
}

double VehicleTrip::calcRestroomTime()
{
	return (mGStationCnt / 2) * mParms.getRestroomTime();
}

double VehicleTrip::calcSleepTime()
{
	int numOfNaps = mDriveTime / mParms.getAwakeTime();

	// Checks to see if arrival is exactly at nap time
	if (numOfNaps != 0 && numOfNaps % mParms.getNapTime() == 0)
		numOfNaps--;

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


