/* FlightSystem.h 

FlightSystem header file declaring a vector to hold objects and
functions to access and modify that information 

Author: Ricky Taylor

*/

#pragma once
#include <string>
#include <vector>
#include "Aircraft.h"

class FlightSystem
{
private:
	std::vector<Aircraft> aircraftList_;   //Declaring vector to hold aircraft objects
public:
	FlightSystem();      //Default Constructor
	void AddAircraft(std::string flightNumber, std::string airline,          //Declaring function to add aircraft objects to vector
		std::string aircraftType, int groundSpeed, int altitude,
		std::string gridReference, int heading);

	std::vector<Aircraft>  ListAllAircraft();                                //Declaring function to list all aircraft in system
	std::vector<Aircraft> ListAllCruisingAircraft();                         //Declaring function to list all crusing aicraft above 30k feet in system

	int numAircraftInSector() const;                                         //Declaring function to return number of aircraft objects in system

	void RemoveAircraft(std::string flightNumber);                           //Declaring function to 

	void ChangeHeading(std::string flightNumber, int heading);               //Declaring function to change heading information in aircraft object
	int GetHeading(std::string flightNumber) const;                          //Declaring function to get heading infromation from aircraft object

	void ChangeAltitude(std::string flightNumber, int altitude);     //Declaring fucntion to change altitude information of aircraft object
	int GetAltitude(std::string flightNumber) const;                         //Delcaring function to get altitude inforation of aircraft object

	void CollisionCheck(std::string flightNumber, int altitude, std::string gridReference);

	~FlightSystem();         //Destructor
};

