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

// Constructor: Sets the default filename.
accountManager::accountManager()
{   
	// Set the filename for storing admin account data.
    adminAccountFilename = "adminAccountData.txt";

} // End of the constructor.


// Function to check if the account file exists.
bool accountManager::accountExists()
{   
	// Try to open the file.
    ifstream file(adminAccountFilename);

    // If the file opens successfully, it exists
    return file.good();

} // End of accountExists function.


// Helper function to get input without spaces.
string accountManager::getInputWithoutSpaces(const string& prompt)
{
	// Variable to hold user input.
	string input;

	// Loop until valid input without spaces is received.
	while (true)
	{
		// Display prompt.
		cout << prompt;

		// Read input.
		cin >> input;

		// Clear the rest of the line to check for extra characters.
		string remaining;
		getline(cin, remaining);

		// Check if there was anything after the first word (spaces + text).
		if (!remaining.empty())
		{
			// Check if remaining has non-whitespace characters.
			bool hasNonSpace = false;

			// Iterate through remaining characters.
			for (char c : remaining)
			{	
				// If any character is not a space, mark flag and break.
				if (!isspace(c))
				{	
					// Found a non-space character.
					hasNonSpace = true;

					// Break out of the loop.
					break;
				
				} // End of if block.
			
			} // End of for loop.

			// If there are non-space characters, input had spaces.
			if (hasNonSpace)
			{	
				// Inform the user of the error.
				cout << "Error: Input cannot contain spaces. Please try again.\n";

				// Continue to next iteration to re-prompt.
				continue;

			} // End of if block.
		}

		// Input is valid (no spaces).
		break;

	} // End of while loop.

	// Return the valid input.
	return input;

} // End of getInputWithoutSpaces function.


// Function to create a new account.
void accountManager::createAccount()
{   
	// Variables to hold user input.
    string adminUsername, adminPassword;

	// 1. Get username and password from the user.
    cout << "\n--- Create Master Account ---\n";
	adminUsername = getInputWithoutSpaces("Enter new Username (no spaces): ");
	adminPassword = getInputWithoutSpaces("Enter new Master Password (no spaces): ");

    // Write the credentials to the file.
    ofstream file(adminAccountFilename);

	// 2. Save the credentials to the file.
    if (file.is_open())
    {   
		// Write username and password to the file.
        file << adminUsername << endl << adminPassword;

		// Close the file.
        file.close();

		// Confirm account creation.
        cout << "Account created successfully!\n";

	} // End of if block.

	// 3. Handle file creation error.
    else {

		// Error handling if file cannot be created.
        cout << "Error: Could not create account file.\n";

	} // End of else block.

} // End of createAccount function.


// Function to handle user login.
bool accountManager::login()
{
	// Variables to hold stored and input credentials.
    string usernameInput, passwordInput;

    // 1. Load the existing account data from the file
    ifstream file(adminAccountFilename);

	// Read the stored username and password.
    if (file.is_open())
    {   
		// Read username and password from the file (no spaces expected).
        file >> adminAccountUsername >> adminAccountPassword;

		// Close the file.
        file.close();

	} // End of if block.

	// Handle file read error.
    else {

		// Error handling if file cannot be read.
        cout << "Error: Could not read account file.\n";

		// Return false indicating login failure.
        return false;
    
	} // End of else block.

    // 2. Ask the user for credentials and read input.
    cout << "\n--- Login ---\n";
	usernameInput = getInputWithoutSpaces("Username: ");
	passwordInput = getInputWithoutSpaces("Password: ");

    // 3. Verify
    if (usernameInput == adminAccountUsername && passwordInput == adminAccountPassword)
    {   
		// Login successful.
        return true;

	} // End of if block.

	// Login failed.
    else
    {   
		// Return false indicating login failure.
        return false;

	} // End of else block.

} // End of login function.