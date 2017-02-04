//==============================================================================
// Assignment 1 - Trip Leg
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#ifndef TRIPLEG_HPP_
#define TRIPLEG_HPP_


using namespace std;


class TripLeg
{

public:

	enum RoadType { HIGHWAY, CITY, DEFAULT };

private:

// MEMBER VARIABLES ============================================================


	double mDistance;
	RoadType mRoadType;


public:

// CONSTRUCTORS ================================================================


	TripLeg();

	TripLeg(double distance, RoadType roadType);


// ACCESSORS / MUTATORS ========================================================


	double getDistance();
	RoadType getRoadType();

};


#endif /* TRIPLEG_HPP_ */
