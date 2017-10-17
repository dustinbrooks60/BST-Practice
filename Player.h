/* Filename: Player.h

   Date of creation: May 23rd, 2017
   Author: Dustin Brooks
*/


#include <iostream>
#include <string>
#include <locale>

using namespace std;

// Default Constructor
// Description:   Create a blank patient member
// Postcondition: name set to "To be entered", address set to "To be entered", phone set to 
//                "To be entered", email set to "To be entered", and care card is set to 
//                "0000000000".
class Player {

private:

  int theLeaderboardPosition;
  string theName;
  string theSeason;
  string theTeam;
  string thePosition;
  int theGamesPlayed;
  int theGoals;
  int theAssists;
  int thePoints;
  int thePlusMinus;
  int thePenaltyMinutes;
  double thePointsPerGame;
  int thePowerPlayGoals;
  int thePowerPlayPoints;
  int theShorthandedGoals;
  int theShorthandedPoints;
  int theGameWinningGoals;
  int theOvertimeGoals;
  int theTotalShots;
  double theShootingPercentage;
  double theTimeOnIce;
  double theShiftsPerGame;
  double theFaceoffWins;



// Constructor
// Description:   Create a patient with a specific care card number
// Postcondition: name set to "To be entered", address set to "To be entered", phone set to 
//                "To be entered", email set to "To be entered", and care card is set to 
//                aCareCard.

public:

Player();

Player(int inputLeaderboardPosistion, string inputName, string inputSeason, string inputTeam,  string inputPosition, int inputGamesPlayed, int inputGoals, int inputAssists, int inputPoints, int inputPlusMinus, int inputPenaltyMinutes, double inputPointsPerGame, int inputPowerPlayGoals, int inputPowerPlayPoints, int inputShorthandedGoals, int inputShorthandedPoints, int inputGameWinningGoals, int inputOvertimeGoals, int inputTotalShots, double inputShootingPercentage, double inputTimeOnIce, double inputShiftsPerGame, double inputFaceoffWins);

/*
Player(double inputGAA, double inputSavePercentage, int inputWins, int inputShutouts);
*/

~Player();

int getLeaderboardPosition() const;

string getName() const;

string getSeason() const;

string getTeam() const;

string getPosition() const;

int getGamesPlayed() const;

int getGoals() const;

int getAssists() const;

int getPoints() const;

int getPlusMinus() const;

int getPenaltyMinutes() const;

double getPointsPerGame() const;

int getPowerPlayGoals() const;

int getPowerPlayPoints() const;

int getShortandedGoals() const;

int getShorthandedPoints() const;

int getGameWinningGoals() const;

int getOvertimeGoals() const;

int getTotalShots() const;

double getShootingPercentage() const;

double getTimeOnIce() const;

double getShiftsPerGame() const;

double getFaceoffWins() const;




//Setters


void setLeaderboardPosition(const int aLeaderboardPosition);
  

void setName(const string aName);

void setSeason(const string aSeason);


// Description: Sets the patient's address.
void setTeam(const string aTeam);


void setPosition(const string aPosition);

void setGamesPlayed(const int aGamesPlayed);
  

void setGoals(const int aGoals);


void setAssists(const int aAssists);

void setPoints(const int aPoints);

void setPlusMinus(const int aPlusMinus);

void setPenaltyMinutes(const int aPenaltyMinutes);

void setPointsPerGame(const double aPointsPerGame);

void setPowerPlayGoals(const int aPowerPlayGoals);

void setPowerPlayPoints(const int aPowerPlayPoints);

void setShorthandedGoals(const int aShorthandedGoals);

void setShorthandedPoints(const int aShorthandedPoints);

void setGameWinningGoals(const int aGameWinningGoals);

void setOvertimeGoals(const int aOvertimeGoals);

void setTotalShots(const int aTotalShots);

void setShootingPercentage(const double aShootingPercentage);

void setTimeOnIce(const double aTimeOnIce);

void setShiftsPerGame(const double aShiftsPerGame);

void setFaceoffWins(const double aFaceoffWins);


//Miscellaneous functions

bool operator==(const Player & rhs);

bool operator>(const Player & rhs);

void printPlayer();


};
