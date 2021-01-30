/* Main.cpp

This program is a aircraft flight management system, This is to help the user
manage all flights in the system as well as to add or remove flights to and from the system.

Author: Ricky Taylor

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include "FlightSystem.h"

bool is_valid_number(const std::string&);							   //Declaring Function in advance
bool is_valid_altitude(int);									   //Declaring Function in advance
bool is_valid_ground_speed(int);								   //Declaring Function in advance
bool is_valid_heading(int);									   //Declaring Function in advance
bool is_valid_grid_reference(const std::string&);						   //Declaring Function in advance
bool is_valid_aircraft_type(const std::string&);					 	   //Declaring Function in advance
bool is_valid_airline(const std::string&);						 	   //Declaring Function in advance
bool is_valid_flight_number(const std::string&);						   //Declaring Function in advance
void modify_aircraft_info(flight_system &sys);				   //Declaring Function in advance
void output_all_aircraft(flight_system &sys);				   //Declaring Function in advance
void output_cruising_aircraft(flight_system &sys);			   //Declaring Function in advance
void new_aircraft(flight_system &sys);						   //Declaring Function in advance
void direction(int &temp);                                     //Declaring function in advance
void flight_number_validation(std::string &flight_number);		   //Declaring function in advance
void airline_validation(std::string &airline);				   //Declaring function in advance
void aircraft_type_validation(std::string &aircraft_type);		   //Declaring function in advance
void ground_speed_validation(int &ground_speed);				   //Declaring function in advance
void altitude_validation(int &altitude);						   //Declaring function in advance
void grid_reference_validation(std::string &grid_reference);	   //Declaring function in advance
void heading_validation(int &heading);						   //Declaring function in advance
void menu(flight_system &sys);								   //Declaring function in advance
void number_of_aircraft(flight_system &sys);

int main() {


	flight_system sys;
	sys.add_aircraft( "BA241", "sdfsdf", "sffdsd", 123, 34000, "B5", 324 );
	sys.add_aircraft( "BA231", "sdfsdf", "sffdsd", 123, 34000, "B8", 34 );
	sys.add_aircraft( "BA251", "sdfsdf", "sffdsd", 123, 34000, "B1", 78 );
	sys.add_aircraft( "BA671", "sdfsdf", "sffdsd", 123, 34000, "B7", 123 );
	menu(sys);
}

/*

This function is the menu for the Aircraft Management System

*/

void menu(flight_system &sys) {

	std::string choice;
	bool valid{ false };

	do {           //This is being used to put the UI into a infinite loop until the user chooses to exit the system.


		std::cout << "Welcome To The Aircraft Flight Management System" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "\nWhat System Would You Like To Access:" <<
			"\n1) List of Aircraft" << "\n2) List Cruising Aircraft" << "\n3) Number of Aircraft in Sector" <<
			"\n4) Add An Aircraft" << "\n5) Update Current Aircraft Information" <<
			"\n6) Exit" << std::endl;

		std::getline(std::cin, choice);

		if (choice == "1") {                           //Sends the user to the funtion outputing the list containing all aircraft information in the system
			output_all_aircraft(sys);
		}
		else if (choice == "2") {                      //Sends the user to the funtion outputing the list containing all cruising aircraft information in the system
			output_cruising_aircraft(sys);
		}
		else if (choice == "3") {
			number_of_aircraft(sys);
		}
		else if (choice == "4") {                      //Sends the user to the function for adding new aircraft to the system
			new_aircraft(sys);
		}
		else if (choice == "5") {                      //Sends the user to the function for modifying any aircraft information in the system
			modify_aircraft_info(sys);
		}
		else if (choice == "6") {                      //Exits the loop and closes system
			std::cout << "\nGood Bye" << std::endl;
			valid = true;
			break;
		}
		else {                                         //Tells user their menu choice was invalid
			std::cout << "\nNumber is Invalid" << std::endl;


		}
	} while (valid != true);
	exit(0);
}
/*

This function is a UI to modify and aircraft information in the system

*/

void modify_aircraft_info(flight_system &sys) {

	std::string modify_choice;
	std::string flight_number;
	int heading;
	int altitude;
	auto valid{ false };
	std::cout << "What Flight Would You Like To Change?, \n\nEnter Flight Number" << std::endl;     //asking the user which flight they would like to modify
	getline(std::cin, flight_number);                                                              //recieving input
	std::cout << "\nWhat Would You Like To Modify" << std::endl;                                  //asking the user what aircraft information they would like to modify
	std::cout << "1) Altitude" << "\n2) Heading" << "\n3) Remove Aircraft" << "\n4) Main Menu" << std::endl;
	std::getline(std::cin,modify_choice);
	do {
		if (modify_choice == "1") {

			altitude_validation(altitude);
			sys.change_altitude(flight_number, altitude);
		}
		else if (modify_choice == "2") {

			heading_validation(heading);
			sys.change_heading(flight_number, heading);
		}
		else if (modify_choice == "3") {

			sys.remove_aircraft(flight_number);                                     //Removing the choosen flight from the system
		}
		else if (modify_choice == "4") {
			system("cls");
			menu(sys);
		}
		else {
			std::cout << "Choice is Invalid" << std::endl;                       //Telling the user their choice was invalid
			modify_aircraft_info(sys);
			valid = true;
		}
	} while (valid != true);
	system("pause");
	system("cls");
	menu(sys);
}

