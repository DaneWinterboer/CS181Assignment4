// Author: Dane Winterboer
// Team Members: Aniruddha Biswas Atanu, Mohamed Amine Saoud
// Course: CS181: Foundations of Computer Science II
// Instructor: Dr. Shahadat
// Date: Sept. 28th, 2023
// Purpose: Program fullfills the requirements for team assignment 03.
// Description: Program utlizes two classes to analyze the cost of ownership
// of two different computers over the same number of years.  

#include <iostream>
#include <iomanip>
#include "Laptop.h"
#include "Desktop.h"

using namespace std;

int main()
{
  // Program constants
  const unsigned DECIMIAL_PLACES = 2;

  // Gets laptop info from user
  cout << "Enter name of laptop computer: ";
  string laptop_name;
  getline(cin, laptop_name);

  cout << "Enter cost of laptop computer: ";
  double laptop_cost;
  cin >> laptop_cost;

  // Gets desktop info from user
  cout << "Enter name of desktop computer: ";
  string desktop_name;
  string dummy;
  getline(cin, dummy);
  getline(cin, desktop_name);

  cout << "Enter cost of desktop computer: ";
  double desktop_cost;
  cin >> desktop_cost;

  // Gets general info from user
  cout << "How many hours will each computer be used in a year? ";
  double hours;
  cin >> hours;

  cout << "How many years will you own each computer? ";
  unsigned years;
  cin >> years;
  cout << endl;

  // Initlizes laptop object
  Laptop laptop1(laptop_name, laptop_cost, hours, years);

  // Initlizes desktop object
  Desktop desktop1(desktop_name, desktop_cost, hours, years);

  // Calculators total cost over time for both objects
  laptop1.costOverTime();
  desktop1.costOverTime();
  

  // Formating cout
  cout << fixed << setprecision(0);

  // Determines which computer cost more and prints difference
  if (laptop1 > desktop1)
  {
    // If laptop is more expensive than the desktop
    cout << "The cost of " << laptop1.getComputerName() << " is $" << 
            abs(laptop1 - desktop1) << " higher than the " << 
            desktop1.getComputerName() << "." << endl;
  }
  else if (laptop1 < desktop1)
  {
    cout << "The cost of " << desktop1.getComputerName() << " is $" << 
            abs(laptop1 - desktop1) << " higher than the " << 
            laptop1.getComputerName() << endl;
  }
  else
  {
    cout << "The cost of " << desktop1.getComputerName() <<
            " is the same as " << laptop1.getComputerName() << "." << endl; 
  }

  // Formating cout
  cout << fixed << setprecision(DECIMIAL_PLACES);

  // Prints info about laptop
  cout << "Cost of owning a " << laptop1.getComputerName() << " over " <<
          laptop1.getYearsUsed() << " years is $" << 
          laptop1.getTotalCostOverTime() << endl;

  // Prints info about desktop
  cout << "Cost of owning a " << desktop1.getComputerName() << " over " <<
          desktop1.getYearsUsed() << " years is $" << 
          desktop1.getTotalCostOverTime() << endl;

  return 0;
}
