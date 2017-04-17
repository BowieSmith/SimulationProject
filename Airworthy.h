/**
 * @author		Bowie Sith
 * @file		Airworthy.h
 * @date		April 2017
 *
 * The Airworthy class stores the priority queues used to implement the
 * Airworthy's flight boarding simulations.  The class also contains
 * uitility methods to read passenger data from a file, load the queues,
 * run the simulation, and save the results to a file.
 */

#ifndef AIRWORTHY_H_
#define AIRWORTHY_H_

#include "Heap_PriorityQueue.h"
#include "Passenger.h"
#include <iostream>
#include <fstream>

class Airworthy
{
private:
	// Queue to hold passengers to simulate previous boarding procedure.
	// Passengers will be assigned a priority value between 1 and 7.
	Heap_PriorityQueue<Passenger> previousBoardingProcQueue;

	// Queue to hold passengers to simulate new boarding procedure.
	// Passengers will be assigned a priority value between 1 and 4.
	Heap_PriorityQueue<Passenger> newBoardingProcQueue;

	// Time in seconds required to board plane using old boarding procedure.
	int previousBoardingProcTime;

	// Time in seconds required to board plane using new boarding procedure.
	int newBoardingProcTime;

	// File to write simulation results too.
	std::ofstream outputFile;

	/**
	 * Assigns old boarding priority number to passenger.
	 * In the old boarding procedure there are 7 priority values.
	 * 1 is the lowest priority and 7 is the highest:
	 *
	 * 7: Families with young children or people who need help (Passenger Type = 'H')
	 * 6: First class and/or business class (Seating Row = 1-4)
	 * 5: Elite passengers and passengers in exit rows (Passenger Type = 'E' or Seating Row = 10 or 11)
	 * 4: Passengers in Seating Rows 23-26
	 * 3: Passengers in Seating Rows 17-22
	 * 2: Passengers in Seating Rows 11-16
	 * 1: Passengers in Seating Rows 5-10
	 *
	 * @param Passenger
	 */
	void assignOldPriorityNumber(Passenger& p) const;

	/**
	 * Assigns new boarding priority number to passenger.
	 * In the old boarding procedure there are 4 priority values.
	 * The first three values are the same as the old boarding values, but
	 * general passengers simply board in the order they're standing in line.
	 *
	 * 4: Families with young children or people who need help (Passenger Type = 'H')
	 * 3: First class and/or business class (Seating Row = 1-4)
	 * 2: Elite passengers and passengers in exit rows (Passenger Type = 'E' or Seating Row = 10 or 11)
	 * 1: Everyone else
	 *
	 * @param Passenger
	 */
	void assignNewPriorityNumber(Passenger& p) const;

public:
	/**
	 * Airworthy constructor.  Reads simulation passengers from input file and loads
	 * passengers into priority queues to test the new and old boarding procedures.
	 * @param inputFileName - Contains list of passengers to board plane for simulation.
	 *		Input list inludes passenger last name, passenger type, and seating row number.
	 * @param outputFileName - Name of file of location to store simulation results
	 */
	Airworthy(std::string inputFileName, std::string outputFileName);

	/**
	 * Run simulation.
	 * This method runs the boarding simulation and outputs the results to the
	 * output file defined by the user.
	 */
	void runSimulation();
};

#include "Airworthy.cpp"

#endif