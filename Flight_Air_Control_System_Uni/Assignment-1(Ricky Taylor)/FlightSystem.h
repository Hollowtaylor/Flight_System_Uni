/* FlightSystem.h 

FlightSystem header file declaring a vector to hold objects and
functions to access and modify that information 

Author: Ricky Taylor

*/

#pragma once
#include <string>
#include <vector>
#include "Aircraft.h"

class flight_system
{
private:
	std::vector<Aircraft> aircraftList_;   //Declaring vector to hold aircraft objects
public:
	flight_system();      //Default Constructor
	void add_aircraft(const std::string& flight_number, const std::string& airline,          //Declaring function to add aircraft objects to vector
	                  const std::string& aircraft_type, int ground_speed, int altitude,
	                  const std::string& grid_reference, int heading);

	std::vector<Aircraft>  list_all_aircraft() const;                                //Declaring function to list all aircraft in system
	std::vector<Aircraft> list_all_cruising_aircraft();                         //Declaring function to list all crusing aicraft above 30k feet in system

	int num_aircraft_in_sector() const;                                         //Declaring function to return number of aircraft objects in system

	void remove_aircraft(const std::string& flight_number);                           //Declaring function to 

	void change_heading(const std::string& flight_number, int heading);               //Declaring function to change heading information in aircraft object
	int get_heading(const std::string& flight_number) const;                          //Declaring function to get heading infromation from aircraft object

	void change_altitude(const std::string& flight_number, int altitude);     //Declaring fucntion to change altitude information of aircraft object
	int get_altitude(const std::string& flight_number) const;                         //Delcaring function to get altitude inforation of aircraft object

	void collision_check(const std::string& flight_number, int altitude, const std::string& grid_reference);

	~flight_system();         //Destructor
};

