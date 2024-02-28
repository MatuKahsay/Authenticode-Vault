#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <json.hpp> // for json parsing and serialization

using json = nlohmann::json;
using namespace std;

// Simple hash function for demonstration purposes
string hashPassword(const string& password) {
    hash<string> hasher;
    return to_string(hasher(password));
}

void registerUser(unordered_map<string, string>& users) {
    string username, password;
    cout << "Please enter a new username: ";
    cin >> username;
    if (users.find(username) != users.end()) {
        cout << "This username is already taken. Please choose a different one." << endl;
        return;
    }
    cout << "Please enter a new password: ";
    cin >> password;
    users[username] = hashPassword(password);
    cout << "Registration successful!" << endl;
}

void loginUser(const unordered_map<string, string>& users) {
    string username, password;
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;
    auto it = users.find(username);
    if (it != users.end() && it->second == hashPassword(password)) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password." << endl;
    }
}

void changePassword(unordered_map<string, string>& users) {
    string username, oldPassword, newPassword;
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your old password: ";
    cin >> oldPassword;
    auto it = users.find(username);
    if (it != users.end() && it->second == hashPassword(oldPassword)) {
        cout << "Please enter your new password: ";
        cin >> newPassword;
        users[username] = hashPassword(newPassword);
        cout << "Password changed successfully!" << endl;
    } else {
        cout << "Invalid username or old password." << endl;
    }
}

void saveToFile(const unordered_map<string, string>& users) {
    json j;
    for (const auto& pair : users) {
        j[pair.first] = pair.second;
    }
    ofstream file("users.json");
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
    } else {
        cerr << "Error saving to file." << endl;
    }
}

void loadFromFile(unordered_map<string, string>& users) {
    ifstream file("users.json");
    if (file.is_open()) {
        json j;
        file >> j;
        for (auto& element : j.items()) {
            users[element.key()] = element.value();
        }
        file.close();
    } else {
        cerr << "No existing user data found, starting fresh." << endl;
    }
}

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
