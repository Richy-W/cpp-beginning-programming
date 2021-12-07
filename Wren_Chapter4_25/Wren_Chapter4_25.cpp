#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	// declare variables
	string name;
	int month;
	double gig;
	char plan;
	double dataOverage;
	double total;

	cout << "Hello, welcome to your mobile bill callculator." << endl;
	cout << "Please enter your name." << endl;
	getline(cin, name);
	cout << "Using numeric value 1-12 what month are we looking at?" << endl;
	cin >> month;

	// if the month is in range display the plackage menu
	if (month > 0 && month < 13)
	{
		cout << "Thank you, " << name << endl; 
		cout << " " << endl;
		cout << "There are 3 data packages." << endl;
		cout << " " << endl;
		cout << "  Package A\n"
			<< "$39.99 per month\n"
			<< "$10 a gigabyte over 4 gigabytes used\n";
		cout << " " << endl;
		cout << "  Package B\n"
			<< "$59.99 per month\n"
			<< "$5 a gigabyte over 8 gigabytes used\n";
		cout << " " << endl;
		cout << "  Package C\n"
			<< "69.99 per month\n"
			<< "Unlimited data plan\n";
		cout << " " << endl;
		cout << "Please enter A, B, C, to indicate what package you are on." << endl; 

		cin >> plan;
		switch (plan) // used switch for menu selection
		{
		case 'a':
		case 'A':
			cout << "How many gigabytes of data did you use during the month? " << endl;
			cin >> gig;
			if (gig > 4)
			{
				dataOverage = (gig - 4);
				total = 39.99 + (dataOverage * 10.00);
				cout << " " << endl;
				cout << name << ", on Package " << plan << endl
					<< "The base charge is $39.99.\n"
					<< "with a $10 charge for every gigabyte over 4.\n"
					<< "At " << dataOverage << " gigabytes over your alloted data plan.\n" 
					<<"You owe $" << total << " for month " << month << endl;
			}
			else
			{
				cout << " " << endl;
				cout << name << ", on Package " << plan << endl;
				cout <<"You owe $39.99" << " for month " << month << endl;
			}

			break;
		case 'b':
		case 'B':
			cout << "How many gigabytes of data did you use during the month?" << endl;
			cin >> gig;
			if (gig > 8)
			{
				dataOverage = (gig - 8);
				total = 59.99 + (dataOverage * 5.00);
				cout << " " << endl;
				cout << name << ", on Pacage " << plan << endl
					<< "The base charge is $59.99.\n" 
					<< "with a charge of $5 for every gigabyte over 8.\n"
					<< "At " << dataOverage << " gigabytes over your alloted data plan.\n"
					<< "You owe $" << total << " for month " << month << endl;
			}
			else
			{
				cout << " " << endl;
				cout << name << ", on Package " << plan << endl;
				cout << "You owe 59.99" << " for month " << month << endl;
			}
			break;
		case 'c':
		case 'C':
			cout << " " << endl;
			cout << name << ", on Package " << plan << endl;
			cout << "You owe $69.99 for month " << month << endl; 
			break;

		default: //should default to error message

			cout << "Invalid selection, please restart the program and try again." << endl;


		}





	}
	else // program should dead end at this error
	{
		cout << "Invalid selection, please restart the program and try again." << endl;
	}
	return 0;


}