#ifndef TIMEZONE_H
#define TIMEZONE_H

#include <iostream>
#include <windows.h>
#include <ctime>

// Flag to check if login is allowed
extern bool isLoginAllowed;

// Function to check if the current system date is greater than February 20, 2025
bool isDateExpired() {
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);  // Get the current system date and time

    // Print current date for debugging purposes (optional)
    std::cout << "Current Date: " << systemTime.wYear << "-" << systemTime.wMonth << "-" << systemTime.wDay << std::endl;

    // Target expiration date: February 20, 2025
    int targetYear = 2025;
    int targetMonth = 2;  // February
    int targetDay = 20;

    // Compare current system date with February 20, 2025
    if (systemTime.wYear > targetYear) {
        return true;  // Expired: Current year is greater than target year
    }
    else if (systemTime.wYear == targetYear) {
        if (systemTime.wMonth > targetMonth) {
            return true;  // Expired: Current month is greater than target month
        }
        else if (systemTime.wMonth == targetMonth) {
            if (systemTime.wDay > targetDay) {
                return true;  // Expired: Current day is greater than target day
            }
        }
    }

    return false;  // If the current date is on or before February 20, 2025
}

// Function to stop login if the date has expired (does not exit, but stops printing)
void checkLoginAvailability() {
    if (isDateExpired()) {
        // If expired, suppress output, don't print login messages
        std::cout << "The application has expired. No further login attempts are allowed." << std::endl;
        std::cout << "Please contact support for assistance." << std::endl;
        isLoginAllowed = false;  // Set login flag to false, preventing login
    }
}

#endif // TIMEZONE_H