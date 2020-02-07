Zion Matthews
:-
s198031
Introduction to C++ Assesment 3
PlayerProfileDataBase

## I. Requirments

1. Description of Problem

   -**Name**: PlayerProfileDataBase

   -**Problem Statement**: Create a program that loads, updates, and saves player profile 
   information to a binary file.

   -**Problem Specifications**: The program must use variables, loops, array's, binary search, and
   binary save.

2. Input Information

     -You will need to type numbers to the program to navigate the menu

3.  Output Information

     -When the program begains, A menu will popup and give you a few options. Create a player
      profile. Search for a profile. See the list of profiles. Save and load.

4.  User Interface Information

    - The program will display a menu

##II. Design 

=============== PLAYER MODIFY MENU V3 =====================
1: Create a player profile.
2: show all player profiles created
3: Search for a player profile.
4: Save and load the player profiles.
5: Exit from program.

3. ### Object Information

   **File**: PlayerProfileDatabase

    Description: The main of the program. The menu

    **Attributes**

         Name: DataBase playerList
         Description: Name for the class DataBase as an access.
         Type: Classname

         Name:playerList.load()
         Description:Used to load an any saved files before the program starts
         Type: Classname

         Name: choice
         Description: Used for as input for the menu
         Type: Int
    
   **File**: Player
 
      Description: Everything envolving rhe players name and score

      **Attributes**
           
           Name: Player();/~Player();
           Description: Defualt constructers
           Type: Function

           Name: Player(const char name[30] , int score)
           Description: Name and score for int
           Type: Function

           Name: char* getName()
           Description: Grabs name
           Type: char

           Name: getScore()
           Description: Grabs score
           Type: Function

           Name: void setName(const char name[30])
           Description: sets name
           Type: Function

           Name: void setScore(int score)
           Description: sets score
           Type: Function

           Name: char _Name[30]
           Description: char array
           Type: array

           Name: void save(std:;ofstream& out)
           Description: to save 
           Type: Function

           Name: bool load(std::ifstream& in)
           Description: to load
           Type: Function
    
    **File**: DataBase

          Description: where everything Requirments

          **Attributes**

              Name:DataBase:;DataBase/~Database()
              Description: defualt constructers
              Type: Function

              Name: void Database::Add(player newProfile)
              Description: Adds the player profile to the array list
              Type: Function

              Name: void DataBase::Sort()
              Description: Sorts the list in alhpabetical order
              Type: Function

              Name: DataBase::List()
              Description: shows the list of all created player profiles that are dstored in the array
              Type: Function

              Name: void DataBase::Search()
              Description: searches for an inputted profile and allows the user to edit int
              Type: Function

              Name: int BinarySearch(char name[30])
              Description: Searches the profiles using binary search
              Type: Function

              Name: Player* PlayerProfilesList
              Description: Array list of player
              Type: Array

              Name: int _arrayLenght = 1
              Description: length of an array
              Type: int
