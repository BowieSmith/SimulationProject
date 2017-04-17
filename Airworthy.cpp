/**
 * @author		Bowie Sith
 * @file		Airworthy.cpp
 * @date		April 2017
 */

void Airworthy::assignOldPriorityNumber(Passenger& p) const
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
	else if (row >= 26 && row <= 23)
	{
		p.setPriorityValue(4);
	}
	else if (row >= 22 && row <= 17)
	{
		p.setPriorityValue(3);
	}
	else if (row >= 16 && row <= 11)
	{
		p.setPriorityValue(2);
	}
	else
	{
		p.setPriorityValue(1);
	}
}

void Airworthy::assignNewPriorityNumber(Passenger& p) const
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

Airworthy::Airworthy(std::string inputFileName, std::string outputFileName)
{
	try
	{
		outputFile = std::ofstream(outputFileName);
		outputFile << "Order of passengers in input file.\n"
				   << "Note: Passengers from input value have a default priority value set to 0\n"
				   << "because they are not part of a boarding procedure.\n\n";

		std::ifstream inFile(inputFileName);
		std::string line;

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
	catch (std::fstream::failure e)
	{
		std::cerr << "Error opening/closing file: " << inputFileName << std::endl;
	}
}

void Airworthy::runSimulation()
{
	outputFile << "\nPassenger boarding order with old boarding procedures:\n\n";
	while (!previousBoardingProcQueue.isEmpty())
	{
		outputFile << previousBoardingProcQueue.peek().toString() << std::endl;
		previousBoardingProcQueue.remove();
	}

	outputFile << "\nPassenger boarding order with new boarding procedures:\n\n";
	while (!newBoardingProcQueue.isEmpty())
	{
		outputFile << newBoardingProcQueue.peek().toString() << std::endl;
		newBoardingProcQueue.remove();
	}
}