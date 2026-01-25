// Include all the needed libraries.
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>
#include <fstream>
#include "accountManager.h"
#include "menusManager.h"
#include "passwordMaster.h"

// Use the standard namespace.
using namespace std;

// Function to display the account creation menu.
int menusManager::showAccountCreationMenu()
{   
	// Variable to hold user choice.
    int creationMenuChoise;

	// Display account creation options.
    cout << "\n--- Welcome ---\n";
    cout << "No master account found.\n";
    cout << "1. Create Master Account\n";
    cout << "Press any other key to exit program.\n";
    cout << "Select option: ";

	// Get user input.
    cin >> creationMenuChoise;

	// Return the user's choice.
    return creationMenuChoise;

} // End of showAccountCreationMenu function.


// Function to display the login menu.
int menusManager::showLoginMenu()
{   
	// Variable to hold user choice.
    int loginMenuChoice;
    cout << "\n--- Welcome Back ---\n";
    cout << "1. Login\n";
    cout << "Press any other key to exit program.\n";
    cout << "Select option: ";

	// Get user input.
    cin >> loginMenuChoice;

	// Return the user's choice.
    return loginMenuChoice;

} // End of showLoginMenu function.


// Function to display the main application menu.
int menusManager::showMainMenu()
{   
	// Variable to hold user choice.
    int mainMenuChoice;
    cout << "\n--- Main Menu ---\n";
    cout << "1. Add Password\n";
    cout << "2. View All Passwords\n";
    cout << "3. Edit an Existing Password\n";
    cout << "4. Delete a Password\n";
    cout << "5. Exit Program\n";
    cout << "Select option: ";

	// Get user input.
    cin >> mainMenuChoice;

	// Return the user's choice.
    return mainMenuChoice;

} // End of showMainMenu function.