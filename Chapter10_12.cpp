#include<iostream>
#include<cstring>
using namespace std;

bool isValidPassword(char[]);

int main()
{
	//array for password to be held
	char password[25];
	bool valid = false;

	// this section will make it clear what constitutes a valid password
	cout << "Welcome to the Password Validation Program\n";
	cout << " \n";
	cout << "A valid password should contain between at least 12 characters \n";
	cout << "It should include UPPER and LOWER case letters,\n";
	cout << "and should also include atleast one NUMBER and SPECIAL character\n";
	cout << " \n";
	cout << "Please enter your password\n";

	//using the do while loop I have allowed the user to re-attempt a new password if they fail to meet the criteria specified
	do
	{
		cin.getline(password, 25);

		valid = isValidPassword(password);
	} while (valid == false);

	return 0;



}

//this function will check for validation and give feedback to the user on the validity of the password they have entered
bool isValidPassword(char pwd[])
{
	//variables for checking password initialized as false
	bool length = false;
	bool upper = false;
	bool lower = false;
	bool digit = false;
	bool special = false;

	//checking length of password
	if (strlen(pwd) < 12)
	{
		cout << "Password should contain at least 12 charactrs\n";
		
	}
	else
	{
		length = true;
	}


	//Checking each letter for the paramaters to see if they are met
	for (int i = 0; i < strlen(pwd); i++)
	{
		if(isupper(pwd[i]))
		{
			upper = true;
		}
		if (islower(pwd[i]))
		{
			lower = true;
		}
		if (isdigit(pwd[i]))
		{
			digit = true;
		}
		if (ispunct(pwd[i]))
		{
			special = true;
		}
	}

	//this section will let the user know what parts of the password failed
	if (upper == false)
	{
		cout << "Password must contain 1 or more upper case letters.\n";
		
	}
	if(lower == false)
	{
		cout << "Password must contain 1 or more lower case letters.\n";
		
	}
	if (digit == false)
	{
		cout << "Password must contain 1 or more numeric digit.\n";
		
	}
	if (special == false)
	{
		cout << "Password must contain 1 or more special characters.\n";
		
	}

	//this statement will ensure all peramiters were met and return a boolean value to main
	if (upper == true && lower == true && digit == true && special == true && length == true)
	{
		cout << "Validation is complete:\n" << "Password is valid";
		return true;
	}
	else
	{
		return false;
	}
}
