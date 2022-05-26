/*
Author: Masrur Rahman Zahin
Student ID: 101214608
Date: 3 April 2021
Description: This program finds out the potential root cause of the Overhead Line Tripping issue.
*/


#include <string>
#include <iostream>

using namespace std;

int main() {

	//declaring variables
	char evolving_fault, permanent_fault;
	double gradient, voltage, time_interval;

	bool run = true;

	cout << "Lets find out the root cause of the Overhead Line Tripping problem." << endl;
	
	do {
		system("CLS");

//start of data collection codeblock
		cout << "\nPlease provide all the details below." << endl << endl;
		
		//checks for evolving fault
		do { 
			cout << "Is there an evolving fault? ( y / n ) : ";					
			cin >> evolving_fault;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (tolower(evolving_fault) == 'y' || tolower(evolving_fault) == 'n') {
				break;
			}
			else {
				cout << "**Invalid Input, Try Again!**" << endl << endl;
			}
		} while (!cin.fail());
		
		//checks for gradient
		do {
			cout << "\nWhat is the rate of change of the curve? : ";
			while (!(cin >> gradient)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "**Invalid Input, Try Again!**" << endl;
				break;
			}
		} while (gradient == 0);

		//checks for voltage
		do {
			cout << "\nWhat is the voltage? : ";
			while (!(cin >> voltage)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "**Invalid Input, Try Again!**" << endl;
				break;
			}
		} while (voltage == 0);

		//checks for permanent fault
		do {
			cout << "\nIs there a permanent fault? ( y / n ) : ";
			cin >> permanent_fault;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (tolower(permanent_fault) == 'y' || tolower(permanent_fault) == 'n') {
				break;
			}
			else {
				cout << "**Invalid Input, Try Again!**" << endl << endl;
			}
		} while (!cin.fail());
		
		//checks for time interval
		do {
			cout << "\nWhat is the time interval between the last neutral distortions and a flashover? : ";
			while (!(cin >> time_interval)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "**Invalid Input, Try Again!**" << endl;
				break;
			}
		} while (time_interval == 0);
//end of data collection codeblock

//start of logic codeblock
		if (evolving_fault == 'y') {
			cout << "\nThe root cause is: CT Explosion" << endl;
		}
		else {
			if (gradient >= 0.100) {
				if (voltage <= 0.100) {
					cout << "\nThe root cause is: Tree Enroachment" << endl;
				}
				else {
					if (permanent_fault == 'y') {
						cout << "\nThe root cause is: Crane" << endl;
					}
					else {
						if (time_interval >= 100) {
							cout << "\nThe root cause is: Pollution" << endl;
						}
						else {
							cout << "\nThe root cause is: Lightning Strike" << endl;
						}
					}
				}
			}
			else {
				cout << "\nThe root cause is: Tree Enroachment" << endl;
			}
		}
//end of logic codeblock

		//asks to repeat again
		char repeat;
		
		do {
			cout << "\nWould you like to try again? ( y / n) : ";
			cin >> repeat;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (tolower(repeat) == 'n') {
				run = false;
				break;
			}
			else if (tolower(repeat) == 'y') {
				run = true;
				break;
			}
			else {
				cout << "**Invalid Input, Try Again!**" << endl << endl;
			}
		} while (!cin.fail());

	} while(run == true);
	
	return 0;
}