/*

This function outputs a list of all aircraft in the system.

*/

void output_all_aircraft(flight_system &sys) {

	std::cout << "Flight#" << std::setw(8) << " " << "Airline" << std::setw(15) << " " << "AircraftType" << std::setw(9) << " " <<
		"GroundSpeed" << std::setw(2) << " " << "Altitude" << std::setw(3) << " " << "GridReference" << std::setw(3) << " " <<
		"Heading" << std::endl;
	std::cout << "__________________________________________________________________________________________________________" << std::endl;
	for (std::vector<int>::size_type i = 0; i != sys.list_all_aircraft().size(); i++) {
		std::cout.width(15); std::cout << std::left << sys.list_all_aircraft()[i].get_flight_number();
		std::cout.width(22); std::cout << std::left << sys.list_all_aircraft()[i].get_airline();
		std::cout.width(21); std::cout << std::left << sys.list_all_aircraft()[i].get_aircraft_type();
		std::cout.width(3); std::cout << std::left << sys.list_all_aircraft()[i].get_ground_speed();
		std::cout.width(10); std::cout << std::left << " kts";
		std::cout.width(5); std::cout << std::left << sys.list_all_aircraft()[i].get_altitude();
		std::cout.width(6); std::cout << std::left << " ft";
		std::cout.width(16); std::cout << std::left << sys.list_all_aircraft()[i].get_grid_reference() << std::setw(1);
		int temp = sys.list_all_aircraft()[i].get_heading();
		direction(temp);
	}
	system("pause");
	system("cls");
	menu(sys);
}

/*

This function outputs a list of all cruising aircraft above 30k feet in the system

*/

void output_cruising_aircraft(flight_system &sys) {
	
	std::cout << "Flight#" << std::setw(8) << " " << "Airline" << std::setw(15) << " " << "AircraftType" << std::setw(9) << " " <<
		"GroundSpeed" << std::setw(2) << " " << "Altitude" << std::setw(3) << " " << "GridReference" << std::setw(3) << " " <<
		"Heading" << std::endl;
	std::cout << "__________________________________________________________________________________________________________" << std::endl;
	for (std::vector<int>::size_type i = 0; i != sys.list_all_cruising_aircraft().size(); i++) {
		std::cout.width(15); std::cout << std::left << sys.list_all_cruising_aircraft()[i].get_flight_number();
		std::cout.width(22); std::cout << std::left << sys.list_all_cruising_aircraft()[i].get_airline();
		std::cout.width(21); std::cout << std::left << sys.list_all_cruising_aircraft()[i].get_aircraft_type();
		std::cout.width(3); std::cout << std::left << sys.list_all_cruising_aircraft()[i].get_ground_speed();
		std::cout.width(10); std::cout << std::left << " kts";
		std::cout.width(5); std::cout << std::left << sys.list_all_cruising_aircraft()[i].get_altitude();
		std::cout.width(6); std::cout << std::left << " ft";
		std::cout.width(16); std::cout << std::left << sys.list_all_cruising_aircraft()[i].get_grid_reference() << std::setw(1);
		int temp = sys.list_all_cruising_aircraft()[i].get_heading();
		direction(temp);
	}
	system("pause");
	system("cls");
	menu(sys);
}

void number_of_aircraft(flight_system &sys) {
	std::cout << "There is: " << sys.num_aircraft_in_sector() << " Aircraft in sector" << std::endl;
	system("pause");
	system("cls");
	menu(sys);
}

/*

This function is to help the user input a new aircraft and its information into the system.

*/

void new_aircraft(flight_system &sys) {
	std::string flight_number;
	std::string airline;
	std::string aircraft_type;
	int ground_speed{ 0 };
	int altitude{ 0 };
	std::string grid_reference;
	int heading{ 0 };
	
	flight_number_validation(flight_number);
	airline_validation(airline);
	aircraft_type_validation(aircraft_type);
	ground_speed_validation(ground_speed);
	altitude_validation(altitude);
	grid_reference_validation(grid_reference);
	heading_validation(heading);


	sys.add_aircraft(flight_number, airline, aircraft_type, ground_speed, altitude, grid_reference, heading);
	system("pause");
	system("cls");
	menu(sys);
}

