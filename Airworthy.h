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
	 * Calculate time for boarding procedure and generate passenger boarding list.
	 * @param Priority Queue for this simulation
	 */
	void calculateTimeAndGenerateBoardingList(Heap_PriorityQueue<Passenger>& pq, int& time);

public:
	/**
	 * Airworthy constructor.  Reads simulation passengers from input file and loads
	 * passengers into both priority queues to test old vs new boarding procedure.
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
