// CSC510_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Pizza {
public:
	int size;
	string toppings;
	Pizza(int x, string y) {
		//cout << "Creating pizza with your custom settings..." << endl;
		size = x;
		toppings = y;
	}
	Pizza() {
		size = 0;
		toppings = "";
	}

	static void PrintPizza(int size, string toppings) {
		string mySize;
		if (size == 0) {
			mySize = "Medium";
		}
		else if (size == 1)
		{
			mySize = "Large";
		}
		cout << "Size: " << mySize << endl;
		cout << "Toppings: " << toppings << endl;
	}

	void PizzaMaker()
	{
		cout << "Creating pizza with your custom settings..." << endl;
		int orderCorrect = 2;
		int mySize = 2;
		string myToppings = "pizza with ";
		string possibleToppings[5] = { "cheese", "tomato sauce", "pepperoni", "mushroom", "pineapple"
		};
		int toppingsBool = 2;
		cout << "Welcome to the ordering page!" << endl;
		cout << "Here you'll create the perfect pizza for you." << endl;
		while (orderCorrect != 1)
		{
			mySize = 2;
			cout << "First, let's choose how big you want your pizza to be." << endl;
			while (mySize != 1 && mySize != 0)
			{
				cout << "Please enter 0 for a medium, or 1 for a large: ";
				cin >> mySize;
				if (mySize != 1 && mySize != 0)
				{
					cout << "Sorry, that input is invalid. Please try again." << endl;
				}
			}
			myToppings = "pizza with ";
			toppingsBool = 2;
			cout << "Thank you! Now it's time to pick out your toppings." << endl;
			for (int i = 0; i < 5; i++)
			{
				toppingsBool = 2;
				while (toppingsBool != 1 && toppingsBool != 0)
				{
					cout << "Would you like " << possibleToppings[i] << " on your pizza? (0 for no, 1 for yes): ";
					cin >> toppingsBool;
					if (toppingsBool != 1 && toppingsBool != 0)
					{
						cout << "Sorry, that input is invalid. Please try again." << endl;
					}
					else
					{
						cout << "Thank you for your input!" << endl;
						if (toppingsBool == 1)
						{
							myToppings = myToppings + possibleToppings[i] + ", ";
						}
					}
				}
			}
			if (myToppings == "pizza with ")
			{
				myToppings = myToppings + "nothing, ";
			}
			myToppings = myToppings + "and made with love!";
			orderCorrect = 2;
			cout << "There's one more step - let's make sure you haven't changed your mind." <<
				endl;
			while (orderCorrect != 0 && orderCorrect != 1)
			{
				if (mySize == 0)
				{
					cout << "You want a medium ";
				}
				if (mySize == 1)
				{
					cout << "You want a large ";
				}
				cout << myToppings << endl;
				cout << "Is this correct? (0 for no, 1 for yes): ";
				cin >> orderCorrect;
				if (orderCorrect != 1 && orderCorrect != 0)
				{
					cout << "Sorry, that input is invalid. Please try again." << endl;
				}
				else if (orderCorrect == 0)
				{
					cout << "OK, then, let's re-make your pizza then." << endl;
				}
				else if (orderCorrect == 1)
				{
					cout << "Great! Let's proceed to the checkout." << endl;
				}
			}
		}
		Pizza myPizza(mySize, myToppings);
		size = mySize;
		toppings = myToppings;
		//return myPizza;
	};
};



bool Login();
int UserInfo(string userInfoArray[5]);
Pizza PizzaOrder[100];
int NumberOfPizza = 0;
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
		Pizza newPizza(0, "");

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
					newPizza.PizzaMaker();
					PizzaOrder[NumberOfPizza] = newPizza;
					NumberOfPizza += 1;
					break;
					//call ordering function here:

				case 2:
					break;
				}
			}
			break;
		case 1:
			newPizza.PizzaMaker();
			PizzaOrder[NumberOfPizza] = newPizza;
			NumberOfPizza += 1;
			break;

		case 2:
			if (NumberOfPizza <= 0) {
				cout << "There is no order" << endl;
			}
			else
			{
				for (int i = 0; i < NumberOfPizza; i++) {
					cout << "Pizza " << i + 1 << ":" << endl;
					PizzaOrder[i].PrintPizza(PizzaOrder[i].size, PizzaOrder[i].toppings);
				}
			}
			break;

		default:
			cout << "Invalid input" << endl;
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



