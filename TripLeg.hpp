//==============================================================================
// Assignment 1 - Trip Leg
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#ifndef TRIPLEG_HPP_
#define TRIPLEG_HPP_

#include "Enums.hpp"

using namespace std;


class TripLeg
{

private:

// MEMBER VARIABLES ============================================================


	double mDistance;
	RoadType mRoadType;


public:

// CONSTRUCTORS ================================================================


	TripLeg();

	TripLeg(double distance, RoadType roadType);


// ACCESSORS / MUTATORS ========================================================


	double distance();
	RoadType roadType();

};


#endif /* TRIPLEG_HPP_ */
