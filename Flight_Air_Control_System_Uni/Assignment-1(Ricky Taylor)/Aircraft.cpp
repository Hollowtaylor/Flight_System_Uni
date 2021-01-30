/* Aircaft.cpp

This file is the source file for the Aircraft class header file.
It is used to define the functions declared int eh aircraft header

This file manages the aircraft objects inforatiom being used by the system

Author: Ricky Taylor

*/

#include "Aircraft.h"

#include <utility>


Aircraft::Aircraft() = default;

Aircraft::Aircraft(std::string flight_number, std::string airline, std::string aircraft_type,   //custom constructor
                   const int ground_speed, const int altitude, std::string grid_reference, const int heading) 
	: flight_number_(std::move(flight_number)), airline_(std::move(airline)), aircraft_type_(std::move(aircraft_type)), 
	ground_speed_( ground_speed ), altitude_( altitude ), grid_reference_(std::move(grid_reference)),
	heading_( heading ) {
}

void Aircraft::set_flight_number(std::string flight_number) {     //function to set the flight number information
	flight_number_ = std::move(flight_number);
}

std::string Aircraft::get_flight_number() const {               //function to get the flightnumber information
	return flight_number_;
}

void Aircraft::set_airline(std::string airline) {              //function to set the airline information
	airline_ = std::move(airline);
}
 
std::string Aircraft::get_airline() const                      //function to get the airline inforation
{
	return airline_;
}

void Aircraft::set_aircraft_type(std::string aircraft_type) {   //function to set the aircraft type information
	aircraft_type_ = std::move(aircraft_type);
}

std::string Aircraft::get_aircraft_type() const {              //function to get the aircraft information
	return aircraft_type_;
}

void Aircraft::set_ground_speed(const int ground_speed) {             //function to set the ground speed information
	ground_speed_ = ground_speed;
}

int Aircraft::get_ground_speed() const {                       //function to get the ground speed information
	return ground_speed_;
}

void Aircraft::set_altitude(const int altitude) {                   //function to set the altitude information
	altitude_ = altitude;
}

int Aircraft::get_altitude() const {                          //function to get the altitude information
	return altitude_;
}

void Aircraft::set_grid_reference(std::string grid_reference) { //funtion to set the grid reference information
	grid_reference_ = std::move(grid_reference);
}

std::string Aircraft::get_grid_reference() const {             //function to get the grid reference information
	return grid_reference_;
}

void Aircraft::set_heading(const int heading) {                     //function set the heading information
	heading_ = heading;
}

int Aircraft::get_heading() const {                           //function to get the heading information
	return heading_;
}


Aircraft::~Aircraft() = default;  //Destructor
