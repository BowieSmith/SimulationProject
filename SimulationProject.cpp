#include "Airworthy.h"
#include "Passenger.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
	Airworthy airworthySimulation70("airworthy70.txt", "simOut.txt");
	airworthySimulation70.runSimulation();

	// std::ofstream outputFile("outputFile.txt");
	// std::ifstream inFile("airworthy70.txt");
	// std::string line;
	// int lineNumber = 1;

	// while (inFile.peek() != EOF)
	// {
	// 	std::getline(inFile, line);
	// 	Passenger tempPassenger(line);
	// 	outputFile << tempPassenger.toString() << std::endl;
	// }

	return 0;
}
