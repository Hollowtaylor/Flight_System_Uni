/* Main.cpp

This program is a aircraft flight management system, This is to help the user
manage all flights in the system aswell as to add or remove flights to and from the system.

Author: Ricky Taylor

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include "FlightSystem.h"

bool IsValidNumber(std::string);							   //Declaring Function in advance
bool IsValidAltitude(int);									   //Declaring Function in advance
bool IsValidGroundSpeed(int);								   //Declaring Function in advance
bool IsValidHeading(int);									   //Declaring Function in advance
bool IsValidGridReference(std::string);						   //Declaring Function in advance
bool IsValidAircraftType(std::string);					 	   //Declaring Function in advance
bool IsValidAirline(std::string);						 	   //Declaring Function in advance
bool IsValidFlightNumber(std::string);						   //Declaring Function in advance
void modifyAircraftInfo(FlightSystem &system);				   //Declaring Function in advance
void outputAllAircraft(FlightSystem &system);				   //Declaring Function in advance
void outputCruisingAircraft(FlightSystem &system);			   //Declaring Function in advance
void NewAircraft(FlightSystem &system);						   //Declaring Function in advance
void Direction(int &temp);                                     //Declaring function in advance
void FlightNumberValidation(std::string &flightNumber);		   //Declaring function in advance
void AirlineValidation(std::string &airline);				   //Declaring function in advance
void AircraftTypeValidation(std::string &aircraftType);		   //Declaring function in advance
void GroundSpeedValidation(int &groundSpeed);				   //Declaring function in advance
void AltitudeValidation(int &altitude);						   //Declaring function in advance
void GridReferenceValidation(std::string &gridReference);	   //Declaring function in advance
void HeadingValidation(int &heading);						   //Declaring function in advance
void Menu(FlightSystem &sys);								   //Declaring function in advance
void NumberofAircraft(FlightSystem &sys);

int main() {


	FlightSystem sys;
	sys.AddAircraft( "BA241", "sdfsdf", "sffdsd", 123, 34000, "B5", 324 );
	sys.AddAircraft( "BA231", "sdfsdf", "sffdsd", 123, 34000, "B8", 34 );
	sys.AddAircraft( "BA251", "sdfsdf", "sffdsd", 123, 34000, "B1", 78 );
	sys.AddAircraft( "BA671", "sdfsdf", "sffdsd", 123, 34000, "B7", 123 );
	Menu(sys);
}

/*

This function is the menu for the Aircraft Management System

*/

void Menu(FlightSystem &sys) {

	std::string choice;
	bool valid{ 0 };

	do {           //This is being used to put the UI into a infinite loop until the user chooses to exit the system.


		std::cout << "Welcome To The Aircraft Flight Management System" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "\nWhat System Would You Like To Access:" <<
			"\n1) List of Aircraft" << "\n2) List Cruising Aircraft" << "\n3) Number of Aircraft in Sector" <<
			"\n4) Add An Aircraft" << "\n5) Update Current Aircraft Information" <<
			"\n6) Exit" << std::endl;

		std::getline(std::cin, choice);

		if (choice == "1") {                           //Sends the user to the funtion outputing the list containing all aircraft information in the system
			outputAllAircraft(sys);
		}
		else if (choice == "2") {                      //Sends the user to the funtion outputing the list containing all cruising aircraft information in the system
			outputCruisingAircraft(sys);
		}
		else if (choice == "3") {
			NumberofAircraft(sys);
		}
		else if (choice == "4") {                      //Sends the user to the function for adding new aircraft to the system
			NewAircraft(sys);
		}
		else if (choice == "5") {                      //Sends the user to the function for modifying any aircraft information in the system
			modifyAircraftInfo(sys);
		}
		else if (choice == "6") {                      //Exits the loop and closes system
			std::cout << "\nGood Bye" << std::endl;
			valid = true;
			break;
		}
		else {                                         //Tells user their menu choice was invalid
			std::cout << "\nNumber is Invaild" << std::endl;


		}
	} while (valid != true);
	exit(0);
}
/*

This function is a UI to modify and aircraft information in the system

*/

