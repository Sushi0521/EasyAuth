#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "timezone.h"

// Function to retrieve the screen resolution (width and height)
void getScreenResolution(int& width, int& height) {
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    width = desktop.right;
    height = desktop.bottom;
}

// Function to set the console window size to 1/8th of the screen resolution
void setConsoleWindowSize() {
    int screenWidth, screenHeight;
    getScreenResolution(screenWidth, screenHeight);

    int consoleWidth = screenWidth / 4;
    int consoleHeight = screenHeight / 4;

    HWND console = GetConsoleWindow();
    MoveWindow(console, 0, 0, consoleWidth, consoleHeight, TRUE);
}

// Function to create and save credentials (username and password) to a .ini file
void saveCredentialsToIni(const std::string& username, const std::string& password) {
    std::ofstream iniFile("credentials.ini");

    if (iniFile.is_open()) {
        iniFile << "[Credentials]\n";
        iniFile << "Username=" << username << "\n";
        iniFile << "Password=" << password << "\n";
        iniFile.close();
        std::cout << "Credentials saved to 'credentials.ini'." << std::endl;
    }
    else {
        std::cerr << "Error opening 'credentials.ini' for writing." << std::endl;
    }
}

// Function to load credentials from the .ini file
bool loadCredentialsFromIni(std::string& username, std::string& password) {
    std::ifstream iniFile("credentials.ini");

    if (iniFile.is_open()) {
        std::string line;
        bool foundCredentials = false;

        while (getline(iniFile, line)) {
            if (line.find("Username=") != std::string::npos) {
                username = line.substr(9);
                foundCredentials = true;
            }
            if (line.find("Password=") != std::string::npos) {
                password = line.substr(9);
            }
        }

        iniFile.close();
        return foundCredentials;
    }
    else {
        std::cerr << "Error reading 'credentials.ini'." << std::endl;
        return false;
    }
}

// Function to show the main menu after login
void showMainMenu() {
    int choice;
    while (true) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Perform an action\n";
        std::cout << "2. Log out\n";
        std::cout << "3. Exit application\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "You can perform any action here.\n";
        }
        else if (choice == 2) {
            std::cout << "Logging out...\n";
            break;  // Break out of the loop to return to login screen
        }
        else if (choice == 3) {
            std::cout << "Exiting application.\n";
            exit(0);  // Exit the program completely
        }
        else {
            std::cout << "Invalid choice! Please select a valid option.\n";
        }
    }
}

#endif // CONFIG_H