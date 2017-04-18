#include "Airworthy.h"
#include "Passenger.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
	Airworthy airworthySimulation70("airworthy70.txt", "results70.txt");
	Airworthy airworthySimulation85("airworthy85.txt", "results85.txt");
	Airworthy airworthySimulation100("airworthy100.txt", "results100.txt");

	airworthySimulation70.runSimulation();
	airworthySimulation85.runSimulation();
	airworthySimulation100.runSimulation();

	return 0;
}
