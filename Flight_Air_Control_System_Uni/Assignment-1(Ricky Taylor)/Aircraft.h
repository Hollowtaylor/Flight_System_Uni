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
	std::string flightNumber_;
	std::string airline_;
	std::string aircraftType_;
	int groundSpeed_;
	int altitude_;
	std::string gridReference_;
	int heading_;

public:
	Aircraft();      //Declaring Default Constructor

	Aircraft(std::string flightNumber, std::string airline,                   //Declaring Custom Constructor
		std::string aircraftType, int groundSpeed, int altitude,
		std::string gridReference, int heading);


	void SetFlightNumber(std::string flightNumber);                     //Declaring function to set the flight number of aircraft object
	std::string GetFlightNumber() const;                                //Declaring function to get the flight number of aircraft object

	void SetAirline(std::string airline);                               //Declaring function to set the Airline of aircraft object
	std::string GetAirline() const;                                     //Declaring function to get the Airline of aircraft object

	void SetAircraftType(std::string aircraftType);                     //Declaring function to set the Aircraft Type of aircraft object
	std::string GetAircraftType() const;                                //Declaring function to get the Aircraft Type of aircraft object
	 
	void SetGroundSpeed(int groundSpeed);                               //Declaring function to set the Ground Speed of aircraft object
	int GetGroundSpeed() const;                                         //Declaring function to get the Ground Speed of aircraft object

	void SetAltitude(int altitude);                                     //Declaring function to set the Altitude of aircraft object
	int GetAltitude() const;                                            //Declaring function to get the Altitude of aircraft object

	void SetGridReference(std::string gridReference);                   //Declaring function to set the Grid Reference of aircraft object
	std::string GetGridReference() const;                               //Declaring function to get the Grid Reference of aircraft object

	void SetHeading(int heading);                                       //Declaring function to set the Heading of aircraft object
	int GetHeading() const;                                             //Declaring function to get the Heading of aircraft object

	~Aircraft();    //Destructor
};

