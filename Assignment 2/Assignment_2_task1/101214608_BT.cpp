/*
Author: Masrur Rahman Zahin
Student ID: 101214608
Date: 29 April 2021
Description: This program generates rain water harvesting table for a range of roof area and precipitation amount
*/


#include <iomanip>
#include <iostream>

using namespace std;

//main
int main() {
	float start_roof, end_roof, increment_roof, start_rain, end_rain, increment_rain;

	cout << "\nRain Harvesting Table" << endl;

	//variables declaration

//get the start value of roof
	do {
		cout << "\nEnter starting roof area in meter square (must be positive): ";
		cin >> start_roof;
		if (start_roof > 0) {
			break;
		}
		else {
			cout << "\ninvalid input, please try again\n";
		}
	} while (start_roof < 0);

	//get the end value of roof
	do {
		cout << "\nEnter ending roof area in meter square (must be positive): ";
		cin >> end_roof;
		if (end_roof > 0) {
			break;
		}
		else {
			cout << "\ninvalid input, please try again\n";
		}
	} while (end_roof < 0);

	//get the increment of roof
	do {
		cout << "\nEnter incremental value in roof area in meter square (must be positive): ";
		cin >> increment_roof;
		if (increment_roof > 0) {
			break;
		}
		else {
			cout << "\ninvalid input, please try again\n";
		}
	} while (increment_roof < 0);

	//get the start of rain
	do {
		cout << "\nEnter starting value for precipitation ammount in mm (must be positive): ";
		cin >> start_rain;
		if (start_rain > 0) {
			break;
		}
		else {
			cout << "\ninvalid input, please try again\n";
		}
	} while (start_rain < 0);

	//get the end of rain
	do {
		cout << "\nEnter starting value for precipitation ammount in mm (must be positive): ";
		cin >> end_rain;
		if (end_rain > 0) {
			break;
		}
		else {
			cout << "\ninvalid input, please try again\n";
		}
	} while (end_rain < 0);

	//get the increment of rain
	do {
		cout << "\nEnter incremental value for precipitation ammount in mm (must be positive): ";
		cin >> increment_rain;
		if (increment_rain > 0) {
			break;
		}
		else {
			cout << "\ninvalid input, please try again\n";
		}
	} while (increment_rain < 0);

	cout << "\n\t\t";

	//prints table comun name
	for (float i = start_rain; i <= end_rain + increment_rain; i += increment_rain) {
		if (i == end_rain) {
			break;
		}
		else if (i > end_rain) {
			cout << fixed << setprecision(2) << end_rain;
		}
		else {
			cout << fixed << setprecision(2) << i << "\t\t";
		}
	}

	cout << "\n";

	//prints table row name and content inside
	for (float j = start_roof; j <= end_roof + increment_roof; j += increment_roof)	{
		if (j == end_roof) {
			break;
		}
		else if (j > end_roof) {
			cout << fixed << setprecision(2) << end_roof << "\t\t";
		}
		else {
			cout << fixed << setprecision(2) << j << "\t\t";
		}
		for (float k = start_rain; k <= end_rain + increment_rain; k += increment_rain)
		{
			if (k == end_rain) {
				break;
			}
			else if (j > end_roof && k > end_rain) {
				cout << fixed << setprecision(2) << end_rain * end_roof << "\t\t";
			}
			else if (j > end_roof) {
				cout << fixed << setprecision(2) << end_roof * k << "\t\t";
			}
			else if (k > end_rain) {
				cout << fixed << setprecision(2) << end_rain * j << "\t\t";
			}
			else {
				cout << fixed << setprecision(2) << j * k << "\t\t";
			}
		}
		cout << endl;
	}

	return 0;
}