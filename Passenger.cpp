/**
 * @author		Bowie Sith
 * @file		Passenger.cpp
 * @date		April 2017
 */

#include "Passenger.h"
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

Passenger::Passenger() : priorityValue(0), lastName(""), passengerType('X'), seatingRow(0)
{
}

Passenger::Passenger(std::string inputLine) : priorityValue(0)
{
	std::istringstream ss(inputLine);
	std::string token;
	std::vector<std::string> tokenVector;

	while (std::getline(ss, token, ' '))
	{
		tokenVector.push_back(token);
	}

	lastName = tokenVector[0];
	setPassengerType(tokenVector[1][0]);
	setSeatingRow(std::stoi(tokenVector[2]));
}

Passenger::Passenger(std::string last, char type, int row)
		: lastName(last), priorityValue(0)
{
	setPassengerType(type);
	setSeatingRow(row);
}

std::string Passenger::toString() const
{
	std::ostringstream oss;
	oss << std::setw(13) << lastName
		<< std::setw(5) << passengerType
		<< std::setw(5) << std::to_string(seatingRow)
		<< std::setw(5) << std::to_string(priorityValue);
	return oss.str();
}

void Passenger::setPriorityValue(int p)
{
	priorityValue = p;
}

int Passenger::getPriorityValue()
{
	return priorityValue;
}

void Passenger::setLastName(std::string last)
{
	lastName = last;
}

std::string Passenger::getLastName()
{
	return lastName;
}

void Passenger::setPassengerType(char t) throw(PrecondViolatedExcep)
{
	if (t == 'H' || t == 'E' || t == 'G')
	{
		passengerType = t;
	}
	else
	{
		throw PrecondViolatedExcep("setPassengerType() only takes the values E, H, and G.");
	}
}

char Passenger::getPassengerType()
{
	return passengerType;
}

void Passenger::setSeatingRow(int r) throw(PrecondViolatedExcep)
{
	if (r >= 1 && r <= 26)
	{
		seatingRow = r;
	}
	else
	{
		throw PrecondViolatedExcep("setSeatingRow() only takes values between 1 and 26");
	}
}

int Passenger::getSeatingRow()
{
	return seatingRow;
}

bool Passenger::operator>(Passenger rightHandOperand)
{
	return priorityValue > rightHandOperand.priorityValue;
}

bool Passenger::operator<(Passenger rightHandOperand)
{
	return priorityValue < rightHandOperand.priorityValue;
}
