#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//prototyping functions to be used in the program
void readfile(string[]); 
int runningTotal(string, string[], const int);
void TotalWins(int[], string[], string[], const int, const int);
void selectionsort(int[], const int);
void swap(int&, int&);

int main()
{
	// varriables for the program
	const int numTeams = 29;
	const int seriesNum = 108;
	int total;
	string userTeam;
	int t = 0;
	int w = 0;

	//arrays for use in the program
	string teams[numTeams];
	string winners[seriesNum];
	int eachTeamWin[numTeams]; 

	//calling function to read the teams into the arrays
	readfile(teams);

	cout << "Please enter a team name\n";
	getline(cin, userTeam);

	total = runningTotal(userTeam, winners, seriesNum);

	cout << userTeam << " has won the World Series " << total << " times.\n";
	
	TotalWins(eachTeamWin, teams, winners, numTeams, seriesNum);

	selectionsort(eachTeamWin, numTeams);

	for (teams[t]; t < numTeams; t++)
	{
		cout << "The team " << teams[t] << " has won ";

		for (eachTeamWin[w]; w < numTeams; w++)
		{
			cout << eachTeamWin[w] << " World Series.\n";
		}
	}

}

//This function should read files into arrays
void readfile(string teams[]) 
{
	int totalTeams = 0;
	ifstream file;

	file.open("Teams.txt");
	if (file.is_open())
	{
		cout << "The Major league Teams are... \n";

		while (getline(file, teams[totalTeams]))
		{
			cout << teams[totalTeams] << endl;
			totalTeams++;
		}
		
		file.close();
	}
	else
	{
		cout << "Error opening file: File Not Found" << endl << endl;
	}
	

}

// This function will save the World Series Winners and save them to an array and find the how many times the users team has won
int runningTotal(string yourTeam, string theWinners[], const int num)
{
	int i = 0;
	int wins = 0;
	ifstream file;

	file.open("WorldSeriesWinners.txt");

	if (file.is_open())
	{
		
		while (getline(file, theWinners[i]))
		{
			if (yourTeam == theWinners[i])
			{
				wins++;
			}
			i++;
		}

		
		file.close();
	}
	else
	{
		cout << "Error opening file: File Not Found" << endl << endl;
	}

	return wins;
}


void TotalWins(int eachT[], string theTeams[], string theWinners[], const int tNum, const int wNum)
{
	int i = 0;
	int t = 0;
	int w = 0;
	int Win = 0;

	for (t = 0; t < tNum; t++)
	{
		

		for (i = 0; i < wNum; i++)
		{
			if (theTeams[t] == theWinners[i])
			{
				Win++;
		
			}
		}
		eachT[t] = Win;
	}

}

void selectionsort(int eachWin[], const int size)
{
	int start;
	int min;
	int minInd;
	
	for (start = 0; start < (size - 1); start++)
	{
		minInd = start;
		min = eachWin[start];

		for (int index = start + 1; index < size; index++)
		{

			if (eachWin[index] < min)
			{
				min = eachWin[index];
				minInd = index;

			}
		}
		swap(eachWin[minInd], eachWin[start]);
	}
}

void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;

}