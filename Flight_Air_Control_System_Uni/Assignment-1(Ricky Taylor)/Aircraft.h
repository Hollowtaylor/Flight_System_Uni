/* Aircraft.h

Aircraft header file declaring functions to access and 
modify information of any Aircraft objects created.

Author: Ricky Taylor

*/

#pragma once
#include <string>

class Aircraft
{
private:
	std::string flight_number_;
	std::string airline_;
	std::string aircraft_type_;
	int ground_speed_{};
	int altitude_{};
	std::string grid_reference_;
	int heading_{};

public:
	Aircraft();      //Declaring Default Constructor

	Aircraft(std::string flight_number, std::string airline,                   //Declaring Custom Constructor
	         std::string aircraft_type, int ground_speed, int altitude,
	         std::string grid_reference, int heading);


	void set_flight_number(std::string flight_number);                     //Declaring function to set the flight number of aircraft object
	std::string get_flight_number() const;                                //Declaring function to get the flight number of aircraft object

	void set_airline(std::string airline);                               //Declaring function to set the Airline of aircraft object
	std::string get_airline() const;                                     //Declaring function to get the Airline of aircraft object

	void set_aircraft_type(std::string aircraft_type);                     //Declaring function to set the Aircraft Type of aircraft object
	std::string get_aircraft_type() const;                                //Declaring function to get the Aircraft Type of aircraft object
	 
	void set_ground_speed(int ground_speed);                               //Declaring function to set the Ground Speed of aircraft object
	int get_ground_speed() const;                                         //Declaring function to get the Ground Speed of aircraft object

	void set_altitude(int altitude);                                     //Declaring function to set the Altitude of aircraft object
	int get_altitude() const;                                            //Declaring function to get the Altitude of aircraft object

	void set_grid_reference(std::string grid_reference);                   //Declaring function to set the Grid Reference of aircraft object
	std::string get_grid_reference() const;                               //Declaring function to get the Grid Reference of aircraft object

	void set_heading(int heading);                                       //Declaring function to set the Heading of aircraft object
	int get_heading() const;                                             //Declaring function to get the Heading of aircraft object

	~Aircraft();    //Destructor
};

