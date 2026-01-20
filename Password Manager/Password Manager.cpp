// Password Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Include all the needed libraries.
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>

// Include all class headers.
#include "menusManager.h"
#include "accountManager.h"
#include "passwordMaster.h"

// Use the standard namespace.
using namespace std;

// Main function - execution starts here.
int main()
{   
	// Create an instance of the MenusManager class.
	MenusManager menuManager;

	// Create an instance of the accountManager class.
	accountManager accountManager;

	// Call the loginUser function to handle user login.
	accountManager.loginUser();

	// Call the main menu function and store the returned choice.
	int menu_choice = menuManager.displayMainMenu();

	// Variable to track if the user input is valid.
	bool valid_menu_input = false;

	// Do while the user input is invalid.
	do
	{
		// Call the main menu function and store the returned choice.
		int menu_choice = menuManager.displayMainMenu();

		// Handle user choice using if-else statements.

		// Option 1: Add a new password.
		if (menu_choice == 1)
		{
			// Mark the input as valid.
			valid_menu_input = true;

			cout << "You selected to add a new password." << endl;
			// Code to add a new password would go here.

		} // End of if block.

		// Option 2: View existing passwords.
		else if (menu_choice == 2)
		{
			// Mark the input as valid.
			valid_menu_input = true;

			cout << "You selected to view existing passwords." << endl;
			// Code to view existing passwords would go here.

		} // End of else if block.

		// Option 3: Edit a current password.
		else if (menu_choice == 3)
		{
			// Mark the input as valid.
			valid_menu_input = true;

			cout << "You selected to edit a current password." << endl;
			// Code to edit a current password would go here.

		} // End of else if block.

		// Option 4: Delete a password.
		else if (menu_choice == 4)
		{
			// Mark the input as valid.
			valid_menu_input = true;

			cout << "You selected to delete a password." << endl;
			// Code to delete a password would go here.

		} // End of else if block.

		// Option 5: Exit the program.
		else if (menu_choice == 5)
		{
			// Mark the input as valid.
			valid_menu_input = true;

			cout << "Exiting the Password Manager. Goodbye!" << endl;
			// Code to exit the program would go here.

		} // End of else if block.

		// Handle invalid input.
		else
		{
			cout << "\nInvalid choice. Please select a valid option (1-5).\n" << endl;
			// Code to handle invalid input would go here.

		} // End of else block.

	} while (!valid_menu_input); // End of do-while loop.

	// Define end of main function.
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
