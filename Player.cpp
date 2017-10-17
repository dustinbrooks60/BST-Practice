/* Filename: Player.cpp
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
#include "Player.h"

using namespace std;

// Default Constructor
// Description:   Create a blank patient member
// Postcondition: name set to "To be entered", address set to "To be entered", phone set to 
//                "To be entered", email set to "To be entered", and care card is set to 
//                "0000000000".
Player::Player() {

  theLeaderboardPosition = 00;
  theName = "To be entered";
  theSeason = "To be entered";
  theTeam = "To be entered";
  thePosition = "To be entered";
  theGamesPlayed = 00;
  theGoals = 00;
  theAssists = 00;
  thePoints = 00;
  thePlusMinus = 00;
  thePenaltyMinutes = 00;
  thePointsPerGame = 00;
  thePowerPlayGoals = 00;
  thePowerPlayPoints = 00;
  theShorthandedGoals = 00;
  theShorthandedPoints = 00;
  theGameWinningGoals = 00;
  theOvertimeGoals = 00;
  theTotalShots = 00;
  theShootingPercentage = 00;
  theTimeOnIce = 00;
  theShiftsPerGame = 00;
  theFaceoffWins = 00;
}



//Constructor for players
Player::Player(int inputLeaderboardPosition, string inputName, string inputSeason, string inputTeam,  string inputPosition, int inputGamesPlayed, int inputGoals, int inputAssists, int inputPoints, int inputPlusMinus, int inputPenaltyMinutes, double inputPointsPerGame, int inputPowerPlayGoals, int inputPowerPlayPoints, int inputShorthandedGoals, int inputShorthandedPoints, int inputGameWinningGoals, int inputOvertimeGoals, int inputTotalShots, double inputShootingPercentage, double inputTimeOnIce, double inputShiftsPerGame, double inputFaceoffWins) {

  theLeaderboardPosition = inputLeaderboardPosition;
  theName = inputName;
  theSeason = inputSeason;
  theTeam = inputTeam;
  thePosition = inputPosition;
  theGamesPlayed = inputGamesPlayed;
  theGoals = inputGoals;
  theAssists = inputAssists;
  thePoints = inputPoints;
  thePlusMinus = inputPlusMinus;
  thePenaltyMinutes = inputPenaltyMinutes;
  thePointsPerGame = inputPointsPerGame;
  thePowerPlayGoals = inputPowerPlayGoals;
  thePowerPlayPoints = inputPowerPlayPoints;
  theShorthandedGoals = inputShorthandedGoals;
  theShorthandedPoints = inputShorthandedPoints;
  theGameWinningGoals = inputGameWinningGoals;
  theOvertimeGoals = inputOvertimeGoals;
  theTotalShots = inputTotalShots;
  theShootingPercentage = inputShootingPercentage;
  theTimeOnIce = inputTimeOnIce;
  theShiftsPerGame = inputShiftsPerGame;
  theFaceoffWins = inputFaceoffWins;
}

/*
//Constructor for goalies
Player::Player(double inputGAA, double inputSavePercentage, int inputWins, int inputShutouts) {

  theName = "To be entered";
  theTeam = "To be entered";
  thePlayerNumber = 00;
  thePosition = "To be entered";
  thePoints = 00;
  theGoals = 00;
  theAssists = 00;
  theGAA = inputGAA;
  theSavePercentage = inputSavePercentage;
  theWins = inputWins;
  theShutouts = inputShutouts;
}
*/

// Getters and setters
// Description: Returns a patient's name.

int Player::getLeaderboardPosition() const {

  return theLeaderboardPosition;
}

string Player::getName() const {

  return theName;
}


string Player::getSeason() const {
 
  return theSeason;
}

// Description: Returns a patient's address.
string Player::getTeam() const {

  return theTeam;
}


string Player::getPosition() const {

  return thePosition;
}


int Player::getGamesPlayed() const {

  return theGamesPlayed;
}


int Player::getGoals() const {

  return theGoals;
}


int Player::getAssists() const {

  return theAssists;
}


// Description: Returns a patient's care card number.
int Player::getPoints() const {

  return thePoints;
}


int Player::getPlusMinus() const {

  return thePlusMinus;
}

int Player::getPenaltyMinutes() const {

  return thePenaltyMinutes;
}

double Player::getPointsPerGame() const {

  return thePointsPerGame;
}

int Player::getPowerPlayGoals() const {

  return thePowerPlayGoals;
}

int Player::getPowerPlayPoints() const {

  return thePowerPlayPoints;
}

int Player::getShortandedGoals() const {
 
  return theShorthandedGoals;
}

int Player::getShorthandedPoints() const {

  return theShorthandedPoints;
}

int Player::getGameWinningGoals() const {

  return theGameWinningGoals;
}

int Player::getOvertimeGoals() const {

  return theOvertimeGoals;
}

int Player::getTotalShots() const {

  return theTotalShots;
}

double Player::getShootingPercentage() const {

  return theShootingPercentage;
}

double Player::getTimeOnIce() const {

  return theTimeOnIce;
}

double Player::getShiftsPerGame() const {

  return theShiftsPerGame;
}

double Player::getFaceoffWins() const {

  return theFaceoffWins;
}






