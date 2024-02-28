#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// Function prototypes
void registerUser(unordered_map<string, string>& users);
void loginUser(const unordered_map<string, string>& users);
void changePassword(unordered_map<string, string>& users);
void saveToFile(const unordered_map<string, string>& users);
void loadFromFile(unordered_map<string, string>& users);

int main() {
    int choice;
    unordered_map<string, string> users;

    // Load users from file at the start of the program
    loadFromFile(users);

    do {
        cout << "   Security System  " << endl;
        cout << "____________________________" << endl;
        cout << "|      1. Register         |" << endl;
        cout << "|      2. Login            |" << endl;
        cout << "|      3. Change Password  |" << endl;
        cout << "|      4. End Program      |" << endl;
        cout << "____________________________" << endl;
        cout << "Enter your choice : - ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(users);
                break;
            case 2:
                loginUser(users);
                break;
            case 3:
                changePassword(users);
                break;
            case 4:
                cout << "Thank you for using the Security System!" << endl;
                break;
            default:
                cout << "Enter a valid choice" << endl;
        }
    } while (choice != 4);

    // Save users to file before exiting
    saveToFile(users);

    return 0;
}

// Define the functions declared earlier
