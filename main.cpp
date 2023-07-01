/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 5 : Airport
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/16/2021
*******************************************************************************/

#include "MyQueue.h"
#include "plane.h"
#include "airport.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

/***************************************************************************
* randomNumber
*___________________________________________________________________________
* Returns a random number either 0 and 1
***************************************************************************/
int randomNumber()
{
    srand(time(NULL));
    return rand() % 2;
}

/***************************************************************************
* userInput
*___________________________________________________________________________
* Handles all the user input for the program
***************************************************************************/
void userInput(Airport &myAirport)
{
    unsigned landingTime = 0;
    unsigned takeoffTime = 0;
    unsigned landingDeadTime = 0;
    unsigned takeoffDeadTime = 0;
    unsigned maxWaitTime = 0;
    unsigned simulationTime = 0;
    cout << "Enter landing time in minutes: ";
    cin >> landingTime;
    myAirport.setLandingTime(landingTime);
    cout << "Enter takeoff time in minutes: ";
    cin >> takeoffTime;
    myAirport.setTakeoffTime(takeoffTime);
    cout << "Enter layover time for landings in minutes: ";
    cin >> landingDeadTime;
    myAirport.setLandingDeadTime(landingDeadTime);
    cout << "Enter layover time for takeoffs in minutes: ";
    cin >> takeoffDeadTime;
    myAirport.setTakeoffDeadTime(takeoffDeadTime);
    cout << "Enter the maximum layover time in minutes: ";
    cin >> maxWaitTime;
    myAirport.setMaxWaitTime(maxWaitTime);
    cout << "Enter the simulation time in minutes: ";
    cin >> simulationTime;
    myAirport.setSimulationTime(simulationTime);
}

/***************************************************************************
* main
*___________________________________________________________________________
* Main function for the program
***************************************************************************/
int main()
{
    Airport myAirport;

    Plane planes[100000];
    for(int i = 0; i < 100000; i++)
    {
        planes[i].setProceedure(randomNumber());
        planes[i].setFuel();
        myAirport.addPlaneToQueue(planes[i]);
    }

    userInput(myAirport);

    for(int i = myAirport.getSimulationTime(); i >= 0; i--)
    {
        if(myAirport.getNextPlane().getProceedure())
        {
            myAirport.runSimulation(myAirport.getTakeoffTime());
        }
        else
        {
            myAirport.runSimulation(myAirport.getLandingTime());
        }
    }

    myAirport.printData();
    myAirport.filePrint(myAirport);

    return 0;
}
