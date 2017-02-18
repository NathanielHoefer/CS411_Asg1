//==============================================================================
// Assignment 1 - WichitaToMonticello
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

    Simulates a trip from Wichita to Monticello with a number of vehicles to
    determine which vehicles take the least/most time, require the least/most
    fuel purchased, and require the least/most consumed.

******************************************************************************/

#include "TripLeg.hpp"
#include "Vehicle.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include "VehicleTrip.hpp"

using namespace std;

// Helper function declarations
vector<Vehicle> initializeVehicles();
vector<TripLeg> initializeTripLegs();
Parameters initializeParms();
double requestInput(double defaultVal);
void printResults(VehicleTrip shortestTime, VehicleTrip longestTime, VehicleTrip leastFuelAdded,
				VehicleTrip mostFuelAdded, VehicleTrip leastFuelUsed, VehicleTrip mostFuelUsed);
void printVehicleStats(VehicleTrip trip);
void tripTesting();

int main()
{
	cout << "Assignment 1" << endl << endl;

	vector<Vehicle> vehicles = initializeVehicles();
	vector<TripLeg> tripLegs = initializeTripLegs();
	Parameters parms = initializeParms();

	VehicleTrip initialTrip(vehicles.at(0), parms);
	initialTrip.runTrip(tripLegs);

	// Initializes records
	VehicleTrip shortestTime = 	initialTrip;
	VehicleTrip longestTime = 	initialTrip;
	VehicleTrip leastFuelAdded = initialTrip;
	VehicleTrip mostFuelAdded = initialTrip;
	VehicleTrip leastFuelUsed = initialTrip;
	VehicleTrip mostFuelUsed = 	initialTrip;

	// Process each vehicle trip
	for (int i = 1; i < (int)vehicles.size(); i++) {
		VehicleTrip trip(vehicles.at(i), parms);
		trip.runTrip(tripLegs);

		// Updates records
		if (trip.getTripTime() < shortestTime.getTripTime())
			shortestTime = trip;
		if (trip.getTripTime() > longestTime.getTripTime())
			longestTime = trip;
		if (trip.getFuelPurchased() < leastFuelAdded.getFuelPurchased())
			leastFuelAdded = trip;
		if (trip.getFuelPurchased() > mostFuelAdded.getFuelPurchased())
			mostFuelAdded = trip;
		if (trip.getFuelConsumed() < leastFuelUsed.getFuelConsumed())
			leastFuelUsed = trip;
		if (trip.getFuelConsumed() > mostFuelUsed.getFuelConsumed())
			mostFuelUsed = trip;
	}

	// Print the formatted results
	printResults(shortestTime, longestTime, leastFuelAdded, mostFuelAdded, leastFuelUsed, mostFuelUsed);
}

