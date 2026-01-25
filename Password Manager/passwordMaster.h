#pragma once

// Include all the needed libraries.
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>

// Forwared declaration of menusManager to avoid circular dependency.
class menusManager;

// Use the standard namespace.
using namespace std;

// A simple structure to hold one password entry
struct PasswordEntry {
    
	// Unique identifier for the password entry.
    int id;

	// Site or service name.
    string siteName;

	// Username for the site or service.
    string sitePassword;

}; // End of PasswordEntry struct.

// This is the declaration of the passwordMaster class.
class passwordMaster
{   
	// Declaring the private section of the class.
    private:

		// Filename to store passwords.
        string allStoredDataFilename;

		// Vector to hold all password entries in memory.
        vector<PasswordEntry> allStoredPasswords;

        // Helper: Loads data from text file into the 'allStoredPasswords' vector
        void loadPasswords();

        // Helper: Saves the current 'allStoredPasswords' vector to the text file
        void savePasswords();

		// Create instance of menusManager to use input helper.
		menusManager* menuManager;
    
    // Declaring the public section of the class.
    public:
        
		// Constructor.
        passwordMaster();

		// Destructor.
		~passwordMaster();

        // 1. Add: Ask user for details, generate ID, save.
        void addPassword();

        // 2. View: Display all passwords in a table.
        void viewPasswords();

        // 3. Edit: Find by ID, update details, save.
        void editPassword();

        // 4. Delete: Find by ID, remove, save.
        void deletePassword();

}; // End of passwordMaster class.