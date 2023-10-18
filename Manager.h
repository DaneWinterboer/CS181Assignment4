// Specification file for the Manager class

#ifndef MANAGER_H
#define MANAGER_H

// Inclusion of Parent Class specification file
#include "Employee.h"

using namespace std;

class Manager : public Employee
{
  private:
    double bonus;
  
  public:
    // Constructors
    Manager(); // default
    Manager(double, string, double, double);
    
    // Mutators
    void setBonus(double);
    
    // Accessors
    double calcPay() const;
};

#endif // MANAGER_H
