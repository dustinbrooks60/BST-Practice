/* NHLStats.cpp
   Class Description: Tracks top NHL players stats
   In this version we use a BST to organize the players.

   Created on: Sept 7th, 2017
   Author: Dustin Brooks
*/
   

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include "BST.h"
#include "Player.h"

using namespace std;


void following(BST<Player>& thePlayers) {

string inputTeam;
Player inputPlayer;

cout << "What is your favorite team? (enter the 3 letter acronym - ie. Washington will be WSH)" << endl;

getline(cin >> ws, inputTeam);

inputPlayer.setTeam(inputTeam);

Player searchedPlayer = thePlayers.retrieve(inputPlayer);


cout << "The player with the highest points on this team is: " << searchedPlayer.getName() << endl;

return;

}



/*
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


cout << "Please enter the player's leaderboard position: "

getline(cin >> ws, playerLeaderboardPosition);

thePlayer.setLeaderboardPosition(playerLeaderboardPosition);

cout << "Please enter the player's name: " << endl;

getline(cin >> ws, playerTeam);

thePlayer.setName(playerName);

cout << "Please enter the player's season: " << endl;

getline(cin >> ws, playerSeason);

thePlayer.setSeason(playerSeason);

cout << "Please enter the player's team: " << endl;

getline(cin >> ws, theTeam);

thePlayer.setTeam(playerTeam);

cout << "Please enter the player's position: " << endl;

getline(cin >> ws, playerPosition);

thePlayer.setPosition(playerPosition);

cout << "Please enter the number of games played: " << endl;

getline(cin >> ws, playerGamesPlayed);

thePlayer.setGamesPlayed(playerGamesPlayed);

cout << "Please enter the number of goals: " << endl;

getline(cin >> ws, playerGoals);

thePlayer.setPosition(playerGoals);

cout << "Please enter the number of assists: " << endl;

getline(cin >> ws, playerAssists);

thePlayer.setPosition(playerAssists);









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

*/


/*
void printAll(BST<Player> * thePlayers) {

thePlayers->traverseInOrder(printPlayer(this->Player));

return;
}
*/




int main() {

  // Variables declaration
  BST<Player> thePlayers; 
  Player newPlayer;
  bool done = false;
  char input = 0;
  string aLine;


  int placeholderLeaderboard;
  string placeholderName;
  string placeholderSeason;
  string placeholderTeam;
  string placeholderPosition;
  int placeholderGamesPlayed;
  int placeholderGoals;
  int placeholderAssists;
  int placeholderPoints;
  int placeholderPlusMinus;
  int placeholderPenaltyMinutes;
  double placeholderPointsPerGame;
  int placeholderPowerPlayGoals;
  int placeholderPowerPlayPoints;
  int placeholderShorthandedGoals;
  int placeholderShorthandedPoints;
  int placeholderGameWinningGoals;
  int placeholderOvertimeGoals;
  int placeholderTotalShots;
  double placeholderShootingPercentage;
  double placeholderTimeOnIce;
  double placeholderShiftsPerGame;
  double placeholderFaceoffWins;

ifstream inFile("dataFile.txt");

if (!inFile) {

cout << "Unable to open player file!" << endl;
}

if (inFile.is_open()) {

while (getline(inFile, aLine)) {

	stringstream ss(aLine);
        ss >> placeholderLeaderboard >> placeholderName >> 	
	placeholderSeason >> placeholderTeam >> placeholderPosition >> 
	placeholderGamesPlayed >> placeholderGoals >> placeholderAssists 
	>> placeholderPoints >> placeholderPlusMinus >> 
	placeholderPenaltyMinutes >> placeholderPointsPerGame >> 
	placeholderPowerPlayGoals >> placeholderPowerPlayPoints >> 
	placeholderShorthandedGoals >> placeholderShorthandedPoints >> 
	placeholderGameWinningGoals >> placeholderOvertimeGoals >> 
	placeholderTotalShots >> placeholderShootingPercentage >> 
	placeholderTimeOnIce >> placeholderShiftsPerGame >> 
	placeholderFaceoffWins; 

newPlayer = Player(placeholderLeaderboard, placeholderName, placeholderSeason, placeholderTeam, placeholderPosition, placeholderGamesPlayed, placeholderGoals, placeholderAssists, placeholderPoints, placeholderPlusMinus, placeholderPenaltyMinutes, placeholderPointsPerGame, placeholderPowerPlayGoals, placeholderPowerPlayPoints, placeholderShorthandedGoals, placeholderShorthandedPoints, placeholderGameWinningGoals, placeholderOvertimeGoals, placeholderTotalShots, placeholderShootingPercentage, placeholderTimeOnIce, placeholderShiftsPerGame, placeholderFaceoffWins);


thePlayers.insert(newPlayer);

}
}


  // Keep doing what the user selects until the user exits
while (not done) {
    // Print menu to user 
  cout << "\n-----Welcome to NHL stats simplified!-----\n" << endl;
  cout << "To determine which player you should be following, enter: f" << endl;
  cout << "To enter a new player, enter: e" << endl;
  cout << "To search for a player: enter s" << endl;
  cout << "To modify a player: enter m" << endl;
  cout << "To print all players: enter p" << endl;
  cout << "To exit: enter x" << endl;
    cout << "Your choice: ";
    cin >> input;
    input = tolower(input);
    switch(input) {

      case 'f': following(thePlayers); break;
/*
      case 'e': enter(thePlayers); break;
      case 's': searching(thePlayers); break;
      case 'm': modify(thePlayers); break;
      case 'p': print(thePlayers); break;
*/
      case 'x': cout << "\n----Bye!\n" << endl; done = true; /* delete thePlayers */; break;
      default: cout << "Not sure what you mean! Please, try again!" << endl;
    }

  }

  return 0;
}