void modifyAircraftInfo(FlightSystem &sys) {

	std::string modifyChoice;
	std::string flightNumber;
	int heading;
	int altitude;
	bool valid{ 0 };
	std::cout << "What Flight Would You Like To Change?, \n\nEnter Flight Number" << std::endl;     //asking the user which flight they would like to modify
	getline(std::cin, flightNumber);                                                              //recieving input
	std::cout << "\nWhat Would You Like To Modify" << std::endl;                                  //asking the user what aircraft information they would like to modify
	std::cout << "1) Altitude" << "\n2) Heading" << "\n3) Remove Aircraft" << "\n4) Main Menu" << std::endl;
	std::getline(std::cin,modifyChoice);
	do {
		if (modifyChoice == "1") {

			AltitudeValidation(altitude);
			sys.ChangeAltitude(flightNumber, altitude);
		}
		else if (modifyChoice == "2") {

			HeadingValidation(heading);
			sys.ChangeHeading(flightNumber, heading);
		}
		else if (modifyChoice == "3") {

			sys.RemoveAircraft(flightNumber);                                     //Removing the choosen flight from the system
		}
		else if (modifyChoice == "4") {
			system("cls");
			Menu(sys);
		}
		else {
			std::cout << "Choice is Invailed" << std::endl;                       //Telling the user their choice was invalid
			modifyAircraftInfo(sys);
			valid = true;
		}
	} while (valid != true);
	system("pause");
	system("cls");
	Menu(sys);
}

/*

This function outputs a list of all aircraft in the system.

*/

void outputAllAircraft(FlightSystem &sys) {

	std::cout << "Flight#" << std::setw(8) << " " << "Airline" << std::setw(15) << " " << "AircraftType" << std::setw(9) << " " <<
		"GroundSpeed" << std::setw(2) << " " << "Altitude" << std::setw(3) << " " << "GridReference" << std::setw(3) << " " <<
		"Heading" << std::endl;
	std::cout << "__________________________________________________________________________________________________________" << std::endl;
	for (std::vector<int>::size_type i = 0; i != sys.ListAllAircraft().size(); i++) {
		std::cout.width(15); std::cout << std::left << sys.ListAllAircraft()[i].GetFlightNumber();
		std::cout.width(22); std::cout << std::left << sys.ListAllAircraft()[i].GetAirline();
		std::cout.width(21); std::cout << std::left << sys.ListAllAircraft()[i].GetAircraftType();
		std::cout.width(3); std::cout << std::left << sys.ListAllAircraft()[i].GetGroundSpeed();
		std::cout.width(10); std::cout << std::left << " kts";
		std::cout.width(5); std::cout << std::left << sys.ListAllAircraft()[i].GetAltitude();
		std::cout.width(6); std::cout << std::left << " ft";
		std::cout.width(16); std::cout << std::left << sys.ListAllAircraft()[i].GetGridReference() << std::setw(1);
		int temp = sys.ListAllAircraft()[i].GetHeading();
		Direction(temp);
	}
	system("pause");
	system("cls");
	Menu(sys);
}

/*

This function outputs a list of all cruising aircraft above 30k feet in the system

*/

void outputCruisingAircraft(FlightSystem &sys) {
	
	std::cout << "Flight#" << std::setw(8) << " " << "Airline" << std::setw(15) << " " << "AircraftType" << std::setw(9) << " " <<
		"GroundSpeed" << std::setw(2) << " " << "Altitude" << std::setw(3) << " " << "GridReference" << std::setw(3) << " " <<
		"Heading" << std::endl;
	std::cout << "__________________________________________________________________________________________________________" << std::endl;
	for (std::vector<int>::size_type i = 0; i != sys.ListAllCruisingAircraft().size(); i++) {
		std::cout.width(15); std::cout << std::left << sys.ListAllCruisingAircraft()[i].GetFlightNumber();
		std::cout.width(22); std::cout << std::left << sys.ListAllCruisingAircraft()[i].GetAirline();
		std::cout.width(21); std::cout << std::left << sys.ListAllCruisingAircraft()[i].GetAircraftType();
		std::cout.width(3); std::cout << std::left << sys.ListAllCruisingAircraft()[i].GetGroundSpeed();
		std::cout.width(10); std::cout << std::left << " kts";
		std::cout.width(5); std::cout << std::left << sys.ListAllCruisingAircraft()[i].GetAltitude();
		std::cout.width(6); std::cout << std::left << " ft";
		std::cout.width(16); std::cout << std::left << sys.ListAllCruisingAircraft()[i].GetGridReference() << std::setw(1);
		int temp = sys.ListAllCruisingAircraft()[i].GetHeading();
		Direction(temp);
	}
	system("pause");
	system("cls");
	Menu(sys);
}