/*

This function determines the direction the aircraft is heading in and outputing the correct information.

*/

void direction(int &temp) {
	

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

This function is used to validate user input

*/

void flight_number_validation(std::string &flight_number) {

	std::string temp;
	bool valid{ false };
	do {                                                             //Looping until the input is valid
		std::cout << "\nPlease Enter a FlightNumber" << std::endl;
		std::getline(std::cin, flight_number);

		if (!(is_valid_flight_number(flight_number))) {            //Validating Input
			std::cout << "\nFlightNumber is Invalid" << std::endl;
			valid = false;
		}
		else {
			valid = true;
		}
	} while (valid != true);	
}

/*

This function is used to validate user input

*/

void airline_validation(std::string &airline)	{

	std::string temp;
	bool valid{ false };
	
	do {															 //Looping until the input is valid
		std::cout << "\nPlease Enter Airline" << std::endl;
		std::getline(std::cin, airline);
		
		if (airline.length() > 4 && airline.length() < 20) {
			if ((is_valid_airline(airline))) {	//Validating Input
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

This function is used to validate user input

*/

void aircraft_type_validation(std::string &aircraft_type)	{

	std::string temp;
	bool valid{ false };
	
	do {															 //Looping until the input is valid
		std::cout << "\nPlease Enter Aircraft Type" << std::endl;
		std::getline(std::cin, aircraft_type);

		if (!(is_valid_aircraft_type(aircraft_type))) {							//Validating Input

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

void ground_speed_validation(int &ground_speed)	{

	std::string temp;
	bool valid{ false };
	
	do {															 //Looping until the input is valid
		std::cout << "\nPlease Enter Ground Speed" << std::endl;
		std::getline(std::cin, temp);
		
		if (is_valid_number(temp)) {
			ground_speed = std::stoi(temp);

			if (!(is_valid_ground_speed(ground_speed))) {			     //Validating Input
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

void altitude_validation(int &altitude)	{

	std::string temp;
	bool valid{ false };
	
	do {															 //Looping until the input is valid

		std::cout << "\nPlease Enter Altitude" << std::endl;
		std::getline(std::cin, temp);
		
		if (is_valid_number(temp)) {
			altitude = std::stoi(temp);

			if (!(is_valid_altitude(altitude))) {                     //Validating Input
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

void grid_reference_validation(std::string &grid_reference)	{

	std::string temp;
	bool valid{ false };
	
	do {															 //Looping until the input is valid

		std::cout << "\nPlease Enter Grid Reference" << std::endl;
		std::getline(std::cin, grid_reference);
		

		if (!(is_valid_grid_reference(grid_reference))) {                //Validating Input
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

void heading_validation(int &heading)	{

	std::string temp;
	bool valid{ false };
	
	do {															 //Looping until the input is valid
		std::cout << "\nPlease Enter Heading" << std::endl;
		std::getline(std::cin, temp);

		if (is_valid_number(temp)) {
			heading = std::stoi(temp);

			if (!(is_valid_heading(heading))) {                       //Validating Input
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


bool is_valid_flight_number(const std::string& flight_number) {                     //Validation for flight_number

	const std::regex pattern("[A-Z][A-Z][0-9][0-9]?[0-9]?[0-9]?[0-9]?[A-Z]?$");

	return std::regex_match(flight_number, pattern);
}


bool is_valid_airline(const std::string& airline)
{
	//Validation for airline

	const std::regex pattern("[A-Za-z]+(\\s)?([A-za-z]+)?$");

	return std::regex_match(airline, pattern);
}

bool is_valid_aircraft_type(const std::string& aircraft_type) {                     //Validation for aircraft type

	const std::regex pattern("([A-Za-z]+)(\\s)?([A-Za-z0-9]+)?$");

	return std::regex_match(aircraft_type, pattern);
}
bool is_valid_grid_reference(const std::string& grid_reference) {                  //Validation for Grid Reference

	const std::regex pattern("[A-J][0-9|10]$");

	return std::regex_match(grid_reference, pattern);
}
bool is_valid_altitude(const int altitude)
{
	//Validation for Altitude

	return altitude <= 0 || altitude >= 60000 ? false : true;
}

bool is_valid_ground_speed(const int ground_speed)
{
	//Validation for Ground Speed

	return ground_speed <= 0 || ground_speed >= 800 ? false : true;
}

bool is_valid_heading(const int heading)
{
	//Validation for Heading

	return heading < 0 || heading > 360 ? false : true;
}

bool is_valid_number(const std::string& temp) {                                //Validation to insure input is number before conversion

	const std::regex pattern("[0-9][0-9]?[0-9]?[0-9]?[0-9]?$");

	return std::regex_match(temp, pattern);
}
