// Password Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Include all the needed libraries.
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>
#include <fstream>

// Include all class headers.
#include "menusManager.h"
#include "accountManager.h"
#include "passwordMaster.h"

// Use the standard namespace.
using namespace std;

// Main function - execution starts here.
int main()
{   
	// Create instances of the manager classes.
	accountManager accountManager;
	passwordMaster passwordMaster;
	menusManager menuManager;

	// --- PHASE 1: Account Check / Creation ---

	// Check if an account already exists.
	if (!accountManager.accountExists())
	{	
		// No account exists, prompt user to create one.
		int choice = menuManager.showAccountCreationMenu();

		// If user chooses to create an account, proceed.
		if (choice == 1)
		{	
			// Create a new account.
			accountManager.createAccount();
			// After creation, we fall through to the Login Phase.

		} // End of if block.

		// If user chooses to exit, terminate the program.
		else
		{	
			// Exit the program message.
			cout << "Exiting program.\n";

			// End the program.
			return 0;

		} // End of else block.
	
	} // End of if block.

	// --- PHASE 2: Login Loop ---

	// Variable to track login status.
	bool loggedIn = false;

	// Variable to track login attempts.
	int loginAttempts = 0;

	// Maximum number of login attempts.
	const int MAX_LOGIN_ATTEMPTS = 3;

	// Loop until the user successfully logs in or chooses to exit.
	while (loggedIn == false && loginAttempts < MAX_LOGIN_ATTEMPTS)
	{	
		// Show the login menu and get user choice.
		int choice = menuManager.showLoginMenu();

		// If user chooses to login, attempt login.
		if (choice == 1)
		{	
			// Increment login attempts.
			loginAttempts++;

			// Attempt to login.
			if (accountManager.login())
			{	
				// Successful login.
				loggedIn = true;

				// Login success message.
				cout << "Login Successful!\n";

			} // End of if block.

			// If login fails, inform the user.
			else
			{	
				// Login failure message.
				cout << "Login Failed. Attempt " << loginAttempts << " of " << MAX_LOGIN_ATTEMPTS << ".\n";

			} // End of else block.

		} // End of if block.

		// Else if the user chooses to exit, terminate the program.
		else
		{	
			// Exit the program message.
			cout << "Exiting program.\n";

			// End the program.
			return 0;

		} // End of else block.
	
	} // End of while loop.

	// If maximum login attempts reached, exit the program.
	if (loginAttempts >= MAX_LOGIN_ATTEMPTS && !loggedIn)
	{	
		// Max attempts reached message.
		cout << "Maximum login attempts reached. Exiting program.\n";

		// End the program.
		return 0;

	} // End of if block.

	// --- PHASE 3: Main Application Loop ---

	// This runs until the user chooses to exit (Option 5)
	bool running = true;
	
	// Main application loop.
	while (running)
	{	
		// Show the main menu and get user choice.

		// Dsplay main menu and get user choice.
		int choice = menuManager.showMainMenu();

		// Handle user choice.
		switch (choice)
		{	
			// 1. Add Password.
			case 1:

				// Call the addPassword function.
				passwordMaster.addPassword();

				// Break to avoid fall-through.
				break;
		
			// 2. View All Passwords.
			case 2:

				// Call the viewPasswords function.
				passwordMaster.viewPasswords();

				// Break to avoid fall-through.
				break;

			case 3:

				// Call the editPassword function.
				passwordMaster.editPassword();

				// Break to avoid fall-through.
				break;

			// 4. Delete a Password.
			case 4:

				// Call the deletePassword function.
				passwordMaster.deletePassword();

				// Break to avoid fall-through.
				break;

			// 5. Exit Program.
			case 5:

				// Set running to false to exit the loop.
				running = false;

				// Exit message.
				cout << "Goodbye!\n";
				
				//	Break to avoid fall-through.
				break;
			
			// Default case for invalid input.
			default:

				// Inform the user of invalid option.
				cout << "Invalid option. Please try again.\n";
		
		} // End of switch block.
	
	} // End of while loop.

	// Program ends here.
	return 0;

} // End of main.cpp file.

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
