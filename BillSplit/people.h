#pragma once
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
class people
{
public:
	people();
	people(string name, double selfcharges);
	string getname();
	double getpayment();
	virtual void getinfo();
	void addcharge(double);

protected:
	string name;
	double totalpayment; //What they owe
};

