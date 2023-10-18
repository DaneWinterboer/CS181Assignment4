// Implementation file for the Manager class

#include <string>
#include <cstdlib>

using namespace std;

#include "Manager.h"

Manager::Manager() : Employee("", 0.00, 0.00)
{
  bonus = 0.00;
}

Manager::Manager(double inBonus, string inName, double inWage,
                 double inHour) : Employee(inName, inWage, inHour)
{
  bonus = inBonus;
}

double Manager::calcPay() const
{
  // Adds bonus to hourly wages
  double total = Employee::calcPay() + bonus;
  return total;
}

void Manager::setBonus(double inBonus)
{
  bonus = inBonus;
}
