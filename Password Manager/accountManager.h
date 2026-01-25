#pragma once

// Include all the needed libraries.
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>

// Use the standard namespace.
using namespace std;

// This is the declaration of the accountManager class.
class accountManager
{

    // Declaring the private section of the class.
    private:

		// Admin account variables.
        string adminAccountFilename;
        string adminAccountUsername;
        string adminAccountPassword;

		// Helper function to get input without spaces.
		string getInputWithoutSpaces(const string& prompt);

	// Declaring the public section of the class.
    public:

        // Constructor
        accountManager();

        // Checks if the "account.txt" file already exists
        bool accountExists();

        // Handles user input to create a new account and saves it
        void createAccount();

        // Handles user input for login and verifies against the file.
        // Returns true if login is successful, false otherwise.
        bool login();

}; // End of accountManager class.

