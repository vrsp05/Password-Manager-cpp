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

// Implementation of the accountManager class constructor.
accountManager::accountManager()
{

}; // End of the constructor.


// Implementation of the loginUser function.
void accountManager::loginUser()
{
	// Create an instance of the MenusManager class to display the login menu.
	MenusManager menuManager;

	// Variable to track if the user input is valid.
	bool valid_login_input = false;

	// Do while the user input is invalid.
	do
	{
		// Display the login menu to the user.
		int login_choice = menuManager.displayLoginMenu();

		// Handle user choice using if-else statements.

		// Option 1: Login.
		if (login_choice == 1)
		{

			cout << "You selected to Login," << endl;
			// Code to add a new password would go here.

			// Mark the input as valid.
			valid_login_input = true;

		} // End of if block. 

		// Option 2: Create an account.
		else if (login_choice == 2)
		{

			// Call the createAccount function to handle account creation.
			createAccount();

		} // End of else if block.

		// Option 3: Exit the program.
		else if (login_choice == 3)
		{

			// Mark the input as valid.
			valid_login_input = true;

			cout << "Exiting the Password Manager. Goodbye!" << endl;
			// Code to exit the program would go here.

		} // End of else if block.

		// Handle invalid input.
		else
		{
			// Display invalid input message.
			cout << "\nInvalid choice. Please select a valid option (1-3).\n" << endl;
			// Code to handle invalid input would go here.

		} // End of else block.

	} while (valid_login_input == false); // End of do-while loop.

}; // End of loginUser function.

// Implementation of the createAccount function using a txt file to store account information.
void accountManager::createAccount()
{	
	// Prompt user for account creation information.
	cout << "You have selected to create an account, please enter the information required below." << endl;

	// Prompt the user for a username.
	cout << "Enter your desired username: ";

	// Create variable and read the username from user input.
	string account_username;
	cin >> account_username;

	// Prompt the user for a password.
	cout << "Enter your desired password: ";

	// Create variable and read the password from user input.
	string account_master_password;
	cin >> account_master_password;




}