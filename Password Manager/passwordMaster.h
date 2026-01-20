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
#include "menusManager.h"

// Use the standard namespace.
using namespace std;

// This is the declaration of the passwordMaster class.
class passwordMaster
{

	// Declaring the private section of the class.
	private:


	// Declaring the public section of the class.
	public:

		// Creating empty constructor for the passwordMaster class.
		passwordMaster();

		// Declaring function to add a new password.
		void addNewPassword();

		// Declaring function to view existing passwords.
		void viewExistingPasswords();

		// Declaring function to edit an existing password.
		void editExistingPassword();

		// Declaring function to delete a password.
		void deletePassword();
};