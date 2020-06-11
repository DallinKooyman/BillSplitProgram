#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include "nonpayingperson.h"

using namespace std;

bool checkname(string nameToCheck, vector<people> theRoster) {
	for (auto iter = theRoster.begin(); iter != theRoster.end(); iter++) {
		if (iter->getname() == nameToCheck) {
			return true;
		}
	}
	return false;
}

double totalcharge()
{
	double const tax = 1.08;
	double onecharge = 0.0;
	double totalamount = 0.0;
	cout << "Enter all prices for this person and enter \"stop\" when done." << endl;
	cin >> onecharge;
	while (!cin.fail()) {
		cin.ignore();
		totalamount += onecharge;
		cin >> onecharge;
		cin.ignore();
	}
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << endl;
	}
	totalamount *= tax;
	return totalamount;
}


int main() {

	string name = "";
	int totalpeople = 0;
	double charge = 0;

	
	vector<people> roster;
	vector<nonpayingperson> nonpayingroster;
	cout << "Enter paying people's name and their charge then \"stop\" when done." << endl;
	cout << "Name: ";
	getline(cin, name);
	cout << endl;
	while (name != "stop") {
		charge = totalcharge();
		roster.push_back(people(name, charge));
		cout << "Name: ";
		getline(cin, name);
		cout << endl;
		while (checkname(name, roster)) {
			cout << "You have already added that person. Please add a different person." << endl;
			cout << "Name: ";
			getline(cin, name);
			cout << endl;
		}

	}

	cout << "Now enter the non paying people's info then \"stop\" when done." << endl;
	cout << "Name: ";
	getline(cin, name);
	cout << endl;
	while (name != "stop") {
		charge = totalcharge();
		nonpayingroster.push_back(nonpayingperson(name, charge));
		cout << "Name: ";
		getline(cin, name);
		cout << endl;
	}

	if (nonpayingroster.size() > 0) {
		cout << "Pre split info" << endl;
		for (int i = 0; i < roster.size(); ++i) {
			roster.at(i).getinfo();
		}
	}
	else {
		cout << "No non-paying people. Everyone is charge with the total amount out in their name." << endl;
	}

	for (int i = 0; i < nonpayingroster.size(); ++i) {
		 nonpayingroster.at(i).getinfo();
	}
	
	double splitcharge = 0.0;
	if (nonpayingroster.size() > 0) {
		cout << endl << "Splitting" << endl;
		for (int i = 0; i < nonpayingroster.size(); ++i) {
			splitcharge += nonpayingroster.at(i).splitbill(roster.size());
		}
	}
	
	for (int i = 0; i < roster.size(); ++i) {
		roster.at(i).addcharge(splitcharge);
	}

	cout << endl << "Final amounts:" << endl;
	for (int i = 0; i < roster.size(); ++i) {
		roster.at(i).getinfo();
	}

	if (nonpayingroster.size() > 0) {
		cout << endl << "Nonpaying info:" << endl;
		for (int i = 0; i < nonpayingroster.size(); ++i) {
			nonpayingroster.at(i).getinfo();
		}
	}


	return 0;
}