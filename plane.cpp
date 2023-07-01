/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 5 : Airport
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/16/2021
*******************************************************************************/

#include "plane.h"

/***************************************************************************
* CONSTRUCTOR Plane
*___________________________________________________________________________
* This constructor constructs an empty plane
***************************************************************************/
Plane::Plane()
{
    this->operational = true;
}

/***************************************************************************
* MUTATOR setFuel
*___________________________________________________________________________
* This sets the fuel based on the proceedure
***************************************************************************/
void Plane::setFuel() // sets fuel based on operational status
{
    if(this->proceedure) this->remainingFuel = 60;
    else this->remainingFuel = 180;
}

/***************************************************************************
* ACCESSOR printInformation
*___________________________________________________________________________
* Prints the planes information
***************************************************************************/
void Plane::printInformation() const
{
    cout << "Proceedure: ";
    if(this->proceedure) cout << "TAKEOFF" << endl;
    else cout << "LANDING" << endl;

    cout << "Operational: ";
    if(this->operational) cout << "YES" << endl;
    else cout << "NO" << endl;

    cout << "Remaining Fuel: " << this->remainingFuel << " GALLONS" << endl;
}

/***************************************************************************
* FRIEND operator<<
*___________________________________________________________________________
* Overloads the << operator for the airport class.
***************************************************************************/
ostream& operator<<(ostream& os, const Plane& plane)
{
    os << "Proceedure: ";
    if(plane.getProceedure()) os << "TAKEOFF" << endl;
    else os << "LANDING" << endl;

    os << "Operational: ";
    if(plane.getOperational()) cout << "YES" << endl;
    else cout << "NO" << endl;

    os << "Remaining Fuel: " << plane.getRemainingFuel() << " GALLONS" << endl;
    return os;
}