// Function used for testing scenarios
void tripTesting()
{
	// Initialization
	Vehicle vehicle("Chevrolet", "Spark", 1.2, 4, 1.7, 8, 14);
	vector<TripLeg> tripLegs;
	tripLegs.push_back(TripLeg(3.3, TripLeg::CITY));
	tripLegs.push_back(TripLeg(23.2, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(14.6, TripLeg::CITY));
	Parameters parms(25, 80, 2.19, 20, 10, 15, 8*60, 10);
	VehicleTrip trip(vehicle, parms);

	trip.runTrip(tripLegs);
}

// Creates the vehicle objects
vector<Vehicle> initializeVehicles()
{
	vector<Vehicle> vehicles;

	vehicles.push_back(Vehicle("Chevrolet", "Spark", 			1.2, 4, 10.5, 	28, 36));
	vehicles.push_back(Vehicle("Chevrolet", "Cruze", 			1.8, 4, 12.5, 	22, 35));
	vehicles.push_back(Vehicle("Chevrolet", "Sonic", 			1.8, 4, 12, 	25, 35));
	vehicles.push_back(Vehicle("Chevrolet", "Camaro",			3.6, 6, 13, 	19, 28));
	vehicles.push_back(Vehicle("Chevrolet", "Suburban C1500", 	5.3, 8, 33, 	13, 18));
	vehicles.push_back(Vehicle("Chevrolet", "Suburban C2500",	6.0, 8, 36, 	10, 15));
	vehicles.push_back(Vehicle("Chrysler", "Town & Country",	3.6, 6, 12.5, 	22, 29));
	vehicles.push_back(Vehicle("Chrysler","300",				5.7, 8, 13.5, 	18, 28));
	vehicles.push_back(Vehicle("Dodge", "Grand Caravan",		3.6, 4, 12.5, 	23, 29));
	vehicles.push_back(Vehicle("Dodge", "Challenger",			5.7, 4, 13, 	16, 25));
	vehicles.push_back(Vehicle("Dodge", "Charger",				5.7, 4, 13, 	17, 26));
	vehicles.push_back(Vehicle("Ford", "Fiesta",				1.6, 4, 9.5, 	29, 39));
	vehicles.push_back(Vehicle("Ford", "Focus",					2.0, 4, 11.5, 	27, 38));
	vehicles.push_back(Vehicle("Ford", "Fusion",				2.0, 4, 12.5, 	22, 33));
	vehicles.push_back(Vehicle("Ford", "Taurus",				3.5, 4, 13, 	19, 29));
	vehicles.push_back(Vehicle("Ford", "Mustang",				5.0, 4, 12, 	18, 25));
	vehicles.push_back(Vehicle("Ford", "E150 Wagon",			5.4, 4, 33.5, 	14, 17));
	vehicles.push_back(Vehicle("Ford", "E350 Wagon",			5.4, 4, 36.5, 	9, 	16));
	vehicles.push_back(Vehicle("Ford", "Expedition 4WD",		5.4, 4, 19, 	13, 19));
	vehicles.push_back(Vehicle("Ford", "F150 Pickup 2WD",		6.2, 4, 25.5, 	15, 20));
	vehicles.push_back(Vehicle("Ford", "F150 Pickup 4WD",		6.2, 4, 23, 	14, 19));
	vehicles.push_back(Vehicle("Honda", "Civic",				1.8, 4, 12, 	28, 39));
	vehicles.push_back(Vehicle("Honda", "Accord",				3.5, 4, 12.5, 	21, 34));
	vehicles.push_back(Vehicle("Hyundai", "Accent",				1.6, 4, 10.5, 	28, 37));
	vehicles.push_back(Vehicle("Hyundai", "Elantra",			1.8, 4, 13, 	28, 38));
	vehicles.push_back(Vehicle("Hyundai", "Sonata",				2.4, 4, 13.5, 	24, 35));
	vehicles.push_back(Vehicle("Mazda", "MAZDA3",				2.0, 4, 11, 	24, 33));
	vehicles.push_back(Vehicle("Mazda", "MAZDA5",				2.5, 4, 11.5, 	22, 28));
	vehicles.push_back(Vehicle("Mazda", "MAZDA6",				3.7, 4, 12, 	18, 27));
	vehicles.push_back(Vehicle("Toyota", "Corolla",				1.8, 4, 12.5, 	26, 34));
	vehicles.push_back(Vehicle("Toyota", "Sienna",				2.7, 4, 13, 	19, 24));
	vehicles.push_back(Vehicle("Toyota", "Camry",				3.5, 4, 13.5, 	21, 31));
	vehicles.push_back(Vehicle("Toyota", "4Runner 4WD",			4.0, 4, 15, 	17, 21));

	return vehicles;
}

// Creates trip leg objects
vector<TripLeg> initializeTripLegs()
{
	vector<TripLeg> tripLegs;

	tripLegs.push_back(TripLeg(3.3, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(23.2, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(0.05, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(0.2, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(56.2, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(50.3, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(6.8, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(53.5, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(21.3, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(229, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(2.8, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(74.7, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(47.3, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(69.3, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(0.2, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(24.3, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(21.2, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(79.2, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(208, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(181.3, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(86.6, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(106.7, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(8.0, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(45.6, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(0.1, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(0.5, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(22.7, 	TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(0.6, 	TripLeg::CITY));
	tripLegs.push_back(TripLeg(1.7, 	TripLeg::CITY));

	return tripLegs;
}

Parameters initializeParms()
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

		// Verifies input with user
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

	Parameters parms(cityMPH, highwayMPH, fuelPrice, refuelTime,
					restroomTime, napTime, awakeTime * 60, gasDistance);
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
	return parms;
}

// Checks if input is valid
double requestInput(double defaultVal)
{
	double value = defaultVal;
	string input = "";

	while (true) {
		getline(cin, input);

		if (input.empty() || input == "\r") {
			return defaultVal;
		}

		// Converts string to value
		stringstream stream(input);
		if (stream >> value)
			return value;
		cout << "Invalid value, please try again" << endl;
	}
}

// Prints the results of the trip
void printResults(VehicleTrip shortestTime, VehicleTrip longestTime,
					VehicleTrip leastFuelAdded, VehicleTrip mostFuelAdded,
					VehicleTrip leastFuelUsed, VehicleTrip mostFuelUsed)
{
	cout << "========================================================" << endl;
	cout << "                      Trip Results                      " << endl;
	cout << "========================================================" << endl;

	cout << setw(14) << "" << "Total miles driven = " << fixed << setprecision(2)
			<< shortestTime.getCityMiles() + shortestTime.getHighwayMiles()
			<< endl;
	cout << setw(10) << "" << fixed << setprecision(2) << left
			<< "City = " << setw(12) << shortestTime.getCityMiles();
	cout << fixed << setprecision(2) << "Highway = "
			<< shortestTime.getHighwayMiles() << endl << endl << endl;

	cout << "========================================================" << endl;
	cout << "   1. Vehicle ariving first at Jefferson's Monticello:  " << endl;
	cout << "========================================================" << endl;
	printVehicleStats(shortestTime);

	cout << "========================================================" << endl;
	cout << "   2. Vehicle arriving last at Jefferson’s Monticello:  " << endl;
	cout << "========================================================" << endl;
	printVehicleStats(longestTime);

	cout << "========================================================" << endl;
	cout << "   3. Vehicle costing the least to reach Jefferson’s    " << endl;
	cout << "        Monticello based on fuel added to tank:         " << endl;
	cout << "========================================================" << endl;
	printVehicleStats(leastFuelAdded);

	cout << "========================================================" << endl;
	cout << "   4. Vehicle costing the most to reach Jefferson’s     " << endl;
	cout << "        Monticello based on fuel added to tank:         " << endl;
	cout << "========================================================" << endl;
	printVehicleStats(mostFuelAdded);

	cout << "========================================================" << endl;
	cout << "   5. Vehicle costing the least to reach Jefferson’s    " << endl;
	cout << "         Monticello based on actual fuel used:          " << endl;
	cout << "========================================================" << endl;
	printVehicleStats(leastFuelUsed);

	cout << "========================================================" << endl;
	cout << "   6. Vehicle costing the most to reach Jefferson’s     " << endl;
	cout << "         Monticello based on actual fuel used:          " << endl;
	cout << "========================================================" << endl;
	printVehicleStats(mostFuelUsed);
}

// Prints the vehicle stats from the trip entered
void printVehicleStats(VehicleTrip trip)
{
	stringstream results;
	results << trip;
	string temp;

	string make, model;
	int cityMPG, highwayMPG, tripTime, gStationCnt;
	double tankSize, currentFuel, fuelPurchased, fuelConsumed;

	// Parses the results from stream
	getline(results, temp, ',');
	make = temp;
	getline(results, temp, ',');
	model = temp;
	getline(results, temp, ',');
	tankSize = atof(temp.c_str());
	getline(results, temp, ',');
	cityMPG = atoi(temp.c_str());
	getline(results, temp, ',');
	highwayMPG = atoi(temp.c_str());
	getline(results, temp, ',');
	currentFuel = atof(temp.c_str());
	getline(results, temp, ',');
	tripTime = atoi(temp.c_str());
	getline(results, temp, ',');
	fuelPurchased = atof(temp.c_str());
	getline(results, temp, ',');
	fuelConsumed = atof(temp.c_str());
	getline(results, temp, ',');
	gStationCnt = atoi(temp.c_str());

	// Calculations for centering title
	int titleLen = make.size() + model.size() + 1;
	int leftTitleSpace = (56 - titleLen) / 2;

	// Calculations for formatted time
	int days, hours, minutes, remainingTime;
	remainingTime = tripTime;
	days = tripTime / (24 * 60);
	remainingTime = tripTime % (24 * 60);
	hours = remainingTime / 60;
	minutes = remainingTime % 60;

	double fuelAddedCost = fuelPurchased * trip.getParms().getFuelPrice();
	double fuelConsumedCost = fuelConsumed * trip.getParms().getFuelPrice();

	// Formats output
	cout << setw(leftTitleSpace) << "";
	cout << make << " " << model		   << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << left << fixed << setprecision(2);
	cout << "Tank Size = " << setw(6) << tankSize;
	cout << "gal   City MPG = " << setw(5) << cityMPG;
	cout << "Highway MPG = " << highwayMPG << endl;;
	cout << "--------------------------------------------------------" << endl;
	cout << "Trip time(minutes) = " << setw(7) << tripTime;
	cout << "Trip time(d.hh:mm) = " << days << "." << setfill('0') << right
			<< setw(2) << hours << ":" << setw(2) << minutes << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << left << setfill(' ');
	cout << "Trip cost based on fuel added = $" << fuelAddedCost << endl;
	cout << "Trip cost based on fuel used  = $" << fuelConsumedCost << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Fuel added = " << setw(8) << setprecision(4) << fuelPurchased
			<< "gal    Fuel remaining = " << tankSize - currentFuel << " gal" << endl;
	cout << "Fuel used  = " << setw(8) << fuelConsumed;
	cout << "gal    Fuel stops     = " << gStationCnt << endl << endl << endl;
}
