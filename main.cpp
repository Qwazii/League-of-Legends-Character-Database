#include <iostream>
#include <fstream>  
#include <string>

void input();
bool isDatabase();
void search();

int main() {
  input();
  /* functions needed:
  1. input function - allows user to input character and attributes , saves info to database
    - function to load database file
    - if no database , create fresh one
    - now handoff to input function

  2. search function - allows user to search by name or attributes (or all?)
  */

  /*
  Aatrox Fighter AD Top
  Ahri Mage AP Mid
  */
  return 0;
}

void input() {
  if (isDatabase() == false) {
    std::cout << "An error has occured with finding or creating the database. Exiting now.";
    return;
  }

  else {
    std::cout << "Inputting new Legend: " << std::endl;
    std::string Legend;
    switch(int x = 0){
      case 0: {
        std::cout << "Legend name: ";
        std::string Input;
        std::cin >> Input;
        Legend += Input;
        x++;
      }
      case 1: {
        std::cout << "Role (Assassin, Fighter, Mage, Marksman, Support, Tank): ";
        std::string Input;
        std::cin >> Input;
        Legend += " " + Input;
        x++;
      }
      case 2: {
        std::cout << "Damage Type (AD, AP): ";
        std::string Input;
        std::cin >> Input;
        Legend += " " + Input;
        x++;
      }
      case 3: {
        std::cout<<"Lane (Top, Jungle, Mid, Bot): ";
        std::string Input;
        std::cin >> Input;
        Legend += " " + Input;
        x++;
      }
      case 4: {
        std::cout << Legend << std::endl;
        // "Aatrox" is an "AD" "Fighter" in "Top" lane. Does this sound correct? (Y/N)
        x++;
      }
      case 5: {
        std::fstream db;
        db.open ("database.txt", std::ifstream::app);
        db << Legend << std::endl;
      }
    }
  }
}

bool isDatabase() {
  // start an fstream object and try to open the database file
  std::fstream db;
  db.open ("database.txt"); 
  // if it is open , close it and return true
  if (db.is_open()) db.close();
  
  // else if the file does not exist , create a new one and let the user know that the file was not detected therefore a new one had to be created
  else {
    std::ofstream ("database.txt");
    std::cout << "A database was not detected. A new one has been created." << std::endl;
  }
  return true;
}

// void search () {
//   /* search function for the database */
// } 
