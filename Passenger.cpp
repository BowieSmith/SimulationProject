#include "Passenger.h"

Passenger::Passenger(std::string last, char type, int row)
	: lastName(last)
{
	setPassengerType(type);
	setSeatingRow(row);
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
