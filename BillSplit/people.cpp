#include "people.h"

people::people()
{
	name = "none";
	totalpayment = 0.0;
}

people::people(string name, double selfcharges)
{
	this->name = name;
	this->totalpayment = selfcharges;
}

string people::getname()
{
	return name;
}

double people::getpayment()
{
	return totalpayment;
}

void people::getinfo()
{
	cout << fixed << setprecision(2) << name << ": $" << totalpayment << endl;
}

void people::addcharge(double othercharge)
{
	totalpayment = othercharge + totalpayment;
}
