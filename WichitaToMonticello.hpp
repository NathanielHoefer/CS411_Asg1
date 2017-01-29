//==============================================================================
// Assignment 1 - WichitaToMonticello Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#ifndef WICHITATOMONTICELLO_HPP_
#define WICHITATOMONTICELLO_HPP_

#include "TripLeg.hpp"
#include "Vehicle.hpp"
#include "Enums.hpp"
#include <vector>

using namespace std;


class WichitaToMonticello
{

private:


// MEMBER VARIABLES ============================================================


	// Parameter Variables
	vector<TripLeg> mTripLegs;
	Vehicle mVehicle;
	double mFuelPrice;
	int mRefuelTime;
	int mRestroomTime;
	int mNapTime;
	int mAwakeTime;

	// Recording Variables
	double mFuelPurchased;
	double mFuelConsumed;
	double mCityMiles;
	double mHighwayMiles;
	int mTravelTime;
	int mGStationCnt;


public:

// CONSTRUCTORS ================================================================


	WichitaToMonticello(Parameters parms);


// ACCESSORS / MUTATORS ========================================================


	Vehicle vehicle();
	double fuelPurchased();
	double fuelConsumed();
	double cityMiles();
	double highwayMiles();
	int travelTime();
	int gStationCount();


// MEMBER FUNCTIONS ============================================================


//	Executes the trip cycle to run through every leg of the trip, calculating
// 		total fuel used, time taken, amount spent on gas, and number of miles
//		Preconditions: None
//		Postconditions: Member variables are updated per calculations
	void runTrip();


//==============================================================================


	// TODO Create all of the calculating functions
};


#endif /* WICHITATOMONTICELLO_HPP_ */
