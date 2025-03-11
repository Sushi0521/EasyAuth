//#pragma once
//#include <windows.h>
//
//// Function to set console background and text colors
//void setColors(bool isDarkMode) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    if (isDarkMode) {
//        // Dark mode: Black text on White background
//        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//    }
//    else {
//        // Light mode: White text on Black background
//        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//    }
//}
//// Function to set console background and text colors (from dunkeloderhell.h)
//
//
//// Function to set console background and text colors
//void setColors(bool isDarkMode) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    if (isDarkMode) {
//        // Dark mode: White text on Black background
//        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
//    }
//    else {
//        // Light mode: Black text on White background
//        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
//    }
//}
