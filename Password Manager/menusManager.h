#pragma once

// Include all the needed libraries.
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>
#include "accountManager.h"
#include "passwordMaster.h"

// Use the standard namespace.
using namespace std;

// This is the declaration of the MenusManager class.
class menusManager {

	// Declaring the public section of the class.
    public:

        // Display options when no account file exists.
        // Returns user choice (1 or 2).
        int showAccountCreationMenu();

        // Display options when an account file DOES exist.
        // Returns user choice (1 or 2).
        int showLoginMenu();

        // Display the main application options after login.
        // Returns user choice (1-5).
        int showMainMenu();

        // Helper function to safely get integer input.
        int getValidIntInput();

}; // End of MenusManager class.