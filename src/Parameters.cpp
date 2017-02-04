//==============================================================================
// Assignment 1 - Parameters Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#include "Parameters.hpp"


// CONSTRUCTORS ================================================================


Parameters::Parameters()
{
	mCityMPH = 0;
	mHighwayMPH = 0;
	mFuelPrice = 0;
	mRefuelTime = 0;
	mRestroomTime = 0;
	mNapTime = 0;
	mAwakeTime = 0;
}

Parameters::Parameters(int cityMPH, int highwayMPH, double fuelPrice,
			int refuelTime, int restroomTime, int napTime, int awakeTime)
{
	mCityMPH = cityMPH;
	mHighwayMPH = highwayMPH;
	mFuelPrice = fuelPrice;
	mRefuelTime = refuelTime;
	mRestroomTime = restroomTime;
	mNapTime = napTime;
	mAwakeTime = awakeTime;
}


// ACCESSORS / MUTATORS ========================================================


int Parameters::getAwakeTime() const { return mAwakeTime; }

void Parameters::setAwakeTime(int awakeTime) { mAwakeTime = awakeTime; }

int Parameters::getCityMph() const { return mCityMPH; }

void Parameters::setCityMph(int cityMph) { mCityMPH = cityMph; }

double Parameters::getFuelPrice() const { return mFuelPrice; }

void Parameters::setFuelPrice(double fuelPrice) { mFuelPrice = fuelPrice; }

int Parameters::getHighwayMph() const { return mHighwayMPH; }

void Parameters::setHighwayMph(int highwayMph) { mHighwayMPH = highwayMph; }

int Parameters::getNapTime() const { return mNapTime; }

void Parameters::setNapTime(int napTime) { mNapTime = napTime; }

int Parameters::getRefuelTime() const { return mRefuelTime; }

void Parameters::setRefuelTime(int refuelTime) { mRefuelTime = refuelTime; }

int Parameters::getRestroomTime() const { return mRestroomTime; }

void Parameters::setRestroomTime(int restroomTime) {
	mRestroomTime = restroomTime;
}
