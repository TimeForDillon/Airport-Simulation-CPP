/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 5 : Airport
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/16/2021
*******************************************************************************/

#ifndef AIRPORT_H
#define AIRPORT_H

#include <fstream>
#include "plane.h"
#include "MyQueue.h"

class Airport
{
private:
    MyQueue<Plane> airTraffic;
    unsigned planesInQueue;
    unsigned planesLanding;
    unsigned planesTakingOff;
    unsigned numberOfCrashes;
    unsigned numberOfSuccessfulLandings;
    unsigned numberOfSuccessfulTakeoffs;
    unsigned totalTakeOffTime;
    unsigned totalLandingTime;
    unsigned landingTime;
    unsigned takeoffTime;
    unsigned landingDeadTime;
    unsigned takeoffDeadTime;
    unsigned maxWaitTime;
    unsigned simulationTime;

public:
    /***************************************************************************
    * CONSTRUCTOR Airpot
    *___________________________________________________________________________
    * This constructor constructs an empty airport.
    ***************************************************************************/
    Airport();
    /***************************************************************************
    * MUTATOR addPlaneToQueue
    *___________________________________________________________________________
    * Adds a plane to the queue
    ***************************************************************************/
    void addPlaneToQueue(Plane aPlane);
    /***************************************************************************
    * MUTATOR addPlaneToQueue
    *___________________________________________________________________________
    * Removes a plane to the queue
    ***************************************************************************/
    void removePlaneFromQueue();
    /***************************************************************************
    * MUTATOR setLandingTime
    *___________________________________________________________________________
    * Sets the landing time
    ***************************************************************************/
    void setLandingTime(unsigned landingTime) { this->landingTime = landingTime; };
    /***************************************************************************
    * MUTATOR setLandingTime
    *___________________________________________________________________________
    * Sets the takeoff time
    ***************************************************************************/
    void setTakeoffTime(unsigned takeoffTime) { this->takeoffTime = takeoffTime; };
    /***************************************************************************
    * MUTATOR setLandingDeadTime
    *___________________________________________________________________________
    * Sets the landing layover time
    ***************************************************************************/
    void setLandingDeadTime(unsigned landingDeadTime) { this->landingDeadTime = landingDeadTime; };
    /***************************************************************************
    * MUTATOR setTakeoffDeadTime
    *___________________________________________________________________________
    * Sets the takeoff layover time
    ***************************************************************************/
    void setTakeoffDeadTime(unsigned takeoffDeadTime) { this->takeoffDeadTime = takeoffDeadTime; };
    /***************************************************************************
    * MUTATOR setMaxWaitTime
    *___________________________________________________________________________
    * Sets the max wait time
    ***************************************************************************/
    void setMaxWaitTime(unsigned maxWaitTime) { this->maxWaitTime = maxWaitTime; };
    /***************************************************************************
    * MUTATOR setSimulationTime
    *___________________________________________________________________________
    * Sets the simulation time
    ***************************************************************************/
    void setSimulationTime(unsigned simulationTime) { this->simulationTime = simulationTime; };
    /***************************************************************************
    * MUTATOR runSimulation
    *___________________________________________________________________________
    * Runs the simulation
    ***************************************************************************/
    void runSimulation(unsigned value);
    /***************************************************************************
    * ACCESSOR getSimulationTime
    *___________________________________________________________________________
    * Returns the simulation time
    ***************************************************************************/
    unsigned getSimulationTime() { return this->simulationTime; };
    /***************************************************************************
    * ACCESSOR getTakeoffTime
    *___________________________________________________________________________
    * Returns the takeoff time
    ***************************************************************************/
    unsigned getTakeoffTime() { return this->takeoffTime; };
    /***************************************************************************
    * ACCESSOR getLandingTime
    *___________________________________________________________________________
    * Returns the landing time
    ***************************************************************************/
    unsigned getLandingTime() { return this->landingTime; };
    /***************************************************************************
    * ACCESSOR getTakeoffDeadTime
    *___________________________________________________________________________
    * Returns the takeoff layover time
    ***************************************************************************/
    unsigned getTakeoffDeadTime() { return this->takeoffDeadTime; };
    /***************************************************************************
    * ACCESSOR getLandingDeadTime
    *___________________________________________________________________________
    * Returns the landing layover time
    ***************************************************************************/
    unsigned getLandingDeadTime() { return this->landingDeadTime; };
    /***************************************************************************
    * ACCESSOR getMaxWaitTime
    *___________________________________________________________________________
    * Returns the max wait time
    ***************************************************************************/
    unsigned getMaxWaitTime() { return this->maxWaitTime; };
    /***************************************************************************
    * ACCESSOR getNextPlane
    *___________________________________________________________________________
    * Returns the plane at the top of the queue
    ***************************************************************************/
    Plane getNextPlane() { return airTraffic.top(); };
    /***************************************************************************
    * ACCESSOR printData
    *___________________________________________________________________________
    * Prints the data of the simulation
    ***************************************************************************/
    void printData();
    /***************************************************************************
    * ACCESSOR filePrint
    *___________________________________________________________________________
    * Prints the data of the simulation to a file
    ***************************************************************************/
    void filePrint(const Airport& airport);
    /***************************************************************************
    * FRIEND operator<<
    *___________________________________________________________________________
    * Overloads the << operator for the airport class.
    ***************************************************************************/
    friend ostream& operator<<(ostream& os, const Airport& airport);
};

#endif // AIRPORT_H
