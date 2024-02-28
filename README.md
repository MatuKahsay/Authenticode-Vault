# Authenticode Vault
This Security System application is a simple console-based program designed to manage user authentication, including registration, login, and password changes. It leverages a combination of C++ standard libraries and the JSON for Modern C++ library for user data management and storage. This document provides a comprehensive guide to help users understand and navigate the application.
Features

    User Registration: Allows new users to create an account by entering a username and a password that meets specific requirements.
    User Login: Enables existing users to log in by verifying their credentials.
    Password Change: Allows users to change their passwords after providing their current password for authentication.
    Data Persistence: User credentials are stored in a JSON file, ensuring data persistence across application restarts.

Requirements

To compile and run this application, you will need:

    A C++ compiler that supports C++11 or later (e.g., GCC, Clang, MSVC).
    The JSON for Modern C++ library, which can be found at https://github.com/nlohmann/json. Ensure this library is accessible to your compiler.

Compilation and Execution

Compile the Program: Use your C++ compiler to compile the application. The command may vary depending on your compiler and setup. An example command for GCC is:


    g++ -std=c++11 -o SecuritySystem SecuritySystem.cpp

Run the Program: After compilation, you can run the program using:



    ./SecuritySystem

Usage Instructions

Upon running the application, you will be presented with a menu offering four options:

    Register: Select this option to create a new user account. You will be prompted to enter a username and a password. Note that usernames must be unique, and passwords must meet the complexity requirements outlined below.
    Login: Select this option to log in with an existing user account. You will need to provide your username and password.
    Change Password: After logging in, you can choose this option to change your password. You must provide your current password for verification before entering a new one.
    End Program: Select this option to exit the application. All user data is saved to a file named users.json, ensuring that user credentials persist for future sessions.

Password Complexity Requirements

To ensure account security, passwords must meet the following criteria:

    At least 8 characters long
    Contains at least one digit (0-9)
    Contains at least one lowercase letter (a-z)
    Contains at least one uppercase letter (A-Z)
    Contains at least one special character (e.g., !@#$%^&*)

Data Storage

User credentials are stored in a JSON file named users.json in the application's directory. This file is automatically created upon the first user registration and updated with each subsequent registration, login, or password change. The file structure is simple, with usernames as keys and their corresponding hashed passwords as values.
Security Considerations

This application uses a simple hashing function for demonstration purposes. In a real-world scenario, it is recommended to use a secure hashing algorithm (e.g., bcrypt, Argon2) and to implement additional security measures such as salted hashes to protect against dictionary and rainbow table attacks.
License

This application is provided as-is, without warranty of any kind. You are free to use, modify, and distribute it as you see fit, subject to any restrictions imposed by the JSON for Modern C++ library's license.
Contributing

Contributions to the application are welcome. Please feel free to fork the repository, make improvements, and submit pull requests.
