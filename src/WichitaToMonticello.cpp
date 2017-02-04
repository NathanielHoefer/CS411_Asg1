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
#include <iostream>
#include <vector>


using namespace std;

vector<Vehicle*> initializeVehicles();
vector<TripLeg*> initializeTripLegs();

int main()
{
	cout << "Initial Submission" << endl;

	vector<Vehicle*> vehicles = initializeVehicles();
	vector<TripLeg*> tripLegs = initializeTripLegs();

	for (int i = 0; i < (int)vehicles.size(); i++) {
		cout << "Car " << i + 1 << ": Model :" <<
				vehicles[i]->getModel() << endl;
	}

	cout << "\n---------------------------\n\n";

	for (int i = 0; i < (int)tripLegs.size(); i++) {
		cout << "Leg " << i + 1 << ": Distance :" <<
				tripLegs[i]->getDistance() << endl;
	}
}


//==============================================================================



vector<Vehicle*> initializeVehicles()
{
	vector<Vehicle*> vehicles;

	vehicles.push_back(new Vehicle("Chevrolet", "Spark",
									1.2, 4, 10.5, 28, 36));
	vehicles.push_back(new Vehicle("Chevrolet", "Cruze",
									1.8, 4, 12.5, 22, 35));
	vehicles.push_back(new Vehicle("Chevrolet", "Sonic",
									1.8, 4, 12, 25, 35));
	vehicles.push_back(new Vehicle("Chevrolet", "Camaro",
									3.6, 6, 13, 13, 18));
	vehicles.push_back(new Vehicle("Chevrolet", "Suburban C1500",
									5.3, 8, 33, 13, 18));
	vehicles.push_back(new Vehicle("Chevrolet", "Suburban C2500",
									6.0, 8, 36, 10, 15));
	vehicles.push_back(new Vehicle("Chrysler", "Town & Country",
									3.6, 6, 12.5, 22, 29));
	vehicles.push_back(new Vehicle("Chrysler", "300",
									5.7, 8, 13.5, 18, 28));
	vehicles.push_back(new Vehicle("Dodge", "Grand Caravan",
									3.6, 4, 12.5, 23, 29));
	vehicles.push_back(new Vehicle("Dodge", "Challenger",
									5.7, 4, 13, 16, 25));
	vehicles.push_back(new Vehicle("Dodge", "Charger",
									5.72, 4, 13, 17, 26));
	vehicles.push_back(new Vehicle("Ford", "Fiesta",
									1.6, 4, 9.5, 29, 39));
	vehicles.push_back(new Vehicle("Ford", "Focus",
									2.0, 4, 11.5, 27, 38));
	vehicles.push_back(new Vehicle("Ford", "Fusion",
									2.0, 4, 12.5, 22, 33));
	vehicles.push_back(new Vehicle("Ford", "Taurus",
									3.5, 4, 13, 19, 29));
	vehicles.push_back(new Vehicle("Ford", "Mustang",
									5.0, 4, 12, 18, 25));
	vehicles.push_back(new Vehicle("Ford", "E150 Wagon",
									5.4, 4, 33.5, 14, 17));
	vehicles.push_back(new Vehicle("Ford", "E350 Wagon",
									5.4, 4, 36.5, 9, 16));
	vehicles.push_back(new Vehicle("Ford", "Expedition 4WD",
									5.4, 4, 19, 13, 19));
	vehicles.push_back(new Vehicle("Ford", "F150 Pickup 2WD",
									6.2, 4, 25.5, 15, 20));
	vehicles.push_back(new Vehicle("Ford", "F150 Pickup 4WD",
									6.2, 4, 23, 14, 19));
	vehicles.push_back(new Vehicle("Honda", "Civic",
									1.8, 4, 12, 28, 39));
	vehicles.push_back(new Vehicle("Honda", "Accord",
									3.5, 4, 12.5, 21, 34));
	vehicles.push_back(new Vehicle("Hyundai", "Accent",
									1.6, 4, 10.5, 28, 37));
	vehicles.push_back(new Vehicle("Hyundai", "Elantra",
									1.8, 4, 13, 28, 38));
	vehicles.push_back(new Vehicle("Hyundai", "Sonata",
									2.4, 4, 13.5, 24, 35));
	vehicles.push_back(new Vehicle("Mazda", "MAZDA3",
									2.0, 4, 11, 24, 33));
	vehicles.push_back(new Vehicle("Mazda", "MAZDA5",
									2.5, 4, 11.5, 22, 28));
	vehicles.push_back(new Vehicle("Mazda", "MAZDA6",
									3.7, 4, 12, 18, 27));
	vehicles.push_back(new Vehicle("Toyota", "Corolla",
									1.8, 4, 12.5, 26, 34));
	vehicles.push_back(new Vehicle("Toyota", "Sienna",
									2.7, 4, 13, 19, 24));
	vehicles.push_back(new Vehicle("Toyota", "Camry",
									3.5, 4, 13.5, 21, 31));
	vehicles.push_back(new Vehicle("Toyota", "4Runner 4WD",
									4.0, 4, 15, 17, 21));

	return vehicles;
}


//==============================================================================


vector<TripLeg*> initializeTripLegs()
{
	vector<TripLeg*> tripLegs;

	tripLegs.push_back(new TripLeg(3.3, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(23.2, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(0.05, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(0.2, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(56.2, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(50.3, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(6.8, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(53.5, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(21.3, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(229, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(2.8, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(74.7, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(47.3, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(69.3, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(0.2, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(24.3, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(21.2, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(79.2, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(208, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(181.3, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(86.6, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(106.7, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(8.0, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(45.6, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(0.1, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(0.5, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(22.7, TripLeg::HIGHWAY));
	tripLegs.push_back(new TripLeg(0.6, TripLeg::CITY));
	tripLegs.push_back(new TripLeg(1.7, TripLeg::CITY));

	return tripLegs;
}
