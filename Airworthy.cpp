/**
 * @author		Bowie Smith
 * @file		Airworthy.cpp
 * @date		April 2017
 */

#include <sstream>
#include <iomanip>
#include "Airworthy.h"

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
void assignOldPriorityNumber(Passenger& p)
{
	char passengerType = p.getPassengerType();
	int row = p.getSeatingRow();

	if (passengerType == 'H')
	{
		p.setPriorityValue(7);
	}
	else if (row >= 1 && row <= 4)
	{
		p.setPriorityValue(6);
	}
	else if (passengerType == 'E' || row == 10 || row == 11)
	{
		p.setPriorityValue(5);
	}
	else if (row >= 23 && row <= 26)
	{
		p.setPriorityValue(4);
	}
	else if (row >= 17 && row <= 22)
	{
		p.setPriorityValue(3);
	}
	else if (row >= 11 && row <= 16)
	{
		p.setPriorityValue(2);
	}
	else
	{
		p.setPriorityValue(1);
	}
}

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
void assignNewPriorityNumber(Passenger& p)
{
	char passengerType = p.getPassengerType();
	int row = p.getSeatingRow();

	if (passengerType == 'H')
	{
		p.setPriorityValue(4);
	}
	else if (row >= 1 && row <= 4)
	{
		p.setPriorityValue(3);
	}
	else if (passengerType == 'E' || row == 10 || row == 11)
	{
		p.setPriorityValue(2);
	}
	else
	{
		p.setPriorityValue(1);
	}
}

void Airworthy::generateDataHeader()
{
	std::ostringstream oss;
	oss << std::setw(13) << "Last Name"
		<< std::setw(5) << "Type"
		<< std::setw(5) << "Row#"
		<< "  Priority Value";
	dataHeader = oss.str();
}

void Airworthy::calculateTimeAndGenerateBoardingList(
		Heap_PriorityQueue<Passenger>& pq, int& time)
{
	// Assume first previous passenger is seated in imaginary back seat to
	// avoid special case
	int previousPassengerRow = 27;
	int currentPassengerRow = 0;

	// Remove passengers from priority queue until empty.
	// Record each passenger to simulate boarding the flight.
	// If previous passenger was seated nearer to the front of the plane
	// (with a lesser seat number), increment boarding time by 25 seconds.
	// Otherwise increment boarding time by 1 second.
	while (!pq.isEmpty())
	{
		Passenger currentPassenger = pq.peek();
		outputFile << currentPassenger.toString() << std::endl;

		currentPassengerRow = currentPassenger.getSeatingRow();

		if (previousPassengerRow <= currentPassengerRow)
		{
			time += 25;
		}
		else
		{
			time++;
		}

		previousPassengerRow = currentPassengerRow;
		pq.remove();
	}
}

void Airworthy::loadQueuesAndRecordInputList(std::string inputFileName,
		std::string outputFileName)
{
	try
	{
		outputFile = std::ofstream(outputFileName);
	}
	catch (std::ofstream::failure e)
	{
		std::cerr << "Error opening output file: " << outputFileName
				  << "\n"  << e.what() << std::endl;
	}

	try
	{
		std::ifstream inFile(inputFileName);
	
		outputFile << "---AIRWORTHY BOARDING SIMULATION RESULTS---\n\n"
				   << "The following list contains passengers in the order\n"
				   << "they were listed in the input file: " << inputFileName << "\n\n"
				   << "NOTE: Passengers from the input file have a default\n"
				   << "priority value set to 0 because they are not yet\n"
				   << "part of a boarding procedure.\n\n";
		outputFile << dataHeader << std::endl << std::endl;
			
		std::string line;

		// Iterate through input file line by line.
		// For each line, build and record two Passenger objects.
		// One passenger object will be assigned a priority value according
		// to old procedures, while the other will be assigned a priority
		// value according to the new procedures.
		// Add the passengers to their corresponding priority queues.
		while (inFile.peek() != EOF)
		{
			std::getline(inFile, line);

			Passenger oldBoardingPriorityPassenger(line);
			outputFile << oldBoardingPriorityPassenger.toString() << std::endl;
			assignOldPriorityNumber(oldBoardingPriorityPassenger);
			previousBoardingProcQueue.add(oldBoardingPriorityPassenger);

			Passenger newBoardingPriorityPassenger(line);
			assignNewPriorityNumber(newBoardingPriorityPassenger);
			newBoardingProcQueue.add(newBoardingPriorityPassenger);
		}

		inFile.close();
	}
	catch (PrecondViolatedExcep e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << "Error opening input file: " << inputFileName
				  << "\n"  << e.what() << std::endl;
	}
}

void Airworthy::runSimulation()
{
	outputFile << "\nThe following list contains the passengers in the order they"
			   << "\nboarded the simulated flight using the old boarding procedures.\n\n"
			   << dataHeader << std::endl << std::endl;
	calculateTimeAndGenerateBoardingList(previousBoardingProcQueue, previousBoardingProcTime);

	outputFile << "\n\nThe old boarding procedure took " << std::setprecision(2)
	   		   << std::fixed << (previousBoardingProcTime / 60.0) << " minutes.\n\n";

	outputFile << "\nThe following list contains the passengers in the order they"
			   << "\nboarded the simulated flight using the new boarding procedures.\n\n"
			   << dataHeader << std::endl << std::endl;
	calculateTimeAndGenerateBoardingList(newBoardingProcQueue, newBoardingProcTime);

	outputFile << "\n\nThe new boarding procedure took " << std::setprecision(2)
	   		   << std::fixed << (newBoardingProcTime / 60.0) << " minutes.\n\n";
}

Airworthy::Airworthy(std::string inputFileName, std::string outputFileName)
	: previousBoardingProcTime(0), newBoardingProcTime(0)
{
	generateDataHeader();

	loadQueuesAndRecordInputList(inputFileName, outputFileName);

	runSimulation();

	outputFile.close();
}
