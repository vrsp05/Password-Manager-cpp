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

// This is the declaration of the fileDataMaster class.
class fileDataMaster
{
	// Declaring the private section of the class.
	private:

	// Declaring the public section of the class.
	public:

		// Creating empty constructor for the fileDataMaster class.
		fileDataMaster();

		// FUNCTION DECLARATIONS: ONLY FOR ACCOUNT DATA FILE MANAGEMENT.

		// Declaring function to save account data to file.
		void saveAccountDataToFile(string username, string master_password);

		// Declaring function to load account data from file.
		void loadAccountDataFromFile();

		// FUNCTION DECLARATIONS: ONLY FOR PASSWORD DATA FILE MANAGEMENT.

		// Declaring function to save password data to file.
		void savePasswordDataToFile();

		// Declaring function to load password data from file.
		void loadPasswordDataFromFile();


};

