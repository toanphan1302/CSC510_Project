// CSC510_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool Login();
int UserInfo(string userInfoArray[5]);

string UserInfoArray[100][5] = {
	{"simpsoni", "abc123", "Isaiah", "123-456-7890", "123St"},
	{"riverad", "123abc", "David", "234-567-8901", "123DR"},
	{"fosterb", "abc321", "Brendan", "345-678-9012", "123RD"},
	{"toanp", "123cba", "Toan", "456-789-0123", "123Ave"} };
string LoggedInUser[5]{};

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
				int userInfoInput = UserInfo(LoggedInUser); // function call here
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
		default:
			cout << "Invalid input";
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
	for (int i = 0; i < sizeof(UserInfoArray) / sizeof(UserInfoArray[0]); i++)
	{
		string a, b;
		string t = " ";
		for (int j = 0; j < 2; j++)
		{
			if (a == username)
			{
				b = UserInfoArray[i][j];
				if (b == password)
				{
					cout << "You are now logged in as: " << UserInfoArray[i][2] << endl;
					//Set LoggedInUser
					for (int k = 0; k < 5; k++) {
						LoggedInUser[k] = UserInfoArray[i][k];
					}
					return true;
				}
			}
			else
			{
				a = UserInfoArray[i][j];
				t = a;
			}
		}
	}
	cout << "Incorrect Username or Password." << endl;
	cout << "Try again." << endl;
	return false;
}
int UserInfo(string userInfoArray[5]) {
	while (true) {
		cout << "0: Show Infomation\t1: Order\n2: Back to home\n";
		int userInput = -1;
		cin >> userInput;
		switch (userInput)
		{
		case 0:
			cout << "Username:\t" << userInfoArray[0] << endl;
			cout << "Name:\t" << userInfoArray[2] << endl;
			cout << "Phone Number:\t" << userInfoArray[3] << endl;
			cout << "Address:\t" << userInfoArray[4] << endl;
			break;
		case 1:
			return 1;
		case 2:
			return 2;
		default:
			cout << "Invalid input" << endl;
		}
	}
}