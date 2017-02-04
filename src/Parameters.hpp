//==============================================================================
// Assignment 1 - Parameters Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#ifndef PARAMETERS_HPP_
#define PARAMETERS_HPP_

using namespace std;


class Parameters
{

private:

// MEMBER VARIABLES ============================================================

	int mCityMPH;
	int mHighwayMPH;
	double mFuelPrice;
	int mRefuelTime;
	int mRestroomTime;
	int mNapTime;
	int mAwakeTime;


public:

// CONSTRUCTORS ================================================================


	Parameters();

	Parameters(int cityMPH, int highwayMPH, double fuelPrice,
				int refuelTime, int restroomTime, int napTime, int awakeTime);


// ACCESSORS / MUTATORS ========================================================

	int getAwakeTime() const;

	void setAwakeTime(int awakeTime);

	int getCityMph() const;

	void setCityMph(int cityMph);

	double getFuelPrice() const;

	void setFuelPrice(double fuelPrice);

	int getHighwayMph() const;

	void setHighwayMph(int highwayMph);

	int getNapTime() const;

	void setNapTime(int napTime);

	int getRefuelTime() const;

	void setRefuelTime(int refuelTime);

	int getRestroomTime() const;

	void setRestroomTime(int restroomTime);
};



#endif /* PARAMETERS_HPP_ */
