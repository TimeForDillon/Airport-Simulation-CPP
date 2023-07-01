/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 5 : Airport
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/16/2021
*******************************************************************************/

#ifndef PLANE_H
#define PLANE_H

#include <iostream>

using namespace std;

class Plane
{
private:
    bool proceedure; // true = takeoff, false = landing
    bool operational; // true = operational, false = non-operational (ran out of fuel)
    unsigned remainingFuel; // 60 for landing, 180 for takeoff

public:
    /***************************************************************************
    * CONSTRUCTOR Plane
    *___________________________________________________________________________
    * This constructor constructs an empty plane
    ***************************************************************************/
    Plane();
    /***************************************************************************
    * MUTATOR burnFuel
    *___________________________________________________________________________
    * This burns the fuel in the plane
    ***************************************************************************/
    void burnFuel() { if(this->proceedure) this->remainingFuel--; else this->remainingFuel -= 2; };
    /***************************************************************************
    * MUTATOR setProceedure
    *___________________________________________________________________________
    * This sets the proceedure base on a random input
    ***************************************************************************/
    void setProceedure(int i) { if(i == 0) this->operational = false; else this->operational = true;};
    /***************************************************************************
    * MUTATOR setFuel
    *___________________________________________________________________________
    * This sets the fuel based on the proceedure
    ***************************************************************************/
    void setFuel();
    /***************************************************************************
    * MUTATOR changeOperationalStatus
    *___________________________________________________________________________
    * This sets the fuel based on the proceedure
    ***************************************************************************/
    void changeOperatonalStatus() { this->operational = false; };
    /***************************************************************************
    * ACCESSOR getProceedure
    *___________________________________________________________________________
    * Returns the proceedure status
    ***************************************************************************/
    bool getProceedure() const { return this->proceedure; };
    /***************************************************************************
    * ACCESSOR getOperational
    *___________________________________________________________________________
    * Returns the operational status
    ***************************************************************************/
    bool getOperational() const { return this->operational; };
    /***************************************************************************
    * ACCESSOR getRemainingFuel
    *___________________________________________________________________________
    * Returns the remaining fuel amount
    ***************************************************************************/
    unsigned getRemainingFuel() const { return this->remainingFuel; };
    /***************************************************************************
    * ACCESSOR printInformation
    *___________________________________________________________________________
    * Prints the planes information
    ***************************************************************************/
    void printInformation() const;
    /***************************************************************************
    * FRIEND operator<<
    *___________________________________________________________________________
    * Overloads the << operator for the airport class.
    ***************************************************************************/
    friend ostream& operator<<(ostream& os, const Plane& plane);
};

#endif // PLANE_H
