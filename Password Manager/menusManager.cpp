// Include all the needed libraries.
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>
#include "accountManager.h"
#include "menusManager.h"
#include "fileDataMaster.h"
#include "passwordMaster.h"

// Use the standard namespace.
using namespace std;

// Empty constructor for the MenusManager class. 
MenusManager::MenusManager()
{

} // End of the constructor.

// Function to display the main menu and get user input.
int MenusManager::displayMainMenu()
{
	// Variable to store user choice.
	int menu_choice;

	// Display the main menu.
	cout << "Password Manager Main Menu" << endl;
	cout << "1. Add a new password" << endl;
	cout << "2. View existing passwords" << endl;
	cout << "3. Edit an existing password" << endl;
	cout << "4. Delete a password" << endl;
	cout << "5. Exit" << endl;

	// Prompt user for input.
	cout << "Please select an option (1-5): ";

	// Get user input.
	cin >> menu_choice;

	// Return the user's choice.
	return menu_choice;

} // End of displayMainMenu function.

// Function to display the login menu and get user input.
int MenusManager::displayLoginMenu()
{
	// Variable to store user choice.
	int login_choice;

	// Display the main menu.
	cout << "Login Menu" << endl;
	cout << "1. Login" << endl;
	cout << "2. Create Account" << endl;
	cout << "3. Exit" << endl;

	// Prompt user for input.
	cout << "Please select an option (1-3): ";

	// Get user input.
	cin >> login_choice;

	// Return the user's choice.
	return login_choice;

} // End of displayMainMenu function.
