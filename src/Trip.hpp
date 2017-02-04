//==============================================================================
// Assignment 1 - Trip Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#ifndef TRIP_HPP_
#define TRIP_HPP_

#include "TripLeg.hpp"
#include "Vehicle.hpp"
#include "Parameters.hpp"
#include <vector>

using namespace std;


class Trip
{

private:


// MEMBER VARIABLES ============================================================


	Parameters mParms;
	Vehicle mVehicle;
	double mFuelPurchased;
	double mFuelConsumed;
	double mCityMiles;
	double mHighwayMiles;
	int mDriveTime;
	int mTripTime;
	int mGStationCnt;


public:

// CONSTRUCTORS ================================================================


	Trip(Vehicle &vehicle, Parameters &parms);


// ACCESSORS / MUTATORS ========================================================


	Vehicle getVehicle();
	double getFuelPurchased();
	double getFuelConsumed();
	double getCityMiles();
	double getHighwayMiles();
	int getDriveTime();
	int gStationCount();


// MEMBER FUNCTIONS ============================================================


//	Executes the trip cycle to run through every leg of the trip, calculating
// 		total fuel used, time taken, amount spent on gas, and number of miles
//		Preconditions: None
//		Postconditions: Member variables are updated per calculations
	void runTrip(vector<TripLeg> &legs);


//==============================================================================


//	Print the trip details per assignment
//		Preconditions: None
//		Postconditions: None
	void printTripDetails();


//==============================================================================

private:

//	Calculates the drive time within a given set of miles
//		Preconditions: Road type either City or Highway
//		Postconditions: None
//		Returns: The minutes taken to drive the amount of miles
	int calcDriveTime(double miles, TripLeg::RoadType roadType);


//==============================================================================


//	Calculates the time taken to refuel based on # of gas stations
//		Preconditions: Refuel time in minutes
//		Postconditions: None
//		Returns: The minutes taken to refuel during trip
	int calcRefuelTime();


//==============================================================================


//	Calculates the total restroom time on the trip based on the # of gas
//		stations.
//		Preconditions: Restroom time is in minutes
//		Postconditions: None
//		Returns: The minutes taken to use the restroom during the trip
	int calcRestroomTime();


//==============================================================================


//	Calculates the total sleep time on the trip based on the # of gas
//		stations.
//		Preconditions: Sleep time is in minutes
//		Postconditions: None
//		Returns: The minutes taken to use the sleep during the trip
	int calcSleepTime();


//==============================================================================


//	Calculates the total cost of gas on the trip taking into consideration of
// 		fuel added or fuel used
//		Preconditions: None
//		Postconditions: None
//		Returns: The dollar value of gas purchased
	double calcGasCost(bool isFuelAdded);

//==============================================================================


//	Increases the total fuel consumed taking into account the road type
//		Preconditions: Fuel consumed is in gallons
//		Postconditions: Total fuel consumed increased by the miles driven
	void increaseFuelConsumed(double miles, TripLeg::RoadType roadType);


//==============================================================================


//	Increases the total fuel purchased based on the vehicle tank
//		Preconditions: Valid vehicle
//		Postconditions: Total fuel purchased increased by difference in gas tank
	void increaseFuelPurchased();

};


#endif /* TRIP_HPP_ */
