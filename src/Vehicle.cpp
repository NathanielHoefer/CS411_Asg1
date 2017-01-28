//==============================================================================
// Assignment 1 - Vehicle Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#include "Vehicle.hpp"

using namespace std;


//==============================================================================
// CONSTRUCTORS / DESTRUCTORS
//==============================================================================


Vehicle::Vehicle()
{
	mMake = "Default";
	mModel = "Default";
	mEngine = 0.0;
	mCylinderCnt = 0;
	mTankSize = 0;
	mCityMPG = 0;
	mHighwayMPG = 0;
	mCurrentFuel = 0;
	mRoadType = DEFAULT;
}


//==============================================================================


Vehicle::Vehicle(String make, String model, double engine, int cylinders,
			double tankSize, int cityMPG, int highwayMPG)
{
	mMake = make;
	mModel = model;
	mEngine = engine;
	mCylinderCnt = cylinders;
	mTankSize = tankSize;
	mCityMPG = cityMPG;
	mHighwayMPG = highwayMPG;
	mCurrentFuel = 0;
	mRoadType = DEFAULT;
}


//==============================================================================
// ACCESSORS / MUTATORS
//==============================================================================


String Vehicle::make() 			{ return mMake; }

String Vehicle::engine() 		{ return mEngine; }

int Vehicle::cylinderCount()	{ return mCylinderCnt; }

double Vehicle::tankSize() 		{ return mTankSize; }

int Vehicle::cityMPG() 			{ return mCityMPG; }

int Vehicle::highwayMPG() 		{ return mHighwayMPG; }

double Vehicle::currentFuel() 	{ return mCurrentFuel; }


//==============================================================================
// MEMBER FUNCTIONS
//==============================================================================


double Vehicle::calcFuelConsumed(double miles, RoadType roadType)
{
	//TODO Calculate fuel consumed

}


//==============================================================================


void Vehicle::consumeFuel(double miles, RoadType roadType)
{

	if (mRoadType == CITY) {
		mCurrentFuel -= miles / mCityMPG;
	} else if (mRoadType == HIGHWAY) {
		mCurrentFuel -= miles / mHighwayMPG;
	}

}
