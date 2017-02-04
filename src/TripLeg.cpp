//==============================================================================
// Assignment 1 - TripLeg Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#include "TripLeg.hpp"

using namespace std;


//==============================================================================
// CONSTRUCTORS / DESTRUCTORS
//==============================================================================


TripLeg::TripLeg()
{
	mDistance = 0;
	mRoadType = DEFAULT;
}


//==============================================================================


TripLeg::TripLeg(double distance, RoadType roadType)
{
	mDistance = distance;
	mRoadType = roadType;
}


//==============================================================================
// ACCESSORS / MUTATORS
//==============================================================================


double TripLeg::getDistance() 				{ return mDistance; }

TripLeg::RoadType TripLeg::getRoadType() 	{ return mRoadType; }
