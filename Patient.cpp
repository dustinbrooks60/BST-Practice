/* Filename: Patient.cpp
   Class description: Models the patient of a walk-in clinic.
   Class invariant: The name of a patient is a valid string (non-empty)
   that starts with an alphabetical letter (a or A to z or Z). The name of the patient, 
   along with the care card number, uniquely identifies her/him.
   Date of creation: May 23rd, 2017
   Author: Dustin Brooks
*/


#include <iostream>
#include <string>
#include <locale>
#include "Patient.h"

using namespace std;

// Default Constructor
// Description:   Create a blank patient member
// Postcondition: name set to "To be entered", address set to "To be entered", phone set to 
//                "To be entered", email set to "To be entered", and care card is set to 
//                "0000000000".
Patient::Patient() {

    name = "To be entered";
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";
    careCard = "0000000000";
}

// Constructor
// Description:   Create a patient with a specific care card number
// Postcondition: name set to "To be entered", address set to "To be entered", phone set to 
//                "To be entered", email set to "To be entered", and care card is set to 
//                aCareCard.
Patient::Patient(string aCareCard) {

   name = "To be entered";
   address = "To be entered";
   phone = "To be entered";
   email = "To be entered";
   careCard = aCareCard;
}


// Getters and setters
// Description: Returns a patient's name.
string Patient::getName() const {

  return name;
}

// Description: Returns a patient's address.
string Patient::getAddress() const {

  return address;
}

// Description: Returns a patient's phone number.
string Patient::getPhone() const {

  return phone;
}

// Description: Returns a patient's email.
string Patient::getEmail() const {

  return email;
}

// Description: Returns a patient's care card number.
string Patient::getCareCard() const {

  return careCard;
}


// Description:   Sets the patient's name.
// Precondition:  aName must be a valid string (non-empty) and starts with an alphabetical 
//                letter.
// Postcondition: Patient's name is set to aName if it is valid, otherwise name is unchanged.
void Patient::setName(const string aName) {

   locale loc;

   if (!aName.empty() && (isalpha(aName[0], loc)) ) {

     name = aName; }

   else {

     name = "Patient: To be entered"; }
}

// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress) {

   address = anAddress;
}

// Description: Sets the patient's phone number.
void Patient::setPhone(const string aPhone) {

   phone = aPhone;
}

// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail) {

   email = anEmail;
}



// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number and false 
//              otherwise.
bool Patient::operator==(const Patient & rhs) {

  if (careCard == rhs.getCareCard() ) 
     return true;

  else 
     return false;
}
	

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient 
//              object.
//              Returns true if the care card number of "this" Patient object is > the care 
//              card number of "rhs" Patient object and false otherwise.
bool Patient::operator>(const Patient & rhs) {

  if (careCard > rhs.getCareCard() )
    return true;

  else 
    return false;
}



  
	

// Description: Prints the content of "this" patient.
void Patient::printPatient( ) {

 cout << careCard << ", " << "Patient: " << name << ", " << address << ", " << phone << ", " << email << "\n";


}

   

