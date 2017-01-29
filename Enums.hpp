//==============================================================================
// Assignment 1 - Enumerations
//==============================================================================
/*  Author: Nathaniel Hoefer
	Date Created: 12/27/2016
	Last Edited: 12/27/2016
*/
#ifndef SRC_ENUMS_HPP_
#define SRC_ENUMS_HPP_

#include "Vehicle.hpp"
#include "TripLeg.hpp"
#include <vector>


enum RoadType
{
		HIGHWAY,
		CITY,
		DEFAULT
};


struct Parameters
{
	vector<TripLeg> tripLegs;
	Vehicle vehicle;
	int cityMPH;
	int highwayMPH;
	double fuelPrice;
	int refuelTime;
	int restroomTime;
	int napTime;
	int awakeTime;
};


#endif /* SRC_ENUMS_HPP_ */
