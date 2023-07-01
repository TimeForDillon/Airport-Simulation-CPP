/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 5 : Airport
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/16/2021
*******************************************************************************/

#include "airport.h"

/***************************************************************************
* CONSTRUCTOR Airpot
*___________________________________________________________________________
* This constructor constructs an empty airport.
***************************************************************************/
Airport::Airport()
{
    this->planesInQueue = 0;
    this->planesLanding = 0;
    this->planesTakingOff = 0;
    this->numberOfCrashes = 0;
    this->numberOfSuccessfulLandings = 0;
    this->numberOfSuccessfulTakeoffs = 0;
    this->totalTakeOffTime = 0;
    this->totalLandingTime = 0;
    this->landingTime = 0;
    this->takeoffTime = 0;
    this->landingDeadTime = 0;
    this->takeoffDeadTime = 0;
    this->maxWaitTime = 0;
    this->simulationTime = 0;
}

/***************************************************************************
* MUTATOR addPlaneToQueue
*___________________________________________________________________________
* Adds a plane to the queue
***************************************************************************/
void Airport::addPlaneToQueue(Plane aPlane)
{
    this->airTraffic.enqueue(aPlane);
    if(aPlane.getProceedure()) this->planesTakingOff++;
    else this->planesLanding++;
    this->planesInQueue++;
}

/***************************************************************************
* MUTATOR addPlaneToQueue
*___________________________________________________________________________
* Removes a plane to the queue
***************************************************************************/
void Airport::removePlaneFromQueue()
{
    this->airTraffic.dequeue();
}

/***************************************************************************
* MUTATOR runSimulation
*___________________________________________________________________________
* Runs the simulation
***************************************************************************/
void Airport::runSimulation(unsigned int value)
{
    this->simulationTime -= value;

    if(value == this->landingTime)
    {
        this->totalLandingTime += value;
        this->numberOfSuccessfulLandings++;
        this->simulationTime -= value;
    }
    else
    {
        this->totalTakeOffTime += value;
        this->numberOfSuccessfulTakeoffs++;
        this->simulationTime -= value;
    }
}

/***************************************************************************
* ACCESSOR printData
*___________________________________________________________________________
* Prints the data of the simulation
***************************************************************************/
void Airport::printData()
{
    cout << "SIMULATION TIME: " << this->simulationTime << endl;
    cout << "LANDING TIME: " << this->landingTime << endl;
    cout << "TAKEOFF TIME: " << this->takeoffTime << endl;
    cout << "LANDING LAYOVER TIME: " << this->landingDeadTime << endl;
    cout << "TAKEOFF LAYOVER TIME: " << this->takeoffDeadTime << endl;
    cout << "MAX WAIT TIME: " << this->maxWaitTime << endl << endl;
    cout << "PLANES IN QUEUE: " << this->planesInQueue << endl;
    cout << "PLANES TAKING OFF: " << this->planesTakingOff << endl;
    cout << "PLANES LANDING: " << this->planesLanding << endl;
    cout << "NUMBER OF CRASHES: " << this->numberOfCrashes << endl;
    cout << "NUMBER OF SUCCESSFUL LANDINGS: " << this->numberOfSuccessfulLandings << endl;
    cout << "NUMBER OF SUCCESSFUL TAKEOFF: " << this->numberOfSuccessfulTakeoffs << endl;
    cout << "TOTAL TAKEOFF TIME: " << this->totalTakeOffTime << endl;
    cout << "TOTAL LANDING TIME: " << this->totalLandingTime << endl;
}

/***************************************************************************
* FRIEND operator<<
*___________________________________________________________________________
* Overloads the << operator for the airport class.
***************************************************************************/
ostream& operator<<(ostream& os, const Airport& airport)
{
    os << "SIMULATION TIME: " << airport.simulationTime << endl;
    os << "LANDING TIME: " << airport.landingTime << endl;
    os << "TAKEOFF TIME: " << airport.takeoffTime << endl;
    os << "LANDING LAYOVER TIME: " << airport.landingDeadTime << endl;
    os << "TAKEOFF LAYOVER TIME: " << airport.takeoffDeadTime << endl;
    os << "MAX WAIT TIME: " << airport.maxWaitTime << endl << endl;
    os << "PLANES IN QUEUE: " << airport.planesInQueue << endl;
    os << "PLANES TAKING OFF: " << airport.planesTakingOff << endl;
    os << "PLANES LANDING: " << airport.planesLanding << endl;
    os << "NUMBER OF CRASHES: " << airport.numberOfCrashes << endl;
    os << "NUMBER OF SUCCESSFUL LANDINGS: " << airport.numberOfSuccessfulLandings << endl;
    os << "NUMBER OF SUCCESSFUL TAKEOFF: " << airport.numberOfSuccessfulTakeoffs << endl;
    os << "TOTAL TAKEOFF TIME: " << airport.totalTakeOffTime << endl;
    os << "TOTAL LANDING TIME: " << airport.totalLandingTime << endl;

    return os;
}

/***************************************************************************
* ACCESSOR filePrint
*___________________________________________________________________________
* Prints the data of the simulation to a file
***************************************************************************/
void Airport::filePrint(const Airport& airport)
{
    ofstream myFile("airportData.txt");
    myFile << airport;
    myFile.close();
}
