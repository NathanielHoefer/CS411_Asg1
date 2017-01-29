//==============================================================================
// Assignment 1 - WichitaToMonticello Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#include "WichitaToMonticello.cpp"

using namespace std;


//==============================================================================
// CONSTRUCTORS / DESTRUCTORS
//==============================================================================


WichitaToMonticello::WichitaToMonticello(Parameters parms)
{
	mTripLegs = parms.tripLegs;
	mVehicle = parms.vehicle;
	mRefuelTime = parms.refuelTime;
	mFuelPrice = parms.fuelPrice;
	mRestroomTime = parms.restroomTime;
	mNapTime = parms.napTime;
	mAwakeTime = parms.awakeTime;

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


Vehicle WichitaToMonticello::vehicle() 		{ return mVehicle; }

double WichitaToMonticello::fuelPurchased() { return mFuelPurchased; }

double WichitaToMonticello::fuelConsumed() 	{ return mFuelConsumed; }

double WichitaToMonticello::cityMiles() 	{ return mCityMiles; }

double WichitaToMonticello::highwayMiles()	{ return mHighwayMiles; }

int WichitaToMonticello::travelTime() 		{ return mTravelTime; }

int WichitaToMonticello::gStationCount() 	{ return mGStationCnt; }


//==============================================================================
// MEMBER FUNCTIONS
//==============================================================================


void WichitaToMonticello::runTrip()
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


	// TODO Create all of the calculating functions
