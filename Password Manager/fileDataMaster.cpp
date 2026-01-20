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
#include "fileDataMaster.h"
#include "passwordMaster.h"

// Use the standard namespace.
using namespace std;

// Implementation of the passwordMaster class constructor.
passwordMaster::passwordMaster()
{

}; // End of the constructor.


// Implementation of the saveAccountDataToFile function.
void fileDataMaster::saveAccountDataToFile(string account_username, string account_master_password)
{
	// Take the username and master password parameters and save them to a file.
	ofstream accountDataFile("adminAccountData.txt");

	// Write the username and master password to the file.
	if (accountDataFile.is_open())
	{	
		// Write in the file.
		accountDataFile << "Admin Account Data:";
		accountDataFile << account_username << endl;
		accountDataFile << account_master_password << endl;

		// Close the file.
		accountDataFile.close();

		// Notify that the data was saved successfully.
		cout << "Account data saved successfully." << endl;

	} // End of if block.

	// Else to handle the error when the file cannot be opened.
	else
	{	
		// Notify that there was an error opening the file.
		cout << "Error: Unable to open file for writing." << endl;

	} // End of else block.


} // End of saveAccountDataToFile function.
