#include "nonpayingperson.h"

nonpayingperson::nonpayingperson()
{
	name = "none";
	totalpayment = 0.0;
}

nonpayingperson::nonpayingperson(string thename, double charges) : people(thename, charges){}

double nonpayingperson::splitbill(int numpeople)
{
	double returnvalue = totalpayment / numpeople;
	return returnvalue;
}

void nonpayingperson::getinfo()
{
	cout << fixed << setprecision(2) << name << ": $" << totalpayment << " " << "THIS PERSON IS NOT PAYING!" << endl;
}
