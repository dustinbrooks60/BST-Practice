/* NHLStats.cpp
   Class Description: Tracks top NHL players stats
   In this version we use a BST to organize the players.

   Created on: Sept 7th, 2017
   Author: Dustin Brooks
*/
   

#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include "BST.h"
#include "Player.h"

using namespace std;

ifstream inFile;


void enter(BST * thePlayers) {

Player thePlayer();
  int playerLeaderboardPosition;
  string playerName;
  string playerSeason;
  string playerTeam;
  string playerPosition;
  int playerGamesPlayed;
  int playerGoals;
  int playerAssists;
  int playerPoints;
  int playerPlusMinus;
  int playerPenaltyMinutes;
  double playerPointsPerGame;
  int playerPowerPlayGoals;
  int playerPowerPlayPoints;
  int playerShorthandedGoals;
  int playerShorthandedPoints;
  int playerGameWinningGoals;
  int playerOvertimeGoals;
  int playerTotalShots;
  double playerShootingPercentage;
  double playerTimeOnIce;
  double playerShiftsPerGame;
  double playerFaceoffWins;


getline(cin >> ws, playerName);

thePlayer.setName(playerName);

cout << "Please enter the player's team: " << endl;

getline(cin >> ws, playerTeam);

thePatient.setTeam(playerTeam);

cout << "Please enter the address: " << endl;

getline(cin >> ws, theAddress);

thePatient.setAddress(theAddress);

cout << "Please enter the phone number: " << endl;

getline(cin >> ws, thePhone);

thePatient.setPhone(thePhone);

cout << "Please enter the email: " << endl;

getline(cin >> ws, theEmail);

thePatient.setEmail(theEmail);

if (thePlayers->insert(thePlayer))
   cout << "The player has been successfully entered" << endl;

else
   cout << "The player was unable to be entered" << endl;


return;
}



void remove(List * thePatients) {

string careCard;


  cout << "Please enter the care card of patient to be removed: " << endl;
  cin >> careCard;
  Patient toBeRemoved(careCard);


if (thePatients->remove(toBeRemoved))
  cout << "The patient has been successfully removed" << endl;

else
  cout << "The patient was unable to be removed" << endl;

return;
}





void searching(List * thePatients) {

string careCard;


  cout << "Please enter the care card of patient to be searched: " << endl;
  cin >> careCard;
  Patient toBeSearched(careCard);


if (thePatients->search(toBeSearched))
  cout << "The patient is in the system" << endl;

else
  cout << "The patient is not in the system" << endl;

return;
}



void modify(List * thePatients) {

bool done2 = false;
char input2 = 0;
string careCard;

string settedName;
string settedAddress;
string settedPhone;
string settedEmail;

  cout << "Please enter the care card of patient to be modified: " << endl;
  cin >> careCard;
  Patient toBeModified(careCard);

if (thePatients->search(toBeModified) == NULL) {
  cout << "That patient is not in the system" << endl;
  return;
}

Patient* toModify = thePatients->search(toBeModified); 


cout << "To change name: enter n" << endl;
cout << "To change address: enter a" << endl;
cout << "To change phone number: enter p" << endl;
cout << "To change email: enter e" << endl;
cout << "To exit: enter x" << endl;
cout << "Your choice: ";

cin >> input2;
input2 = tolower(input2);

switch(input2) {

  while (not done2) {
      case 'n': cout << "Type new name: " << endl; cin.ignore(); getline(cin, settedName); toModify->setName(settedName); cout << "Patient's name has been modified" << endl; break;


      case 'a': cout << "Type new address: " << endl; cin.ignore(); getline(cin, settedAddress); toModify->setAddress(settedAddress); cout << "Patient's address has been modified" << endl; break;

      case 'p': cout << "Type new phone number: " << endl; cin.ignore(); getline(cin, settedPhone); toModify->setPhone(settedPhone); cout << "Patient's phone number has been modified" << endl; break;

      case 'e': cout << "Type new email: " << endl; cin.ignore(); getline(cin, settedEmail); toModify->setEmail(settedEmail); cout << "Patient's email has been modified" << endl; break;


      case 'x': cout << "Returning to main menu\n" << endl; done2 = true; break;

      default: cout << "Not sure what you mean! Please, try again!" << endl;
    }
   
}
}


void print(List * thePatients) {

thePatients->printList();
}

int main() {

  // Variables declaration
  List* patients = new List(); 
  bool done = false;
  char input = 0;

  // Keep doing what the user selects until the user exits
  while (not done) {
    // Print menu to user 
  cout << "\n-----Welcome to NHL stats simplified!\n" << endl;
  cout << "To enter a new patient, enter: e" << endl;
  cout << "To remove a patient, enter: r" << endl;
  cout << "To search for a patient: enter s" << endl;
  cout << "To modify a patient: enter m" << endl;
  cout << "To print all patients: enter p" << endl;
  cout << "To exit: enter x" << endl;
    cout << "Your choice: ";
    cin >> input;
    input = tolower(input);
    switch(input) {
      case 'e': enter(patients); break;
      case 'r': remove(patients); break;
      case 's': searching(patients); break;
      case 'm': modify(patients); break;
      case 'p': print(patients); break;
      case 'x': cout << "\n----Bye!\n" << endl; done = true; delete patients; break;
      default: cout << "Not sure what you mean! Please, try again!" << endl;
    }

  }

  return 0;
}



