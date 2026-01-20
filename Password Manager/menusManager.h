#pragma once

// Include all the needed libraries.
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>
#include "accountManager.h"
#include "fileDataMaster.h"
#include "passwordMaster.h"

// Use the standard namespace.
using namespace std;

// This is the declaration of the MenusManager class.
class MenusManager
{
	// Declaring the private section of the class.
	private:

		// Private members can be declared here if needed.

	// Declaring the public section of the class.
	public:

		// Empty constructor for the MenusManager class.
		MenusManager();

		// Declaring function to display the main menu and get user input.
		int displayMainMenu();

		// Declaring function to display the login menu.
		int displayLoginMenu();

};

