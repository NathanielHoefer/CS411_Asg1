//==============================================================================
// Assignment 1 - WichitaToMonticello
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639

******************************************************************************/

#include "Trip.hpp"
#include "TripLeg.hpp"
#include "Vehicle.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

vector<Vehicle> initializeVehicles();
vector<TripLeg> initializeTripLegs();
void tripTesting();


int main()
{
	cout << "Assignment 1" << endl << endl;;

	vector<Vehicle> vehicles = initializeVehicles();
	vector<TripLeg> tripLegs = initializeTripLegs();
	Parameters parms;

	parms.initializeParms();

	cout << parms.getCityMph() << endl;
	cout << parms.getHighwayMph() << endl;
	cout << parms.getFuelPrice() << endl;
	cout << parms.getGasDistance() << endl;
	cout << parms.getRefuelTime() << endl;
	cout << parms.getRestroomTime() << endl;
	cout << parms.getNapTime() << endl;
	cout << parms.getAwakeTime() << endl;

}



//==============================================================================



void tripTesting()
{
	// Initialization
	Vehicle vehicle("Chevrolet", "Spark", 1.2, 4, 1.7, 8, 14);
	vector<TripLeg> tripLegs;
	tripLegs.push_back(TripLeg(3.3, TripLeg::CITY));
	tripLegs.push_back(TripLeg(23.2, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(14.6, TripLeg::CITY));
	Parameters parms(25, 80, 2.19, 20, 10, 15, 8*60, 10);
	Trip trip(vehicle, parms);

	trip.runTrip(tripLegs);

	trip.printTripDetails();
}


////==============================================================================
//
//
//double requestInput(double defaultVal)
//{
//	double value = defaultVal;
//	string input = "";
//
//	while (true) {
//		getline(cin, input);
//
//		if (input == "") {
//			return defaultVal;
//		}
//
//		// This code converts from string to number safely.
//		stringstream myStream(input);
//		if (myStream >> value)
//			return value;
//		cout << "--Invalid value, please try again" << endl;
//	}
//}
//
//
////==============================================================================
//
//
//Parameters initializeParms()
//{
//	int cityMPH, highwayMPH, refuelTime, restroomTime, napTime, awakeTime;
//	double fuelPrice, gasDistance;
//
//	cout << "Enter the following parameters: \n" << endl;
//
//	cout << "Average speed in the city (MPH) [25]: " << endl;
//	cityMPH = (int)requestInput(CITY_MPH);
//
//	cout << "Average speed on the highway (MPH) [70]: " << endl;
//	highwayMPH = (int)requestInput(HIGHWAY_MPH);
//
//	cout << "Average fuel price per gallon [2.19]: " << endl;
//	fuelPrice = requestInput(FUEL_PRICE);
//
//	cout << "Distance between gas stations (miles) [80.0]: " << endl;
//	gasDistance = requestInput(GAS_DISTANCE);
//
//	cout << "Time required to refuel (minutes) [20]: " << endl;
//	refuelTime = (int)requestInput(REFUEL_TIME);
//
//	cout << "Time required to use the restroom (minutes) [10]: " << endl;
//	restroomTime = (int)requestInput(RESTROOM_TIME);
//
//	cout << "Time required to take a nap (minutes) [15]: " << endl;
//	napTime = (int)requestInput(NAP_TIME);
//
//	cout << "Time before requiring sleep (hours) [8]: " << endl;
//	awakeTime = (int)requestInput(AWAKE_TIME) * 60;
//
//	Parameters parms(cityMPH, highwayMPH, fuelPrice, refuelTime, restroomTime,
//					 napTime, awakeTime, gasDistance);
//
//	return parms;
//}


//==============================================================================


vector<Vehicle> initializeVehicles()
{
	vector<Vehicle> vehicles;

	vehicles.push_back(Vehicle("Chevrolet", "Spark",
									1.2, 4, 10.5, 28, 36));
	vehicles.push_back(Vehicle("Chevrolet", "Cruze",
									1.8, 4, 12.5, 22, 35));
	vehicles.push_back(Vehicle("Chevrolet", "Sonic",
									1.8, 4, 12, 25, 35));
	vehicles.push_back(Vehicle("Chevrolet", "Camaro",
									3.6, 6, 13, 13, 18));
	vehicles.push_back(Vehicle("Chevrolet", "Suburban C1500",
									5.3, 8, 33, 13, 18));
	vehicles.push_back(Vehicle("Chevrolet", "Suburban C2500",
									6.0, 8, 36, 10, 15));
	vehicles.push_back(Vehicle("Chrysler", "Town & Country",
									3.6, 6, 12.5, 22, 29));
	vehicles.push_back(Vehicle("Chrysler", "300",
									5.7, 8, 13.5, 18, 28));
	vehicles.push_back(Vehicle("Dodge", "Grand Caravan",
									3.6, 4, 12.5, 23, 29));
	vehicles.push_back(Vehicle("Dodge", "Challenger",
									5.7, 4, 13, 16, 25));
	vehicles.push_back(Vehicle("Dodge", "Charger",
									5.72, 4, 13, 17, 26));
	vehicles.push_back(Vehicle("Ford", "Fiesta",
									1.6, 4, 9.5, 29, 39));
	vehicles.push_back(Vehicle("Ford", "Focus",
									2.0, 4, 11.5, 27, 38));
	vehicles.push_back(Vehicle("Ford", "Fusion",
									2.0, 4, 12.5, 22, 33));
	vehicles.push_back(Vehicle("Ford", "Taurus",
									3.5, 4, 13, 19, 29));
	vehicles.push_back(Vehicle("Ford", "Mustang",
									5.0, 4, 12, 18, 25));
	vehicles.push_back(Vehicle("Ford", "E150 Wagon",
									5.4, 4, 33.5, 14, 17));
	vehicles.push_back(Vehicle("Ford", "E350 Wagon",
									5.4, 4, 36.5, 9, 16));
	vehicles.push_back(Vehicle("Ford", "Expedition 4WD",
									5.4, 4, 19, 13, 19));
	vehicles.push_back(Vehicle("Ford", "F150 Pickup 2WD",
									6.2, 4, 25.5, 15, 20));
	vehicles.push_back(Vehicle("Ford", "F150 Pickup 4WD",
									6.2, 4, 23, 14, 19));
	vehicles.push_back(Vehicle("Honda", "Civic",
									1.8, 4, 12, 28, 39));
	vehicles.push_back(Vehicle("Honda", "Accord",
									3.5, 4, 12.5, 21, 34));
	vehicles.push_back(Vehicle("Hyundai", "Accent",
									1.6, 4, 10.5, 28, 37));
	vehicles.push_back(Vehicle("Hyundai", "Elantra",
									1.8, 4, 13, 28, 38));
	vehicles.push_back(Vehicle("Hyundai", "Sonata",
									2.4, 4, 13.5, 24, 35));
	vehicles.push_back(Vehicle("Mazda", "MAZDA3",
									2.0, 4, 11, 24, 33));
	vehicles.push_back(Vehicle("Mazda", "MAZDA5",
									2.5, 4, 11.5, 22, 28));
	vehicles.push_back(Vehicle("Mazda", "MAZDA6",
									3.7, 4, 12, 18, 27));
	vehicles.push_back(Vehicle("Toyota", "Corolla",
									1.8, 4, 12.5, 26, 34));
	vehicles.push_back(Vehicle("Toyota", "Sienna",
									2.7, 4, 13, 19, 24));
	vehicles.push_back(Vehicle("Toyota", "Camry",
									3.5, 4, 13.5, 21, 31));
	vehicles.push_back(Vehicle("Toyota", "4Runner 4WD",
									4.0, 4, 15, 17, 21));

	return vehicles;
}


//==============================================================================


vector<TripLeg> initializeTripLegs()
{
	vector<TripLeg> tripLegs;

	tripLegs.push_back(TripLeg(3.3, TripLeg::CITY));
	tripLegs.push_back(TripLeg(23.2, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(0.05, TripLeg::CITY));
	tripLegs.push_back(TripLeg(0.2, TripLeg::CITY));
	tripLegs.push_back(TripLeg(56.2, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(50.3, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(6.8, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(53.5, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(21.3, TripLeg::CITY));
	tripLegs.push_back(TripLeg(229, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(2.8, TripLeg::CITY));
	tripLegs.push_back(TripLeg(74.7, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(47.3, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(69.3, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(0.2, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(24.3, TripLeg::CITY));
	tripLegs.push_back(TripLeg(21.2, TripLeg::CITY));
	tripLegs.push_back(TripLeg(79.2, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(208, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(181.3, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(86.6, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(106.7, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(8.0, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(45.6, TripLeg::CITY));
	tripLegs.push_back(TripLeg(0.1, TripLeg::CITY));
	tripLegs.push_back(TripLeg(0.5, TripLeg::CITY));
	tripLegs.push_back(TripLeg(22.7, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(0.6, TripLeg::CITY));
	tripLegs.push_back(TripLeg(1.7, TripLeg::CITY));

	return tripLegs;
}
