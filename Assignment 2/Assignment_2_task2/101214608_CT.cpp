/*
Author: Masrur Rahman Zahin
Student ID: 101214608
Date: 29 April 2021
Description: Challenge task for Assignment 2
*/


#include <iomanip>
#include <iostream>

using namespace std;

//function that prints column name
void Column(float start_rain, float end_rain, float increment_rain) {
	//table column name

	bool isDone = false;
	if (start_rain == end_rain) {
		isDone = true;
	}
	else if (start_rain > end_rain) {
		cout << fixed << setprecision(2) << end_rain;
		isDone = true;
	}
	else {
		cout << fixed << setprecision(2) << start_rain << "\t\t";
	}
	if (!isDone) {
		Column(start_rain + increment_rain, end_rain, increment_rain);
	}

}

//function that prints table content
void Table_Content(float start_roof, float end_roof, float start_rain, float end_rain, float increment_rain) {
	//table contents

	bool isDone = false;
	if (start_rain == end_rain) {
		isDone = true;
	}
	else if (start_roof > end_roof && start_rain > end_rain) {
		cout << fixed << setprecision(2) << end_rain * end_roof << "\t\t";
		isDone = true;
	}
	else if (start_roof > end_roof) {
		cout << fixed << setprecision(2) << end_roof * start_rain << "\t\t";
	}
	else if (start_rain > end_rain) {
		cout << fixed << setprecision(2) << end_rain * start_roof << "\t\t";
		isDone = true;
	}
	else {
		cout << fixed << setprecision(2) << start_roof * start_rain << "\t\t";
	}
	if (!isDone) {
		Table_Content(start_roof, end_roof, start_rain + increment_rain, end_rain, increment_rain);
	}

}

//function that prints table row and contents
void Row(float start_roof, float end_roof, float increment_roof, float start_rain, float end_rain, float increment_rain) {
	//table row name plus content inside

	bool isDone = false;
	if (start_roof == end_roof) {
		isDone = true;
	}
	else if (start_roof > end_roof) {
		cout << fixed << setprecision(2) << end_roof << "\t\t";
		isDone = true;
	}
	else {
		cout << fixed << setprecision(2) << start_roof << "\t\t";
	}
	Table_Content(start_roof, end_roof, start_rain, end_rain, increment_rain);
	cout << endl;

	if (!isDone) {
		Row(start_roof + increment_roof, end_roof, increment_roof, start_rain, end_rain, increment_rain);
	}
}

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

	//calls column function
	Column(start_rain, end_rain, increment_rain);

	cout << "\n";

	//calls row function
	Row(start_roof, end_roof, increment_roof, start_rain, end_rain, increment_rain);

	return 0;
}
