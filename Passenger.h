/**
 * @author		Bowie Smith
 * @file		Passenger.h
 * @date		April 2017
 *
 * The Passenger class stores passenger information for passengers flying on
 * the Airbus A320-200.  The passenger objects are used to model boarding
 * procedures for Airworthy Airlines.
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "PrecondViolatedExcep.h"
#include <string>

class Passenger
{
private:
	// Priority Value used to determine boarding order
	int priorityValue;

	// Last name of passenger
	std::string lastName;

	// Type of passenger:
	// H: Child or passenger who needs help boarding (e.g. wheelchair)
	// E: Elite passenger (frequent flier)
	// G: General boarding passenger
	char passengerType;

	// Row of seat in plane. Value must be between 1 and 26
	int seatingRow;

public:
	/**
	 * Passenger default constructor.
	 */
	Passenger();
	
	/**
	 * Passenger constructor to build passenger given line from input file.
	 * param inputLine - Input line for passenger simulation
	 */
	Passenger(std::string inputLine);

	/**
	 * Passenger constructor
	 * @param last - Last name
	 * @param type - Type of passenger (H,E,G)
	 * @param row - Row number on flight (1-26)
	 */
	Passenger(std::string last, char type, int row);

	/**
	* Turns passenger object into a string for i/o
	* @return Passenger object as string.
	*/
	std::string toString() const;

	/**
	 * Sets passenger priority value for boarding.
	 * @param p - Priority value
	 */
	void setPriorityValue(int p);

	/**
	 * Retrieves passenger priority value.
	 * @return integer priority value
	 */
	int getPriorityValue();

	/**
	 * Sets passengers last name.
	 * @param last - Last name of passenger.
	 */
	void setLastName(std::string last);

	/**
	 * Retrieves passengers last name.
	 * @return string - last name
	 */
	std::string getLastName();

	/**
	 * Sets type of passenger. Must be H, E, or G.
	 * @param t - Passenger type
	 * @throws PrecondViolatedExcep if not H, E, or G
	 */
	void setPassengerType(char t) throw(PrecondViolatedExcep);

	/**
	 * Retrieves passenger type.
	 * @return char - Passenger type
	 */
	char getPassengerType();

	/**
	 * Assigns a seating row to passenger.  Row must be between 1 and 26.
	 * @param int - Seating row
	 * @throws PrecondViolatedExcep if not between 1 and 26
	 */
	void setSeatingRow(int r) throw(PrecondViolatedExcep);

	/**
	 * Retrieves the seating row of the passenger
	 * @return int - Row number
	 */
	int getSeatingRow();

	/**
	 * Compares passengers using their priority value.  If the passenger
	 * making the function call has a greater priority value than the
	 * other passenger, this will return true.  Otherwise, this will return
	 * false.
	 * @param rightHandOperand - Other passenger
	 * @return bool - True of calling passenger has higher priority value
	 */
	bool operator>(Passenger rightHandOperand);


	/**
	 * Compares passengers using their priority value.  If the passenger
	 * making the function call has a priority value less than the
	 * other passenger, this will return true.  Otherwise, this will return
	 * false.
	 * @param rightHandOperand - Other passenger
	 * @return bool - True of calling passenger has lower priority value
	 */
	bool operator<(Passenger rightHandOperand);
};

#endif
