//==============================================================================
// Assignment 1 - Trip Leg
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#ifndef TRIPLEG_HPP_
#define TRIPLEG_HPP_

class TripLeg
{
public:
	enum RoadType { HIGHWAY, CITY, DEFAULT };

private:
	double mDistance;
	RoadType mRoadType;

public:
	TripLeg();
	TripLeg(double distance, RoadType roadType);

	double getDistance();
	RoadType getRoadType();

};

#endif /* TRIPLEG_HPP_ */
