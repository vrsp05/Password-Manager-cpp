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
	// Display account creation options.
    cout << "\n--- Welcome ---\n";
    cout << "No master account found.\n";
    cout << "1. Create Master Account\n";
    cout << "Press any other integer to exit program\n";
    cout << "Select option: ";

    // Variable to hold user choice.
	int creationMenuChoice = getValidIntInput();

	// Return the user's choice.
    return creationMenuChoice;

} // End of showAccountCreationMenu function.


// Function to display the login menu.
int menusManager::showLoginMenu()
{   

	// Display login options.
    cout << "\n--- Welcome Back ---\n";
    cout << "1. Login\n";
    cout << "Press any other integer to exit program\n";
    cout << "Select option: ";

    // Variable to hold user choice.
	int loginMenuChoice = getValidIntInput();

	// Return the user's choice.
    return loginMenuChoice;

} // End of showLoginMenu function.


// Function to display the main application menu.
int menusManager::showMainMenu()
{   
	// Display main menu options.
    cout << "\n--- Main Menu ---\n";
    cout << "1. Add Password\n";
    cout << "2. View All Passwords\n";
    cout << "3. Edit an Existing Password\n";
    cout << "4. Delete a Password\n";
    cout << "5. Exit Program\n";
    cout << "Select option: ";

    // Variable to hold user choice.
    int mainMenuChoice = getValidIntInput();

	// Return the user's choice.
    return mainMenuChoice;

} // End of showMainMenu function.


// Helper function to safely get integer input.
int menusManager::getValidIntInput()
{   
	// Variable to hold user input as string.
	string input;
	
	// Variable to hold parsed integer.
	int userInput;
    
    // Loop until valid input is received.
    while (true)
    {
		// Read entire line including spaces.
		getline(cin, input);

		// Remove leading and trailing whitespace.
		input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
		input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);

		// Check if input is empty after trimming.
		if (input.empty())
		{
			// Prompt user again.
			cout << "Invalid input. Please enter a number: ";

			// Continue to next iteration.
			continue;
		
		} // End of if block. 

		// Try to convert string to integer.
		try
		{
			// Use stoi to convert string to integer.
			userInput = stoi(input);

			// Successfully converted, exit loop.
			break;

		} // End of try block.

		// Catch conversion errors.
		catch (const invalid_argument&)
		{
			// Input is not a valid number.
			cout << "Invalid input. Please enter a number: ";

		} // End of catch block.

		// Catch out of range errors.
		catch (const out_of_range&)
		{
			// Number is too large.
			cout << "Number too large. Please enter a valid number: ";

		} // End of catch block.

	} // End of while loop.

	// Return the valid choice.
    return userInput;

} // End of getValidIntInput function.