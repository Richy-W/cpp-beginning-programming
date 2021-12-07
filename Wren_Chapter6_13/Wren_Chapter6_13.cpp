#include <iostream>
using namespace std;

// prototying functions
int validation(int, int);
int numEmployees();
int daysAbsent(int);
double avgAbsentDays(int, int);

int main()
{
	int employeeNum;
	int totalAbsent;
	double avgDaysAbsent;

	employeeNum = numEmployees(); // these insure that returned data from the functions are stored in a variable.
	totalAbsent = daysAbsent(employeeNum);
	avgDaysAbsent = avgAbsentDays(employeeNum, totalAbsent);

	cout << "With " << employeeNum << " employees, and " << totalAbsent << " total absences.\n" << "The average days absent is " << avgDaysAbsent << endl;
	

	return 0;
}

// this function will ensure that the numbers entered by the user are within acceptable ranges then returns its value 
int validation(int num1, int num2)
{

	while (num1 < num2)
	{
		cout << "ERROR, you can not enter a number less than " << num2 << ": \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> num1;
	}
	return num1;
}

// this function will ask how many employees a company has and calls the validation function to ensure that a posative number is entered
// it then returns the number given back to main 
int numEmployees()
{
	int num;

	cout << "How many employees are working at your business location?\n";
	cin >> num;

	num = validation(num, 1);

	return num;
}

// This function will take the number of employees entered from the numEmployees function and find out how many days each employee missed.
// It will also ensure that the number of days missed per employee is possible by calling the valadation function.
// The last thing this function will do is record the most days missed and least days missed before returning the total missed to main
int daysAbsent(int employeeNum)
{
	int totalMissed = 0;
	int mostAbsent;
	int leastAbsent;
	int employeeMissed;

	cout << "Please enter the number of days missed by employee #1:\n";
	cin >> employeeMissed;

	employeeMissed = validation(employeeMissed, 0); // checks the paramaters are met before setting the base standard for most and least absent variables

	mostAbsent = leastAbsent = employeeMissed; // this will create a base line for most and least absent to be recorded

	for (int person = 1; person < employeeNum; person++)
	{
		cout << "Please enter the number of days missed by employee #" << (person + 1) << ":\n";
		cin >> employeeMissed;
		employeeMissed = validation(employeeMissed, 0);
		totalMissed += employeeMissed;



		if (employeeMissed > mostAbsent)
		{
			mostAbsent = employeeMissed;
		}
		else if (employeeMissed < leastAbsent)
		{
			leastAbsent = employeeMissed;
		}

	}
	cout << "The most days missed by a single employee is " << mostAbsent << endl;
	cout << "The least amount of days missed by a single employee is " << leastAbsent << endl;

	return totalMissed;
}

//This function will do the calculation for average days missed and return it to main
double avgAbsentDays(int employeeNum, int totalAbsent)
{
	double average = totalAbsent / static_cast<double>(employeeNum);

	return average;
}
