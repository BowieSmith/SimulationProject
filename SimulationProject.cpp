/**
 * @author		Bowie Smith
 * @file		SimulationProject.cpp
 * @date		April 2017
 *
 * SimulationProject.cpp is the driving class for the Airworthy Airlines
 * flight boarding simulation project.  The main method simply calls a
 * description method to describe the program and the Airworthy constructors
 * to run the simulations and generate output files with results.
 *
 * The Airworthy constructor takes two argument.  The first argument is
 * the input file of Passengers to use for the flight boarding simulation.
 * The second argument is the name used to store the results of the
 * simulation for the given input.  All implementation details are hidden
 * by the constructor.  See the Airworthy class for more information.
 */

#include "Airworthy.h"
#include <string>

int main()
{
	Airworthy airworthySimulation70("airworthy70.txt", "results70.txt");
	Airworthy airworthySimulation85("airworthy85.txt", "results85.txt");
	Airworthy airworthySimulation100("airworthy100.txt", "results100.txt");

	return 0;
}
