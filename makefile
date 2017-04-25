# Makefile for SimulationProject
# Author:		Bowie Smith
# Date:			April 2017


objects = SimulationProject.o Airworthy.o Passenger.o PrecondViolatedExcep.o
CPP = g++
CPPFLAGS = -std=gnu++11

boardingSimulation: $(objects)
	$(CPP) $(CPPFLAGS) -o boardingSimulation $(objects)
Passenger.o: Passenger.cpp Passenger.h
	$(CPP) $(CPPFLAGS) -ggdb -c Passenger.cpp
SimulationProject.o: SimulationProject.cpp Airworthy.h Passenger.h Heap_PriorityQueue.h ArrayMaxHeap.h PrecondViolatedExcep.h
	$(CPP) $(CPPFLAGS) -ggdb -c SimulationProject.cpp
Airworthy.o: Airworthy.cpp Airworthy.h Passenger.h Heap_PriorityQueue.h ArrayMaxHeap.h PrecondViolatedExcep.h
	$(CPP) $(CPPFLAGS) -ggdb -c Airworthy.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	$(CPP) $(CPPFLAGS) -ggdb -c PrecondViolatedExcep.cpp
