/*
Author: Masrur Rahman Zahin
Student ID: 101214608
Date: 13 May 2021
Description: This program finds out the potential root cause of the Overhead Line Tripping issue and saves the data in the respective text files,
			 it also outputs the total count for each cause and also outputs the Highest and Lowest number of cause.
*/


#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;


//output total counts with cause
void ShowCount(int explosion_count, int encroachment_count, int crane_count, int pollution_count, int lightning_count) {
	cout << "-- Total count for the root cause of Over Head Line Tripping --"<< endl;
	cout << "\n Current Transformer Expolosions: " << explosion_count;
	cout << "\n Tree Encroachments: " << encroachment_count;
	cout << "\n Cranes: " << crane_count;
	cout << "\n Pollutions: " << pollution_count;
	cout << "\n Lightning Strikes: " << lightning_count << endl;
}

//logic block
string LogicBlock(string evolving_fault, double gradient, double voltage, string permanent_fault, double time_interval, string cause) {
	if (evolving_fault == "yes") {
		return cause = "explosion";
	}
	else {
		if (gradient >= 0.100) {
			if (voltage <= 0.100) {
				return cause = "encroachment";
			}
			else {
				if (permanent_fault == "yes") {
					return cause = "crane";
				}
				else {
					if (time_interval >= 100) {
						return cause = "pollution";
					}
					else {
						return cause = "lightning";
					}
				}
			}
		}
		else {
			return cause = "encroachment";
		}
	}
}

//check highest
int CheckHigh(int high, int explosion_count, int encroachment_count, int crane_count, int pollution_count, int lightning_count) {
	high = max({ explosion_count, encroachment_count, crane_count, pollution_count, lightning_count });
	return high;
}

//check lowest
int CheckLow(int low, int explosion_count, int encroachment_count, int crane_count, int pollution_count, int lightning_count) {
	low = min({ explosion_count, encroachment_count, crane_count, pollution_count, lightning_count });
	return low;
}

//output highest
void OutHigh(int high, int explosion_count, int encroachment_count, int crane_count, int pollution_count, int lightning_count){
	if (high == explosion_count) {
		cout << "\n Highest: Current Transformer Expolosions";
	}
	if (high == encroachment_count) {
		cout << "\n Highest: Tree Encroachments";
	}
	if (high == crane_count) {
		cout << "\n Highest: Cranes";
	}
	if (high == pollution_count) {
		cout << "\n Highest: Pollutions";
	}
	if (high == lightning_count) {
		cout << "\n Highest: Lightning Strikes";
	}
}

//output lowest
void OutLow(int low, int explosion_count, int encroachment_count, int crane_count, int pollution_count, int lightning_count) {
	if (low == explosion_count) {
		cout << "\n Lowest: Current Transformer Expolosions";
	}
	if (low == encroachment_count) {
		cout << "\n Lowest: Tree Encroachments";
	}
	if (low == crane_count) {
		cout << "\n Lowest: Cranes";
	}
	if (low == pollution_count) {
		cout << "\n Lowest: Pollutions";
	}
	if (low == lightning_count) {
		cout << "\n Lowest Lightning Strikes";
	}
	cout << endl;
}


int main() {

	//declaring variable
	string evolving_fault, permanent_fault, cause;
	double gradient = 0.0, voltage = 0.0, time_interval = 0.0;
	int explosion_count = 0, encroachment_count = 0, crane_count = 0, pollution_count = 0, lightning_count = 0, high = 0, low = 0;

	//declaring readfile
	ifstream readfile;

	//open readfile and read text from file
	readfile.open("oht_data.txt");

	while (readfile.good()) {

		//save varaibles from text file
		readfile >> evolving_fault >> gradient >> voltage >> permanent_fault >> time_interval;

		//call logic codeblock and save cause
		cause = LogicBlock(evolving_fault, gradient, voltage, permanent_fault, time_interval, cause);

		//open writefile and write to corresponidng file & increment count 
		ofstream writefile;

		//check for cause and save into respective files also counts
		if (cause == "explosion") {
			explosion_count++;
			writefile.open("ctexplod.txt", ios_base::app);
			writefile << evolving_fault << " " << gradient << " " << voltage << " " << permanent_fault << " " << time_interval << endl;
		}

		if (cause == "encroachment") {
			encroachment_count++;
			writefile.open("treeencr.txt", ios_base::app);
			writefile << evolving_fault << " " << gradient << " " << voltage << " " << permanent_fault << " " << time_interval << endl;
		}

		if (cause == "crane") {
			crane_count++;
			writefile.open("crane.txt", ios_base::app);
			writefile << evolving_fault << " " << gradient << " " << voltage << " " << permanent_fault << " " << time_interval << endl;
		}

		if (cause == "pollution") {
			pollution_count++;
			writefile.open("pollut.txt", ios_base::app);
			writefile << evolving_fault << " " << gradient << " " << voltage << " " << permanent_fault << " " << time_interval << endl;
		}

		if (cause == "lightning") {
			lightning_count++;
			writefile.open("lightnin.txt", ios_base::app);
			writefile << evolving_fault << " " << gradient << " " << voltage << " " << permanent_fault << " " << time_interval << endl;
		}

		//close writefile
		writefile.close();
	}

	//close readfile
	readfile.close();
	
	//call ShowCount fuction
	ShowCount(explosion_count, encroachment_count, crane_count, pollution_count, lightning_count);

	//Check Highest and Lowest
	high = CheckHigh(high, explosion_count, encroachment_count, crane_count, pollution_count, lightning_count);

	low = CheckLow(low, explosion_count, encroachment_count, crane_count, pollution_count, lightning_count);

	cout << "\n-- Highest and Lowest cause for Overhead Line Tripping --" << endl;

	//Output Highest and Lowest
	OutHigh(high, explosion_count, encroachment_count, crane_count, pollution_count, lightning_count);

	OutLow(low, explosion_count, encroachment_count, crane_count, pollution_count, lightning_count);

	return 0;
}