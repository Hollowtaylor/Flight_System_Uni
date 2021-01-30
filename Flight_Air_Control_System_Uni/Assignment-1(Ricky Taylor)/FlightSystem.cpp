/* FlightSystem.cpp

This is the source file for the FlightSystem Class Header file,
It is used to define the functions declared in the flightsystems header

This file manages the input and output of the vector containing all aircraft information

Author: Ricky Taylor

*/

#include "FlightSystem.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>



flight_system::flight_system() = default;        //Default Constructor

/*

Function to add aircraft into the vector

*/

void flight_system::add_aircraft(const std::string& flight_number, const std::string& airline,
                                const std::string& aircraft_type, const int ground_speed, const int altitude,
                                const std::string& grid_reference, const int heading) {

	unsigned int new_altitude = altitude;
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {								//Searches the vector for the flight number entered by user
		if (flight_number == aircraftList_[i].get_flight_number()) {											 //If their is a match informs the user flight is in the system
			std::cout << "Flight " << aircraftList_[i].get_flight_number() << " is already in system" << std::endl;
			return;
		}
		
	}
	const Aircraft temp_aircraft(flight_number, airline, aircraft_type, ground_speed, altitude, grid_reference, heading);    //if a match is not found inputs the aircraft information in the system
		aircraftList_.push_back(temp_aircraft);
		(collision_check(flight_number, altitude, grid_reference));
}

std::vector<Aircraft> flight_system::list_all_aircraft() const
{                   //Function return the private vector information to main.cpp

	
	return aircraftList_;
}

std::vector<Aircraft> flight_system::list_all_cruising_aircraft() {          //Function Creating a new temporary vector containing all cruising aircraft above 30k feets information

	std::vector<Aircraft> cruising_aircraft;                              //Declaring temporary vector                 
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {                     //Searching through vector contain all aircraft inforamtion
		if (aircraftList_[i].get_altitude() >= 30000) {                 //copying any aircraft with an altitude of over 30k feet into new temporary vector
			cruising_aircraft.push_back(aircraftList_.at(i));
		}
	}
	return cruising_aircraft;                                             //returning the new vector to main.
}

int flight_system::num_aircraft_in_sector() const {                         //function to return the amount of aircraft currently in the system

	return aircraftList_.size();
}

void flight_system::remove_aircraft(const std::string& flight_number) {                      //Function to remove aircraft from the vector

	int count{ 0 };
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {     //Searching through vector contain all aircraft inforamtion
		if ( aircraftList_.at(i).get_flight_number() == flight_number) {  //If the flight is found removing it from system
			const int b = i;
			aircraftList_.erase(aircraftList_.begin() + b);
			return;
		}
		else {
			count++;
		}
	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flight_number << " is not in system" << std::endl;                  //if a flight is not found inputs the aircraft information in the system
	}
}

void flight_system::change_heading(const std::string& flight_number, int heading) {         //Function to change the heading of an aircraft in system

	int count{ 0 };
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {     //Searching through vector contain all aircraft inforamtion
		if (flight_number == aircraftList_[i].get_flight_number()) {                //If flight is found updating the heading information to the new heading
			aircraftList_.at(i).set_altitude(heading);
		}
		else {
			count++;
		}
	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flight_number << " is not in system" << std::endl;                  //if a flight is not found inputs the aircraft information in the system
	}
}

int flight_system::get_heading(const std::string& flight_number) const {                     //function to get the heading of a flight currently in the system

	int count{ 0 };
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {      //Searching through vector contain all aircraft inforamtion
		if (flight_number == aircraftList_[i].get_flight_number()) {                  //If flight is found returning the heading information to main.cpp.
			return aircraftList_.at(i).get_heading();
		}
		else {
			count++;
		}
	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flight_number << " is not in system" << std::endl;                 //if a flight is not found inputs the aircraft information in the system
	}
}

void flight_system::change_altitude(const std::string& flight_number, const int altitude) {		     //Function to update the altitude of an aircraft in the sytem

	std::string temp_grid;													         //Declaring a temporary string to hold flights grid information
	unsigned int new_altitude = altitude;                                             //Copying the user input into a tempory new int.
	int count{ 0 };

	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {        //Searching through vector contain all aircraft inforamtion
		if (flight_number == aircraftList_.at(i).get_flight_number()) {                    //If flight is found updating the altitude information to the new altitude
			aircraftList_.at(i).set_altitude(altitude);
			temp_grid = aircraftList_.at(i).get_grid_reference();

		}
		else {
			count++;
		}

	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flight_number << " is not in system" << std::endl;                  //if a flight is not found inputs the aircraft information in the system
	}
	(collision_check(flight_number, altitude, temp_grid));
}


int flight_system::get_altitude(const std::string& flight_number) const {                  //function to get altitude

	int count{ 0 };
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++)
	{
		//Searching through vector contain all aircraft inforamtion
		if (flight_number == aircraftList_[i].get_flight_number()) {               //If flight is found returning the altitude information to main.cpp
			return aircraftList_.at(i).get_altitude(); 
		}
		count++;
	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flight_number << " is not in system" << std::endl;                 //if a flight is not found inputs the aircraft information in the system
	}

	return 0;
}

void flight_system::collision_check(const std::string& flight_number, const int altitude, const std::string& grid_reference) {
	const unsigned int temp_alt = altitude;
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {   //Searching through vector contain all aircraft inforamtion
		const unsigned int temp2 = aircraftList_[i].get_altitude();
		const unsigned int dist = 3000;
		if (flight_number != aircraftList_[i].get_flight_number()) {
			if (aircraftList_[i].get_grid_reference() == grid_reference && (temp_alt - temp2 < dist || temp2 - temp_alt < dist)) {                               //Checking to see there are no flights within the same grid and less than 3000 feet apart
				std::cout << "Warning - Aircraft collision possible between " << flight_number << " and " << aircraftList_.at(i).get_flight_number() << std::endl;   //if there is a match informing the user of a potential collision
			}
		}
	}

}

flight_system::~flight_system() = default;
