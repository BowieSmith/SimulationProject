#include <iostream>
#include "Passenger.h"

void displayPassenger(Passenger& p)
{
	std::cout << "\nLast Name: " << p.getLastName()
			  << "\nPassenger Type: " << p.getPassengerType()
			  << "\nSeating Row: " << p.getSeatingRow()
			  << "\nPriority Value: " << p.getPriorityValue()
			  << std::endl;
}

int main()
{
	Passenger p1("Sitter",'E',21);
	Passenger p2("Smiter",'H',5);

	p1.setPriorityValue(4);
	p2.setPriorityValue(3);

	displayPassenger(p1);
	displayPassenger(p2);

	return 0;
}