void NumberofAircraft(FlightSystem &sys) {
	std::cout << "There is: " << sys.numAircraftInSector() << " Aircraft in sector" << std::endl;
	system("pause");
	system("cls");
	Menu(sys);
}

/*

This function is to help the user input a new aircraft and its information into the system.

*/

void NewAircraft(FlightSystem &sys) {
	std::string flightNumber;
	std::string airline;
	std::string aircraftType;
	int groundSpeed{ 0 };
	int altitude{ 0 };
	std::string gridReference;
	int heading{ 0 };
	
	FlightNumberValidation(flightNumber);
	AirlineValidation(airline);
	AircraftTypeValidation(aircraftType);
	GroundSpeedValidation(groundSpeed);
	AltitudeValidation(altitude);
	GridReferenceValidation(gridReference);
	HeadingValidation(heading);


	sys.AddAircraft(flightNumber, airline, aircraftType, groundSpeed, altitude, gridReference, heading);
	system("pause");
	system("cls");
	Menu(sys);
}

/*

This function determines the direction the aircraft is heading in and outputing the correct information.

*/

void Direction(int &temp) {
	

	if (temp >= 350 || temp <= 10) {

		std::cout << "(N) ";

	}
	else if (temp > 10 && temp < 80) {

		std::cout << "(NE) ";
	}
	else if (temp >= 80 && temp <= 100) {

		std::cout << "(E) ";
	}
	else if (temp > 100 && temp < 170) {

		std::cout << "(SE) ";
	}
	else if (temp >= 170 && temp <= 190) {

		std::cout << "(S) ";
	}
	else if (temp > 190 && temp < 260) {

		std::cout << "(SW) ";
	}
	else if (temp >= 260 && temp <= 280) {

		std::cout << "(W) ";
	}
	else if (temp > 280 && temp < 350) {

		std::cout << "(NW) ";
	}
	std::cout << temp << "'" << std::endl;
}

/*

This functioon is used to validate user input

*/

void FlightNumberValidation(std::string &flightNumber) {

	std::string temp;
	bool valid{ 0 };
	do {                                                             //Looping until the input is valid
		std::cout << "\nPlease Enter a FlightNumber" << std::endl;
		std::getline(std::cin, flightNumber);

		if (!(IsValidFlightNumber(flightNumber))) {            //Validating Input
			std::cout << "\nFlightNumber is Invalid" << std::endl;
			valid = false;
		}
		else {
			valid = true;
		}
	} while (valid != true);	
}

/*

This functioon is used to validate user input

*/

void AirlineValidation(std::string &airline)	{

	std::string temp;
	bool valid{ 0 };
	
	do {															 //Looping until the input is valid
		std::cout << "\nPlease Enter Airline" << std::endl;
		std::getline(std::cin, airline);
		
		if (airline.length() > 4 && airline.length() < 20) {
			if ((IsValidAirline(airline))) {	//Validating Input
				valid = true;
			}
			else {
				std::cout << "Airline is Invalid" << std::endl;
				valid = false;
			}
		}
		else {
			std::cout << "Airline is Invalid" << std::endl;
			valid = false;
		}

				
	} while (valid != true || airline.length() < 4 || airline.length() > 20);
}

/*

This functioon is used to validate user input

*/

void AircraftTypeValidation(std::string &aircraftType)	{

	std::string temp;
	bool valid{ 0 };
	
	do {															 //Looping until the input is valid
		std::cout << "\nPlease Enter Aircraft Type" << std::endl;
		std::getline(std::cin, aircraftType);

		if (!(IsValidAircraftType(aircraftType))) {							//Validating Input

			std::cout << "Aircraft Type is Invalid" << std::endl;
			valid = false;
		}
		else {
			valid = true;
		}
	} while (valid != true);
}

/*

This functioon is used to validate user input

*/

