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
passwordMaster::passwordMaster()
{   
	// Set the filename for storing password data.
    allStoredDataFilename = "allStoredData.txt";

    // Seed the random number generator so IDs are different every time
    srand(time(0));

} // End of the constructor.

// Helper: Loads data from text file into the 'allStoredPasswords' vector
void passwordMaster::loadPasswords()
{   
	// Clear existing data.
    allStoredPasswords.clear();

	// Open the file for reading.
    ifstream file(allStoredDataFilename);

	// Read each entry from the file.
    if (file.is_open())
    {   
		// Temporary entry to hold data while reading.
        PasswordEntry entry;

        // Read ID, Site, and Password until end of file
        while (file >> entry.id >> entry.siteName >> entry.sitePassword)
        {   
			// Add the entry to the vector.
            allStoredPasswords.push_back(entry);

		} // End of while loop.

		// Close the file.
        file.close();

	} // End of if block.

} // End of loadPasswords function.


// Helper: Saves the current 'allStoredPasswords' vector to the text file
void passwordMaster::savePasswords()
{   
	// Open the file for writing.
    ofstream file(allStoredDataFilename);

	// Write each entry to the file.
    if (file.is_open())
    {   
		// Write each password entry to the file
        for (const auto& entry : allStoredPasswords)
        {   
			// Write ID, Site, and Password
            file << entry.id << " " << entry.siteName << " " << entry.sitePassword << endl;

		} // End of for loop.

		// Close the file.
        file.close();
    
	} // End of if block.

} // End of savePasswords function.


// 1. Add: Ask user for details, generate ID, save.
void passwordMaster::addPassword()
{
    // Ensure we have the latest data.
    loadPasswords();

	// Get new password details from user.
    PasswordEntry newEntry;

	// Prompt the user for site name and password.
    cout << "\n--- Add New Password ---\n";
    cout << "Enter Site Name: ";

	// Read site name (no spaces).
    cin >> newEntry.siteName;

    cout << "Enter Password: ";
    
    // Read site password (no spaces).
    cin >> newEntry.sitePassword;

    // Generate a random 4-digit ID (1000 to 9999)
    newEntry.id = rand() % 9000 + 1000;

	// Add the new entry to the vector and save to file.
    allStoredPasswords.push_back(newEntry);

	// Save updated data back to file.
    savePasswords();

	// Confirm to the user.
    cout << "Password saved successfully! (ID: " << newEntry.id << ")\n";

} // End of addPassword function.

// 2. View: Display all passwords in a table.
void passwordMaster::viewPasswords()
{   
	// Ensure we have the latest data.
    loadPasswords();

	// Display all stored passwords.
    cout << "\n--- All Saved Passwords ---\n";

	// Check if there are any passwords stored.
    if (allStoredPasswords.empty())
    {   
		// Display message if no passwords are found.
        cout << "No passwords stored yet.\n";

		// Exit the function early.
        return;
    
	} // End of if block.

	// Display table header.
    cout << "ID\tSite Name\tPassword\n";
    cout << "----------------------------------------\n";

	// Display each password entry.
    for (const auto& entry : allStoredPasswords)
    {   
		// Display ID, Site Name, and Password
        cout << entry.id << "\t" << entry.siteName << "\t\t" << entry.sitePassword << endl;

	} // End of for loop.

} // End of viewPasswords function.

// 3. Edit: Find by ID, update details, save.
void passwordMaster::editPassword()
{   
	// Ensure we have the latest data.
    loadPasswords();

	// Variable to hold the target ID.
    int targetID;

	// Prompt user for the ID to edit.
    cout << "\nEnter ID of password to edit: ";
    
    // Read the user input.
    cin >> targetID;

	// Flag to track if we found the ID.
    bool found = false;

    // Reference (&) allows us to modify the actual entry in the vector
    for (auto& entry : allStoredPasswords)
    {   
		// Check for matching ID
        if (entry.id == targetID)
        {   
			// Mark as found.
            found = true;

			// Display current details.
            cout << "Current: " << entry.siteName << " (" << entry.sitePassword << ")\n";

			// Confirm edit action variable.
            char confirm;

			// Prompt for confirmation.
            cout << "Edit this entry? (y/n): ";

			// Read user confirmation.
            cin >> confirm;

			// If confirmed, get new details.
            if (confirm == 'y' || confirm == 'Y')
            {   
				// Get new site name and password.
                cout << "Enter New Site Name: ";

				// Read new site name (no spaces).
                cin >> entry.siteName;

				// Get new password.
                cout << "Enter New Password: ";

				// Read new site password (no spaces).
                cin >> entry.sitePassword;

				// Save updated data back to file.
                savePasswords();

				// Confirm to the user.
                cout << "Entry updated successfully.\n";

			} // End of if block.

			// If not confirmed, cancel edit.
            else
            {   
				// Edit cancelled message.
                cout << "Edit cancelled.\n";
            
			} // End of else block.
            
			// Exit loop after finding the entry
            break;

		} // End of if block.

	} // End of for loop.

	// If ID was not found, inform the user.
    if (!found) cout << "ID not found.\n";

} // End of editPassword function.


// 4. Delete: Find by ID, remove, save.
void passwordMaster::deletePassword()
{   
	// Ensure we have the latest data.
    loadPasswords();

	// Variable to hold the target ID.
    int targetID;

	// Prompt user for the ID to delete.
    cout << "\nEnter ID of password to delete: ";

	// Read the user input.
    cin >> targetID;

	// Flag to track if we found the ID.
    bool found = false;

    // Iterate using an iterator so we can erase efficiently
    for (auto it = allStoredPasswords.begin(); it != allStoredPasswords.end(); ++it)
    {   
		// Check for matching ID
        if (it->id == targetID)
        {   
			// Mark as found.
            found = true;

			// Display entry to be deleted.
            cout << "Deleting: " << it->siteName << "\n";

			// Confirm delete action variable.
            char confirm;

			// Prompt for confirmation.
            cout << "Are you sure? (y/n): ";

			// Read user confirmation.
            cin >> confirm;

			// If confirmed, delete the entry.
            if (confirm == 'y' || confirm == 'Y')
            {   
				// Erase the entry from the vector.
                allStoredPasswords.erase(it);

				// Save updated data back to file.
                savePasswords();

				// Display success message.
                cout << "Entry deleted successfully.\n";

			} // End of if block.

			// If not confirmed, cancel delete.
            else
            {   
				// Delete cancelled message.
                cout << "Delete cancelled.\n";

			} // End of else block.

			// Exit loop after processing the entry
            break;

		} // End of if block.

	} // End of for loop.

	// If ID was not found, inform the user.
    if (!found) cout << "ID not found.\n";

} // End of deletePassword function.


