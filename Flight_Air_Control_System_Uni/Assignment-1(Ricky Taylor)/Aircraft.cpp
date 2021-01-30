/* Aircaft.cpp

This file is the source file for the Aircraft class header file.
It is used to define the functions declared int eh aircraft header

This file manages the aircraft objects inforatiom being used by the system

Author: Ricky Taylor

*/

#include "Aircraft.h"



Aircraft::Aircraft() {  //default constructor
}

Aircraft::Aircraft(std::string flightNumber, std::string airline, std::string aircraftType,   //custom constructor
	int groundSpeed, int altitude, std::string gridReference, int heading) 
	: flightNumber_( flightNumber ), airline_( airline ), aircraftType_( aircraftType ), 
	groundSpeed_( groundSpeed ), altitude_( altitude ), gridReference_( gridReference ),
	heading_( heading ) {
}

void Aircraft::SetFlightNumber(std::string flightNumber) {     //function to set the flight number information
	flightNumber_ = flightNumber;
}

std::string Aircraft::GetFlightNumber() const {               //function to get the flightnumber information
	return flightNumber_;
}

void Aircraft::SetAirline(std::string airline) {              //function to set the airline information
	airline_ = airline;
}
 
std::string Aircraft::GetAirline() const                      //function to get the airline inforation
{
	return airline_;
}

void Aircraft::SetAircraftType(std::string aircraftType) {   //function to set the aircraft type information
	aircraftType_ = aircraftType;
}

std::string Aircraft::GetAircraftType() const {              //function to get the aircraft information
	return aircraftType_;
}

void Aircraft::SetGroundSpeed(int groundSpeed) {             //function to set the ground speed information
	groundSpeed_ = groundSpeed;
}

int Aircraft::GetGroundSpeed() const {                       //function to get the ground speed information
	return groundSpeed_;
}

void Aircraft::SetAltitude(int altitude) {                   //function to set the altitude information
	altitude_ = altitude;
}

int Aircraft::GetAltitude() const {                          //function to get the altitude information
	return altitude_;
}

void Aircraft::SetGridReference(std::string gridReference) { //funtion to set the grid reference information
	gridReference_ = gridReference;
}

std::string Aircraft::GetGridReference() const {             //function to get the grid reference information
	return gridReference_;
}

void Aircraft::SetHeading(int heading) {                     //function set the heading information
	heading_ = heading;
}

int Aircraft::GetHeading() const {                           //function to get the heading information
	return heading_;
}


Aircraft::~Aircraft() {  //Destructor
}
