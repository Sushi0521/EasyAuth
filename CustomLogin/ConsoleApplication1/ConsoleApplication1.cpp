#include <iostream>
#include "config.h"      // Include config.h for the console size and credentials
#include "timezone.h"    // Include timezone.h for date expiration check
#include "dunkeloderhell.h"

// Initialize the login allowed flag
bool isLoginAllowed = true;


int main() {
    // Check if the current date has expired (greater than February 20, 2025)
    checkLoginAvailability();  // This will prevent login if the date is expired

    // If the date has expired, isLoginAllowed will be false and login won't proceed
    if (!isLoginAllowed) {
        // The date has expired, so we don't proceed with the login or any other operations
        return 0;  // End the program early
    }

  

    // Set the console window size to 1/8th of the screen resolution (if applicable)
    setConsoleWindowSize();

    // Check if credentials are already saved in the ini file
    std::string username, password;
    if (loadCredentialsFromIni(username, password)) {
        std::cout << "Auto-login successful!" << std::endl;
        std::cout << "Welcome back, " << username << std::endl;
    }
    else {
        // If no saved credentials, prompt the user to enter them
        std::cout << "Enter your username: ";
        std::cin >> username;

        std::cout << "Enter your password: ";
        std::cin >> password;

        // Save the new credentials to the ini file
        saveCredentialsToIni(username, password);
        std::cout << "New credentials saved!" << std::endl;
    }

    // Call the main menu after successful login
    showMainMenu();

    return 0;
}