//==============================================================================
// Assignment 1 - Vehicle Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#ifndef SRC_VEHICLE_HPP_
#define SRC_VEHICLE_HPP_

#include "Enums.hpp"s

using namespace std;

class Vehicle
{

private:

// MEMBER VARIABLES ============================================================

	String mMake;
	String mModel;
	double mEngine;
	int mCylinderCnt;
	double mTankSize;
	int mCityMPG;
	int mHighwayMPG;
	double mCurrentFuel;
	RoadType mRoadType;

public:

// CONSTRUCTORS ================================================================

	Vehicle();

	Vehicle(String make, String model, double engine, int cylinders,
			double tankSize, int cityMPG, int highwayMPG);


// ACCESSORS / MUTATORS ========================================================


	String 	make();
	String 	model();
	double 	engine();
	int 	cylinderCount();
	double 	tankSize();
	int 	cityMPG();
	int 	highwayMPG();
	double 	currentFuel();
	RoadType roadType();

	void setRoadType(RoadType roadType);


// MEMBER FUNCTIONS ============================================================


//	Calculates the amount of fuel consumed after a number of miles
//		Preconditions: Entered miles is greater than 0
//		Postconditions: None
//		Returns: Gallons of fuel consumed after the specified number of miles.
	double calcFuelConsumed(double miles);


//==============================================================================


//	Reduces the current fuel in tank according to the miles travelled
//		Preconditions: Entered miles is greater than 0
//		Postconditions: None
	void consumeFuel(double miles);
};



#endif /* SRC_VEHICLE_HPP_ */
