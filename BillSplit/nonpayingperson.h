#pragma once
#include "people.h"
class nonpayingperson :
	public people
{
public:
	nonpayingperson();
	nonpayingperson(string, double);
	double splitbill(int);
	void getinfo();

};

