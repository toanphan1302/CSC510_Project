// CSC510_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool Login();
string UserInfo[100][5] = {
	{"simpsoni", "abc123", "Isaiah", "123-456-7890", "123St"},
	{"riverad", "123abc", "David", "234-567-8901", "123DR"},
	{"fosterb", "abc321", "Brendan", "345-678-9012", "123RD"},
	{"toanp", "123cba", "Toan", "456-789-0123", "123Ave"} };

int main() {
	while (true) 
	{
		//Print out options to choose from the user
		cout << "0: Login\t1: Continue as guest\n2: View orders\n";
		//Read in user input
		int userInput = 0;
		cin >> userInput;

		bool loginResult = false;
		//Base on user input call the appropriate function
		switch (userInput)
		{
		case 0:
			loginResult = Login();
			if (loginResult == true) {
				//Call usef info function
				int userInfoInput = 0; // function call here
				switch (userInfoInput) {
				case 1:
					break;
					//call ordering function here:
				case 2:
					break;
				}
			}
			break;
		case 1:
			//call ordering function here:
			break;
		case 2:
			break;

		default:
			break;
		}
	}
	cout << "Program End" << endl;
	return 0;
}
bool Login()
{
	bool SuccessfulLogin = false;
	string username, password;
	cout << "Enter Username: ";
	cin >> username;
	cout << "\nEnter Password: ";
	cin >> password;
	for (int i = 0; i < sizeof(UserInfo) / sizeof(UserInfo[0]); i++)
	{
		string a, b;
		string t = " ";
		for (int j = 0; j < 2; j++)
		{
			if (a == username)
			{
				b = UserInfo[i][j];
				if (b == password)
				{
					cout << "You are now logged in as: " << UserInfo[i][2] << endl;
					return true;
				}
			}
			else
			{
				a = UserInfo[i][j];
				t = a;
			}
		}
	}
	cout << "Incorrect Username or Password." << endl;
	cout << "Try again." << endl;
	return false;
}