# Version 1: How the Application Works
I have written many comments to help new developers understand how the application works, but I will also provide a short guide in this description.

# Main.cpp
This file is primarily used to initialize the application with your .ini file, which is created after launch. The .ini file holds the following information:

- Username
- Password
- Desktop Width
- Desktop Height

These settings are used for auto-login and to resize the application. This file is also used for the main login process, where standard C input is used to retrieve your username and password. After a successful login, the main menu will be displayed.

# Config.h
This is a customizable main interface that allows the user to interact with the application, reusing our standard input method. You can add your own functions here. This file is also where the main .ini file is created and where the application is initialized. Additionally, we use this file to detect the user's desktop size and adjust the .ini file size if necessary (in case the application has been moved or the .ini file is incorrect).

# TimeZone.h
This file has one primary purpose: to check whether the user is attempting to use the application past its due date. If the date in the .ini file is not equal to the current Windows time, login is prohibited.
Note: At the moment, changing your Windows date will bypass this restriction. I am working on a fix.

# I will be adding more features soon, including changes to the application signature and the addition of ASM protection.