/*
double Player::getGAA() const {

  return theGAA;
}

double Player::getSavePercentage() const {

  return theSavePercentage;
}

int Player::getWins() const {

  return theWins;
}

int Player::getShutouts() const {
 
  return theShutouts;
}
*/

// Description:   Sets the patient's name.
// Precondition:  aName must be a valid string (non-empty) and starts with an alphabetical 
//                letter.
// Postcondition: Patient's name is set to aName if it is valid, otherwise name is unchanged.

void Player::setLeaderboardPosition(const int aLeaderboardPosition) {

  theLeaderboardPosition = aLeaderboardPosition;
}
  

void Player::setName(const string aName) {

   locale loc;

   if (!aName.empty() && (isalpha(aName[0], loc)) ) {

     theName = aName; }

   else {

     theName = "Player: To be entered"; }
}

void Player::setSeason(const string aSeason) {

  theSeason = aSeason;
}


// Description: Sets the patient's address.
void Player::setTeam(const string aTeam) {

   theTeam = aTeam;
}


void Player::setPosition(const string aPosition) {
   
   thePosition = aPosition;
}

void Player::setGamesPlayed(const int aGamesPlayed) {

   theGamesPlayed = aGamesPlayed;
}
  

void Player::setGoals(const int aGoals) {

   theGoals = aGoals;
}


void Player::setAssists(const int aAssists) {

   theAssists = aAssists;
}

void Player::setPoints(const int aPoints) {

   thePoints = aPoints;
}

void Player::setPlusMinus(const int aPlusMinus) {

   thePlusMinus = aPlusMinus;
}

void Player::setPenaltyMinutes(const int aPenaltyMinutes) {

   thePenaltyMinutes = aPenaltyMinutes;
}

void Player::setPointsPerGame(const double aPointsPerGame) {

   thePointsPerGame = aPointsPerGame;
}

void Player::setPowerPlayGoals(const int aPowerPlayGoals) {

   thePowerPlayGoals = aPowerPlayGoals;
}

void Player::setPowerPlayPoints(const int aPowerPlayPoints) {

   thePowerPlayPoints = aPowerPlayPoints;
}

void Player::setShorthandedGoals(const int aShorthandedGoals) {

   theShorthandedGoals = aShorthandedGoals;
}

void Player::setShorthandedPoints(const int aShorthandedPoints) {

   theShorthandedPoints = aShorthandedPoints;
}

void Player::setGameWinningGoals(const int aGameWinningGoals) {

   theGameWinningGoals = aGameWinningGoals;
}

void Player::setOvertimeGoals(const int aOvertimeGoals) {

   theOvertimeGoals = aOvertimeGoals;
}

void Player::setTotalShots(const int aTotalShots) {

   theTotalShots = aTotalShots;
}

void Player::setShootingPercentage(const double aShootingPercentage) {

   theShootingPercentage = aShootingPercentage;
}

void Player::setTimeOnIce(const double aTimeOnIce) {

   theTimeOnIce = aTimeOnIce;
}

void Player::setShiftsPerGame(const double aShiftsPerGame) {

   theShiftsPerGame = aShiftsPerGame;
}

void Player::setFaceoffWins(const double aFaceoffWins) {

   theFaceoffWins = aFaceoffWins;
}



/*
void Player::setGAA(const double aGAA) {

  theGAA = aGAA;
}

void Player::setSavePercentage(const double aSavePercentage) {

  theSavePercentage = aSavePercentage;
}

void Player::setWins(const int aWins) {

  theWins = aWins;
}

void Player::setShutouts(const int aShutouts) {

  theShutouts = aShutouts;
}
*/

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number and false 
//              otherwise.
bool Player::operator==(const Player & rhs) {

  if (thePoints == rhs.getPoints() ) 
     return true;

  else 
     return false;
}
	

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient 
//              object.
//              Returns true if the care card number of "this" Patient object is > the care 
//              card number of "rhs" Patient object and false otherwise.
bool Player::operator>(const Player & rhs) {

  if (thePoints > rhs.getPoints() )
    return true;

  else 
    return false;
}



  
	

// Description: Prints the content of "this" player.
void Player::printPlayer() {

 cout << "Leaderboard Position: " << theLeaderboardPosition << "\n" << "Name: " << theName << "\n" << "Season: " << theSeason << "\n" <<  "Team: " << theTeam << "Position: " << thePosition << "\n" << "Games Played: " << theGamesPlayed << "\n" << "Goals: " << theGoals << "\n" << "Assists: " << theAssists << "\n" << "Points: " << thePoints << "\n" << "+/-: " << thePlusMinus << "\n" << "Penalty Minutes: " << thePenaltyMinutes << "\n" << "Points Per Game: " << thePointsPerGame << "\n" << "Power Play Goals: " << thePowerPlayGoals << "\n" << "Power Play Points: " << thePowerPlayPoints << "\n" << "Shorthanded Goals: " << theShorthandedGoals << "\n" << "Shorthanded Points: " << theShorthandedPoints << "\n" << "Game winning goals: " << theGameWinningGoals << "\n" << "Overtime Goals: " << theOvertimeGoals << "\n" << "Total shots: " << theTotalShots << "\n" << "Shooting percentage: " << theShootingPercentage << "\n" << "Time on ice: " << theTimeOnIce << "\n" << "Shifts per game: " << theShiftsPerGame << "\n" << "Faceoff Wins: " << theFaceoffWins << "\n";


}

   
