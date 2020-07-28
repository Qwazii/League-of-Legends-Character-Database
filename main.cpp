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
        int i;
        std::cout << "Role ( 0: Assassin, 1: Fighter, 2: Mage, 3: Marksman, 4: Support, 5: Tank): ";
        std::cin >> i; 
       switch(i) {
           case 0: {
            std::string Input = "Assassin";
            Legend += " " + Input;
            break;
           }
           case 1: {
            std::string Input = "Fighter";
            Legend += " " + Input;
            break;
           }
           case 2: {
            std::string Input = "Mage";
            Legend += " " + Input;
            break;
           }
           case 3: {
            std::string Input = "Marksman";
            Legend += " " + Input;
            break;
           }
           case 4: {
            std::string Input = "Support";
            Legend += " " + Input;
            break;
           }
           case 5: {
            std::string Input = "Tank";
            Legend += " " + Input;
            break;
           }

       }
        x++;
      }
      case 2: {
        int i;
        std::cout << "Damage Type (0: AD, 1: AP): ";
        std::cin >> i;
        switch(i) {
           case 0: {
            std::string Input = "AD";
            Legend += " " + Input;
            break;
           }
           case 1: {
            std::string Input = "AP";
            Legend += " " + Input;
            break;
           }
        x++;
      }
      }
      case 3: {
        int i;
        std::cout<<"Lane (0: Top, 1: Jungle, 2: Mid, 3: Bot): ";
        std::cin >> i;
         switch(i) {
           case 0: {
            std::string Input = "Top";
            Legend += " " + Input;
            break;
           }
           case 1: {
            std::string Input = "Jungle";
            Legend += " " + Input;
            break;
           }
           case 2: {
            std::string Input = "Mid";
            Legend += " " + Input;
            break;
           }
           case 3: {
            std::string Input = "Bot";
            Legend += " " + Input;
            break;
           }
        x++;
      }
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
