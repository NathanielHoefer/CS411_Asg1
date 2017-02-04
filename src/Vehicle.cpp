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
}


//==============================================================================


Vehicle::Vehicle(string make, string model, double engine, int cylinders,
			double tankSize, int cityMPG, int highwayMPG)
{
	mMake = make;
	mModel = model;
	mEngine = engine;
	mCylinderCnt = cylinders;
	mTankSize = tankSize;
	mCityMPG = cityMPG;
	mHighwayMPG = highwayMPG;
	mCurrentFuel = tankSize;
}


//==============================================================================
// ACCESSORS / MUTATORS
//==============================================================================


string Vehicle::getMake() 			{ return mMake; }

string Vehicle::getModel()			{ return mModel; }

double Vehicle::getEngine() 		{ return mEngine; }

int Vehicle::getCylinderCount()		{ return mCylinderCnt; }

double Vehicle::getTankSize() 		{ return mTankSize; }

int Vehicle::getCityMPG() 			{ return mCityMPG; }

int Vehicle::getHighwayMPG() 		{ return mHighwayMPG; }

double Vehicle::getCurrentFuel() 	{ return mCurrentFuel; }


//==============================================================================
// MEMBER FUNCTIONS
//==============================================================================


double Vehicle::calcFuelConsumed(double miles, TripLeg::RoadType roadType)
{
	double mpg;

	if (roadType == TripLeg::CITY) {
		mpg = mCityMPG;
	} else if (roadType == TripLeg::HIGHWAY) {
		mpg = mHighwayMPG;
	}

	return miles / mpg;

}


//==============================================================================


void Vehicle::consumeFuel(double gallons)
{
	if (gallons <= mCurrentFuel) {
		mCurrentFuel -= gallons;
	}
}
