//==============================================================================
// Assignment 1 - Parameters Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#ifndef PARAMETERS_HPP_
#define PARAMETERS_HPP_


// Constants for all default values
static const int CITY_MPH = 25;
static const int HIGHWAY_MPH = 70;
static const double FUEL_PRICE = 2.19;		// Per gallon
static const double GAS_DISTANCE = 80.0;	// Distance between gas stations
static const int REFUEL_TIME = 20;			// in minutes
static const int RESTROOM_TIME = 10;		// in minutes
static const int NAP_TIME = 15;				// in minutes
static const int AWAKE_TIME = 8;			// in hours


class Parameters
{

private:

// MEMBER VARIABLES ============================================================

	int mCityMPH;
	int mHighwayMPH;
	double mFuelPrice;
	int mRefuelTime;		// in minutes
	int mRestroomTime;		// in minutes
	int mNapTime;			// in minutes
	int mAwakeTime;			// in minutes
	double mGasDistance;	// in miles


public:

// CONSTRUCTORS ================================================================


	Parameters();

	Parameters(int cityMPH, int highwayMPH, double fuelPrice,
				int refuelTime, int restroomTime, int napTime, int awakeTime,
				double gasDistance);


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

	double getGasDistance() const;

	void setGasDistance(double gastDistance);


// MEMBER FUNCTIONS ============================================================


//	Requests input from user to initialize all of the parameters
//		Preconditions: None
//		Postconditions: The member variables are updated
	void initializeParms();


private:

//==============================================================================


//	Requests and validates value entered by user
//		Preconditions: None
//		Postconditions: None
//		Returns: A valid double value
	double requestInput(double defaultVal);
};



#endif /* PARAMETERS_HPP_ */
