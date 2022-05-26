#include <string>
#include <iostream>

using namespace std;

int main() {

	char evolving_fault, permanent_fault;
	double gradient, voltage, time_interval = 0;

	char run = 'y';

	while (run == 'y') {
		system("CLS");

		cout << "Lets find out the root cause of the Overhead Line Tripping problem." << endl;
		do
		{
			cout << "Is there an evolving fault? ( y / n ) : " << endl;
			cin >> evolving_fault;
		} while (!cin.fail() && tolower(evolving_fault) != 'y' && tolower(evolving_fault) != 'n');

		if (evolving_fault != 'y') {
			cout << "\nWhat is the rate of change of the curve? : ";
			while (!(cin >> gradient) || gradient < 0) {
				if (!cin) { //input validation for positive number
					cout << "Invalid input" << endl; 
					cin.clear(); //clear invalid input
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  //ignore everything until enter-key
				}
				cout << "What is the rate of change of the curve? (only Real numbers are accepted): " << endl;
			}

			//rest of the tree
		}
		else
			cout << "CT explosion" << endl;

		do
		{
			cout << "Would you like to try again? ( y / n)" << endl;
			cin >> run;
		} while (!cin.fail() && tolower(run) != 'y' && tolower(run) != 'n');
	}
	return 0;
}