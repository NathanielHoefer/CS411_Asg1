//==============================================================================
// Assignment 1 - Parameters Class
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#include "Parameters.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

//==============================================================================
// CONSTRUCTORS / DESTRUCTORS
//==============================================================================


Parameters::Parameters()
{
	mCityMPH = CITY_MPH;
	mHighwayMPH = HIGHWAY_MPH;
	mFuelPrice = FUEL_PRICE;
	mRefuelTime = REFUEL_TIME;
	mRestroomTime = RESTROOM_TIME;
	mNapTime = NAP_TIME;
	mAwakeTime = AWAKE_TIME;
	mGasDistance = GAS_DISTANCE;
}

Parameters::Parameters(int cityMPH, int highwayMPH, double fuelPrice,
			int refuelTime, int restroomTime, int napTime, int awakeTime,
			double gasDistance)
{
	mCityMPH = cityMPH;
	mHighwayMPH = highwayMPH;
	mFuelPrice = fuelPrice;
	mRefuelTime = refuelTime;
	mRestroomTime = restroomTime;
	mNapTime = napTime;
	mAwakeTime = awakeTime;
	mGasDistance = gasDistance;
}


//==============================================================================
// ACCESSORS / MUTATORS
//==============================================================================


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
double Parameters::getGasDistance() const { return mGasDistance; }
void Parameters::setGasDistance(double gastDistance) {
	mGasDistance = gastDistance;
}


//==============================================================================
// MEMBER FUNCTIONS
//==============================================================================


void Parameters::initializeParms()
{
	int cityMPH, highwayMPH, refuelTime, restroomTime, napTime, awakeTime;
	double fuelPrice, gasDistance;
	string input = "";
	bool isFinished, isApproved;
	isFinished = isApproved = false;

	while (!isFinished) {
		isFinished = isApproved = false;

		cout << "Enter the following parameters: " << endl;

		cout << " - Average speed in the city (MPH) [25]: ";
		cityMPH = (int)requestInput(CITY_MPH);

		cout << " - Average speed on the highway (MPH) [70]: ";
		highwayMPH = (int)requestInput(HIGHWAY_MPH);

		cout << " - Average fuel price per gallon [2.19]: ";
		fuelPrice = requestInput(FUEL_PRICE);

		cout << " - Distance between gas stations (miles) [80.0]: ";
		gasDistance = requestInput(GAS_DISTANCE);

		cout << " - Time required to refuel (minutes) [20]: ";
		refuelTime = (int)requestInput(REFUEL_TIME);

		cout << " - Time required to use the restroom (minutes) [10]: ";
		restroomTime = (int)requestInput(RESTROOM_TIME);

		cout << " - Time required to take a nap (minutes) [15]: ";
		napTime = (int)requestInput(NAP_TIME);

		cout << " - Time before requiring sleep (hours) [8]: ";
		awakeTime = (int)requestInput(AWAKE_TIME);

		cout << "\n--------------------------------------------------------"
				<< endl << endl;

		while (!isApproved) {

			cout << "Are the following parameters correct? (Y/N)" << endl;

			cout << left << setw(13) << "City MPH:" << right
					<< setfill('0') << setw(2) << cityMPH
					<< setfill(' ') << setw(3) << "";
			cout << left << setw(21) << "Refuel Time (min):" << right
					<< setfill('0') << setw(2) << refuelTime
					<< setfill(' ') << setw(3) << "";
			cout << left << setw(18) << "Nap Time (min):" << right
					<< setfill('0') << setw(2) << napTime
					<< setfill(' ') << endl;
			cout << left << setw(13) << "Highway MPH:" << right
					<< setfill('0') << setw(2) << highwayMPH
					<< setfill(' ') << setw(3) << "";
			cout << left << setw(21) << "Restroom Time (min):" << right
					<< setfill('0') << setw(2) << restroomTime
					<< setfill(' ') << setw(3) << "";
			cout << left << setw(18) << "Awake Time (hr):" << right
					<< setfill(' ') << setw(2) << awakeTime
					<< setfill(' ') << endl;
			cout << left << setw(30) << "Gas Station Distance (miles): "
					<< fixed << setprecision(1) << setw(9) << gasDistance
					<< "Fuel Price: $" << setprecision(2) << fuelPrice << endl;


			// TODO Windows will only accept string as "Y\r"
			getline(cin, input);

			if (input == "Y" || input == "y") {
				isFinished = true;
				isApproved = true;
			} else if (input == "N" || input == "n") {
				cout << "--------------------------------------------------------"
						<< endl << endl;
				isApproved = true;
			} else {
				cout << "--------------------------------------------------------"
						<< endl << endl;
			}
		}
	}

	cout << "Input: " << input << endl;

	mCityMPH = cityMPH;
	mHighwayMPH = highwayMPH;
	mFuelPrice = fuelPrice;
	mRefuelTime = refuelTime;
	mRestroomTime = restroomTime;
	mNapTime = napTime;
	mAwakeTime = awakeTime * 60;
	mGasDistance = gasDistance;

	cout << "--------------------------------------------------------" << endl;
	cout << endl;

}


//==============================================================================


double Parameters::requestInput(double defaultVal)
{
	double value = defaultVal;
	string input = "";

	while (true) {
		getline(cin, input);

		if (input.empty() || input == "\r") {
			return defaultVal;
		}

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> value)
			return value;
		cout << "--Invalid value, please try again" << endl;
	}
}
