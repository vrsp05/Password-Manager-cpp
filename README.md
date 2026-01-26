# Password Manager

A console-based C++ password manager application that provides secure storage and management of passwords. This application features a master account authentication system and full CRUD (Create, Read, Update, Delete) functionality for password entries. All data is persisted using text files for simplicity and portability.

## Features

- **Master Account System**: Secure login with username and password (no spaces allowed).
- **Account Creation**: First-time setup creates a master account.
- **Login Authentication**: Maximum 3 login attempts before program exits.
- **Add Passwords**: Store passwords with site names (supports spaces).
- **View Passwords**: Display all stored passwords in a formatted table.
- **Edit Passwords**: Update existing password entries by ID.
- **Delete Passwords**: Remove password entries with confirmation.
- **Input Validation**: Robust error handling for all user inputs.
- **Unique ID Generation**: Automatic 4-digit ID assignment with duplicate prevention.

## Instructions for Build and Use

### Steps to build and/or run the software:

1. **Clone the repository**: git clone https://github.com/vrsp05/Password-Manager-cpp.git cd Password-Manager-cpp

2. **Open the project in Visual Studio**:
- Navigate to the project directory.
- Open `Password Manager.sln`.

3. **Build the project**:
- Select **Build > Build Solution** (or press `Ctrl+Shift+B`).
- Ensure the build configuration is set to **Debug** or **Release**.

4. **Run the application**:
- Press`Ctrl+F5` to run without debugging, or `F5` to run with debugging.

### Instructions for using the software:

YouTube Demo available [here](https://youtu.be/vUFVAjBw8Dk).

1. **First Launch - Account Creation**:
- When no master account exists, you'll be prompted to create one.
- Enter a username.
- Enter a master password.
- Account credentials aresaved to `adminAccountData.txt`.

2. **Login**:
- Enter your username and password.
- You have 3 attempts before the program exits.
- Successful login takes you to the main menu.

3. **Main Menu Options**:
- **Option 1 - Add Password**: Enter site name and password.
- **Option 2 - View All Passwords**:Displays all saved passwords with IDs.
- **Option 3 - Edit Password**: Enter password ID to modify site name and password.
- **Option 4 - Delete Password**: Enter password ID to remove an entry.
- **Option 5 - Exit Program**: Safely exit the application.

4. **Tips**:
- Write down your password IDs when adding entries.
- Use the View option to see all stored password IDs.
- All password data is stored in `allStoredData.txt`.

## Development Environment

To recreate the development environment, you need the following software and/or libraries with the specified versions:

* **Visual Studio 2022** (or later) with C++ Desktop Development workload.
* **C++14 Standard** (minimum) - Project is configured to compile with C++14.
* **Windows OS** - Developed and tested on Windows.
* **Standard C++ Libraries**:
- `<iostream>` - Input/output operations.
- `<fstream>` - File operations.
- `<string>` - String handling.
- `<vector>` - Dynamic arrays for password storage.
- `<cstdlib>` - Random number generation.
- `<ctime>` - Time functions for seeding random numbers.

## File Structure
Password-Manager-cpp/

├── Password Manager.cpp # Main entry point and program flow

├── accountManager.h/.cpp # Account creation and login functionality

├── menusManager.h/.cpp # Menu display and input validation

├── passwordMaster.h/.cpp # Password CRUD operations

├── adminAccountData.txt # Stores master account credentials (auto-generated)

├── allStoredData.txt # Stores all password entries (auto-generated)


## Code Architecture

The application follows an object-oriented design with three main classes:

- **`accountManager`**: Handles master account creation, login, and authentication.
- **`menusManager`**: Manages menu displays and validates user input.
- **`passwordMaster`**: Manages password storage, retrieval, editing, and deletion.

## Security Notes

⚠️ **Important**: This is an educational project. The following security limitations exist:

- Passwords are stored in **plain text** in local files.
- No encryption is implemented.
- Not suitable for storing real, sensitive passwords.
- Recommended for learning purposes only.

## Useful Websites to Learn More

I found these websites useful in developing this software:

* [C++ File I/O Documentation](https://cplusplus.com/doc/tutorial/files/) - Essential for understanding file operations
* [C++ Vector Container](https://cplusplus.com/reference/vector/vector/) - Used for dynamic password storage
* [C++ Exception Handling](https://cplusplus.com/doc/tutorial/exceptions/) - Implemented for input validation with stoi()
* [Microsoft C++ Documentation](https://learn.microsoft.com/en-us/cpp/) - Visual Studio C++ reference
* [Git and GitHub Guides](https://docs.github.com/en) - Version control best practices
* [W3 Schools](https://www.w3schools.com/cpp/) - Quick syntax definitions.
* [C++ by The Chermo](https://youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&si=Q-vPeTrGlQBrJeFO) - Tutorials for a more relaxed learning.

## Future Work

The following items I plan to fix, improve, and/or add to this project in the future:

* [ ] **Password Encryption**: Implement encryption (AES-256) for secure password storage
* [ ] **Password Strength Validator**: Add checks for password complexity requirements
* [ ] **Password Generator**: Auto-generate secure random passwords
* [ ] **Search Functionality**: Search passwords by site name or partial match
* [ ] **Category/Tags System**: Organize passwords by categories (Social Media, Banking, etc.)
* [ ] **Export/Import Feature**: Backup and restore password data
* [ ] **Password History**: Track changes to passwords over time
* [ ] **Auto-Lock Feature**: Automatically log out after period of inactivity
* [ ] **Master Password Change**: Allow users to update their master password
* [ ] **Multi-User Support**: Support multiple user accounts with separate password vaults
* [ ] **GUI Version**: Create a graphical user interface using Qt or similar framework

## License

This project is created for educational purposes as part of CSE 310 coursework.

## Author

Victor Santana - [GitHub Profile](https://github.com/vrsp05)

---

**Note**: Remember to never store real passwords in this application. Use a production-grade password manager like Bitwarden, 1Password, or KeePass for actual password management.
