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



FlightSystem::FlightSystem()        //Default Constructor
{
}

/*

Function to add aircraft into the vector

*/

void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, 
		std::string aircraftType, int groundSpeed, int altitude, 
		std::string gridReference, int heading) {

	unsigned int newAltitude = altitude;
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {								//Searches the vector for the flight number entered by user
		if (flightNumber == aircraftList_[i].GetFlightNumber()) {											 //If their is a match informs the user flight is in the system
			std::cout << "Flight " << aircraftList_[i].GetFlightNumber() << " is already in system" << std::endl;
			return;
		}
		
	}                                                          
		Aircraft tempAircraft(flightNumber, airline, aircraftType, groundSpeed, altitude, gridReference, heading);    //if a match is not found inputs the aircraft information in the system
		aircraftList_.push_back(tempAircraft);
		(CollisionCheck(flightNumber, altitude, gridReference));
}

std::vector<Aircraft> FlightSystem::ListAllAircraft() {                   //Function return the private vector information to main.cpp

	
	return aircraftList_;
}

std::vector<Aircraft> FlightSystem::ListAllCruisingAircraft() {          //Function Creating a new temporary vector containing all cruising aircraft above 30k feets information

	std::vector<Aircraft> crusingAircraft_;                              //Declaring temporary vector                 
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {                     //Searching through vector contain all aircraft inforamtion
		if (aircraftList_[i].GetAltitude() >= 30000) {                 //copying any aircraft with an altitude of over 30k feet into new temporary vector
			crusingAircraft_.push_back(aircraftList_.at(i));
		}
	}
	return crusingAircraft_;                                             //returning the new vector to main.
}

int FlightSystem::numAircraftInSector() const {                         //function to return the amount of aircraft currently in the system

	return aircraftList_.size();
}

void FlightSystem::RemoveAircraft(std::string flightNumber) {                      //Function to remove aircraft from the vector

	int count{ 0 };
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {     //Searching through vector contain all aircraft inforamtion
		if ( aircraftList_.at(i).GetFlightNumber() == flightNumber) {  //If the flight is found removing it from system
			int b = i;
			aircraftList_.erase(aircraftList_.begin() + b);
			return;
		}
		else {
			count++;
		}
	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flightNumber << " is not in system" << std::endl;                  //if a flight is not found inputs the aircraft information in the system
	}
}

void FlightSystem::ChangeHeading(std::string flightNumber, int heading) {         //Function to change the heading of an aircraft in system

	int count{ 0 };
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {     //Searching through vector contain all aircraft inforamtion
		if (flightNumber == aircraftList_[i].GetFlightNumber()) {                //If flight is found updating the heading information to the new heading
			aircraftList_.at(i).SetAltitude(heading);
		}
		else {
			count++;
		}
	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flightNumber << " is not in system" << std::endl;                  //if a flight is not found inputs the aircraft information in the system
	}
}

int FlightSystem::GetHeading(std::string flightNumber) const {                     //function to get the heading of a flight currently in the system

	int count{ 0 };
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {      //Searching through vector contain all aircraft inforamtion
		if (flightNumber == aircraftList_[i].GetFlightNumber()) {                  //If flight is found returning the heading information to main.cpp.
			return aircraftList_.at(i).GetHeading();
		}
		else {
			count++;
		}
	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flightNumber << " is not in system" << std::endl;                 //if a flight is not found inputs the aircraft information in the system
	}
}

void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude) {		     //Function to update the altitude of an aircraft in the sytem

	std::string tempgrid;													         //Declaring a temporary string to hold flights grid information
	unsigned int newAltitude = altitude;                                             //Copying the user input into a tempory new int.
	int count{ 0 };

	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {        //Searching through vector contain all aircraft inforamtion
		if (flightNumber == aircraftList_.at(i).GetFlightNumber()) {                    //If flight is found updating the altitude information to the new altitude
			aircraftList_.at(i).SetAltitude(altitude);
			tempgrid = aircraftList_.at(i).GetGridReference();

		}
		else {
			count++;
		}

	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flightNumber << " is not in system" << std::endl;                  //if a flight is not found inputs the aircraft information in the system
	}
	(CollisionCheck(flightNumber, altitude, tempgrid));
}


int FlightSystem::GetAltitude(std::string flightNumber) const {                  //function to get altitude

	int count{ 0 };
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {   //Searching through vector contain all aircraft inforamtion
		if (flightNumber == aircraftList_[i].GetFlightNumber()) {               //If flight is found returning the altitude information to main.cpp
			return aircraftList_.at(i).GetAltitude(); 
		}
		else {
			count++;
		}
	}
	if (count == aircraftList_.size()) {
		std::cout << "Flight " << flightNumber << " is not in system" << std::endl;                 //if a flight is not found inputs the aircraft information in the system
	}
}

void FlightSystem::CollisionCheck(std::string flightNumber, int altitude, std::string gridReference) {
	unsigned int tempAlt = altitude;
	for (std::vector<int>::size_type i = 0; i != aircraftList_.size(); i++) {   //Searching through vector contain all aircraft inforamtion
		unsigned int temp2 = aircraftList_[i].GetAltitude();
		unsigned int dist = 3000;
		if (flightNumber != aircraftList_[i].GetFlightNumber()) {
			if (aircraftList_[i].GetGridReference() == gridReference && (tempAlt - temp2 < dist || temp2 - tempAlt < dist)) {                               //Checking to see there are no flights within the same grid and less than 3000 feet apart
				std::cout << "Warning - Aircraft collison possible between " << flightNumber << " and " << aircraftList_.at(i).GetFlightNumber() << std::endl;   //if there is a match informing the user of a potential collision
			}
		}
	}

}

FlightSystem::~FlightSystem() {               //Destructor
}
