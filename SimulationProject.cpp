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
#include <iostream>

void description()
{
	std::cout << "\nHello!\n\n"
			  << "You just executed a flight boarding simulation for Airworthy Airlines.\n"
			  << "This simulation tests a newly proposed boarding scheme against Airworthy's old\n"
			  << "boarding scheme. Both boarding schemes pre-board families with children\n"
			  << "or people needing assistance, first-class passengers, and frequent fliers.\n"
			  << "However, the old boarding scheme boards general passengers in four tiers,\n"
			  << "whereas the new boarding scheme boards general passengers randomly in a\n"
			  << "first-come-first-serve manner as they get in line to board.\n\n"
			  << "Airworthy was hoping this new boarding scheme would alleviate the overhead\n"
			  << "of the previous boarding plan, and potentially decrease boarding time.\n\n"
			  << "The simulation works by reading a list of passengers in the order they arrive,\n"
			  << "assigning them a priority value based on the two boarding schemes, and\n"
			  << "placing them in a piority queue as they wait to \"board\" the flight.\n"
			  << "Taking passengers out of the priority queue simulates the act of boarding\n"
			  << "the plane. As passengers board, a file records the order in which they board\n"
			  << "and the amount of time it takes to board the plane. The assumption is made\n"
			  << "that an unblocked passenger takes 1 second to board and a blocked passenger\n"
			  << "take 25 seconds to board. A passenger is considered blocked if the previous\n"
			  << "passenger boarding the plane has an assigned seat in the same row or nearer\n"
			  << "to the front of the plane.\n\n"
			  << "To thoroughly test the simulation, three scenarios are run to simulate\n"
			  << "70%, 85%, and 100% capacity.  Each scenario reads from a list of mock\n"
			  << "passengers to build the priority queues, and write the results of the\n"
			  << "simulation to the files: results70.txt, results85.txt, results100.txt\n\n"
			  << "Check out the output files to see how the new boarding scheme worked!\n\n";
}

int main()
{
	description();

	Airworthy airworthySimulation70("airworthy70.txt", "results70.txt");
	Airworthy airworthySimulation85("airworthy85.txt", "results85.txt");
	Airworthy airworthySimulation100("airworthy100.txt", "results100.txt");

	return 0;
}