void GroundSpeedValidation(int &groundSpeed)	{

	std::string temp;
	bool valid{ 0 };
	
	do {															 //Looping until the input is valid
		std::cout << "\nPlease Enter Ground Speed" << std::endl;
		std::getline(std::cin, temp);
		
		if (IsValidNumber(temp)) {
			groundSpeed = std::stoi(temp);

			if (!(IsValidGroundSpeed(groundSpeed))) {			     //Validating Input
				std::cout << "Speed Is Invalid" << std::endl;
				
				valid = false;
			}
			else {
				
				valid = true;
			}
		}
		else {
			std::cout << "Speed is Invalid" << std::endl;
			valid = false;
		}

	} while (valid != true);
}

/*

This functioon is used to validate user input

*/

void AltitudeValidation(int &altitude)	{

	std::string temp;
	bool valid{ 0 };
	
	do {															 //Looping until the input is valid

		std::cout << "\nPlease Enter Altitude" << std::endl;
		std::getline(std::cin, temp);
		
		if (IsValidNumber(temp)) {
			altitude = std::stoi(temp);

			if (!(IsValidAltitude(altitude))) {                     //Validating Input
				std::cout << "Altitude is Invalid" << std::endl;
				
				valid = false;
			}
			else {
				
				valid = true;
			}
		}
		else {
			std::cout << "Altitude is Invalid" << std::endl;
			valid = false;
		}
	} while (valid != true);
}

/*

This functioon is used to validate user input

*/

void GridReferenceValidation(std::string &gridReference)	{

	std::string temp;
	bool valid{ 0 };
	
	do {															 //Looping until the input is valid

		std::cout << "\nPlease Enter Grid Reference" << std::endl;
		std::getline(std::cin, gridReference);
		

		if (!(IsValidGridReference(gridReference))) {                //Validating Input
			std::cout << "Grid Reference is Invalid" << std::endl;
			valid = false;
		}
		else {
			valid = true;
		}

	} while (valid != true);
}

/*

This functioon is used to validate user input

*/

void HeadingValidation(int &heading)	{

	std::string temp;
	bool valid{ 0 };
	
	do {															 //Looping until the input is valid
		std::cout << "\nPlease Enter Heading" << std::endl;
		std::getline(std::cin, temp);

		if (IsValidNumber(temp)) {
			heading = std::stoi(temp);

			if (!(IsValidHeading(heading))) {                       //Validating Input
				std::cout << "Heading is Invalid" << std::endl;
				valid = false;
			}
			else {
				
				valid = true;
			}
		}
		else {
			std::cout << "Heading is Invalid" << std::endl;
			valid = false;
		}
	} while (valid != true);
}


bool IsValidFlightNumber(std::string flightnumber) {                     //Validation for flightnumber

	const std::regex pattern("[A-Z][A-Z][0-9][0-9]?[0-9]?[0-9]?[0-9]?[A-Z]?$");

	return std::regex_match(flightnumber, pattern);
}
bool IsValidAirline(std::string airline) {                               //Validation for airline

	const std::regex pattern("[A-Za-z]+(\\s)?([A-za-z]+)?$");

	return std::regex_match(airline, pattern);
}
bool IsValidAircraftType(std::string aircraftType) {                     //Validation for aircraft type

	const std::regex pattern("([A-Za-z]+)(\\s)?([A-Za-z0-9]+)?$");

	return std::regex_match(aircraftType, pattern);
}
bool IsValidGridReference(std::string gridReference) {                  //Validation for Grid Reference

	const std::regex pattern("[A-J][0-9|10]$");

	return std::regex_match(gridReference, pattern);
}
bool IsValidAltitude(int altitude) {                                    //Validation for Altitude

	if (altitude <= 0 || altitude >= 60000) {
		return false;
	}
	else {
		return true;
	}

}
bool IsValidGroundSpeed(int groundSpeed) {                              //Validation for Ground Speed

	if (groundSpeed <= 0 || groundSpeed >= 800) {
		return false;
	}
	else {
		return true;
	}

}
bool IsValidHeading(int heading) {                                     //Validation for Heading

	if (heading < 0 || heading > 360) {
		return false;
	}
	else {
		return true;
	}

}
bool IsValidNumber(std::string temp) {                                //Validation to insure input is number before conversion

	const std::regex pattern("[0-9][0-9]?[0-9]?[0-9]?[0-9]?$");

	return std::regex_match(temp, pattern);
}