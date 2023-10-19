/*
Author: Dane Winterboer
Course: CS181: Foundations of Computer Science II
Instructor: Dr. Shahadat
Date: Oct. 20th, 2023
Git Repo link: https://github.com/DaneWinterboer/CS181Assignment4
Purpose: Program fullfills the requirements for team assignment 04.
Description: Program utlizes a dynamically allocated array, which contains
pointers to instances of a derived class "Manager," to determine the highest
and average salary of a user defined number of manager level employees.
*/

#include <iostream>
#include <iomanip>
#include "Manager.h"

using namespace std;

int main()
{
  // Program constants
  const unsigned DECIMAL_PLACES = 2;
  
  // Gets number of managers from user
  size_t totalManagers;
  cout << "Enter number of managers: ";
  cin >> totalManagers;
  cout << endl; // blank line
  
  // Dynamically allocates array of managers
  Manager* managers = new Manager[totalManagers];
  
  // Gets user input of manager information
  for(size_t index = 0; index < totalManagers; index++)
  {
    // Gets manager name
    cout << "Enter manager " << index << " name: ";
    string name;
    string dummy;
    getline(cin, dummy);
    getline(cin, name);
    
    // Gets manager name
    cout << "Enter manager " << index << " hourly wage: ";
    double wage;
    cin >> wage;
    
    // Gets manager hours
    cout << "Enter manager " << index << " hours worked: ";
    double hours;
    cin >> hours;
    
    // Gets manager bonus
    cout << "Enter manager " << index << " bonus: ";
    double bonus;
    cin >> bonus;
    cout << endl; // blank line

    
    // Creates a new object initialized with user input
    Manager* temp = new Manager(bonus, name, wage, hours);
    
    // Stores new object in manager array
    managers[index] = *temp;
    
    // Removes temp from active memory
    temp = nullptr;
    delete temp;
  }
  
  // Finds highest paid manager in list
  size_t highestPayIndex = 0; // tracking varaiable for highest paided index
  
  for(size_t index = 1; index < totalManagers; index++)
  {
    // If true, assigns newest highest pay manager and its index position
    if(managers[highestPayIndex].calcPay() < managers[index].calcPay())
    {
      highestPayIndex = index;
    }
  }
  
  // Displays highest paid manager
  cout << "Highest paid manager is " <<
          managers[highestPayIndex].getName() << fixed << 
          setprecision(DECIMAL_PLACES) << " who is paid $" <<
          managers[highestPayIndex].calcPay() << endl;
  
  // Tracking variables for average calculation
  double totalPay = 0;

  // Sums all managers pay
  for(size_t index = 0; index < totalManagers; index++)
  {
    totalPay += managers[index].calcPay();
  }
   
  // Calculates average
  double averagePay = totalPay / static_cast<double>(totalManagers);
  
  // Displays average
  cout << "Average pay is $" << averagePay << endl;
  
  return 0;
}
