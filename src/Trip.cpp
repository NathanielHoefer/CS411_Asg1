//==============================================================================
// Assignment 1 - Trip Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#include "Trip.hpp"

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
	mTravelTime = 0;
	mGStationCnt = 0;
}


//==============================================================================
// ACCESSORS / MUTATORS
//==============================================================================


Vehicle Trip::vehicle() 		{ return mVehicle; }

double Trip::fuelPurchased() 	{ return mFuelPurchased; }

double Trip::fuelConsumed() 	{ return mFuelConsumed; }

double Trip::cityMiles() 		{ return mCityMiles; }

double Trip::highwayMiles()		{ return mHighwayMiles; }

int Trip::travelTime() 			{ return mTravelTime; }

int Trip::gStationCount() 		{ return mGStationCnt; }


//==============================================================================
// MEMBER FUNCTIONS
//==============================================================================


void Trip::runTrip()
{
//	miles travelled = 0
//
//	for every leg {
//		veh.setRoad
//
//		// Sets to remaining miles until gas station
//		legTravelled = <station distance> - milesTravelled % <station distance>
//		veh.tank -= legTravelled / <MPG>
//		nextStationInLeg = true
//
//		while (legTravelled < leg.distance) {
//
//			// Station in next leg?
//			if (legTravelled + <station distance> > leg.distance) {
//				nextStationInLeg = false
//			}
//
//			// Will it make it to the next gas station?
//			gasToNextStation = true
//			if (nextStationInLeg) {
//				if (fuelUsed(<station distance>) > veh.tank) {
//					gasToNextStation = false
//				}
//			} else {
//				// TODO Calculate fuel to next station
//			}
//
//
//			// Stopping at gas station if needed
//			if (!gasToNextStation) {
//				# Fuel purchased
//				veh.tank fill
//				gas station++
//			}
//
//			// Update current local travel and veh.tank
//			if (nextStationInLeg) {
//				legTravelled += <station distance>
//				veh.tank -= <station distance> / <MPG>
//			} else {
//				int remainder = leg.distance - <legTravelled>
//				legTravelled += remainder
//				veh.tank -= remainder / <MPG>
//			}
//		}
//		# Fuel used	(using leg.distance)
//		# Drive time (using leg.distance)
//		# Miles driven (using leg.distance)
//	}
//	# Gas Cost
//	Calc total time {
//		# Refuel time
//		# Restroom time
//		# Sleep time
//		Drive time + Refuel time + restroom time + Sleep time
//	}

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
	double numOfNaps = mTravelTime / mParms.getAwakeTime();

	// Checks to see if arrival is exactly at nap time
	if ((int)numOfNaps % mParms.getNapTime() == 0) {
		numOfNaps--;
	}

	return (int)numOfNaps * mParms.getNapTime();
}


//==============================================================================


double Trip::calcGasCost()
{
	return mFuelPurchased * mParms.getFuelPrice();
}


//==============================================================================


void Trip::increaseFuelConsumed(double miles, TripLeg::RoadType roadType)
{
	double gallons = mVehicle.calcFuelConsumed(miles, roadType);

	mVehicle.consumeFuel(gallons);

	mFuelConsumed += gallons;
}


//==============================================================================


void Trip::increaseFuelPurchased()
{
	mFuelPurchased += mVehicle.getTankSize() - mVehicle.getCurrentFuel();
}
