#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<string, string> users = {
    {"admin", "admin_pass"},
    {"user", "user_pass"}
};

void getUserInput(char *buffer) {
    cout << "Enter input: ";
    cin >> buffer;
}

int main() {
    char username[10];
    char password[10];

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username] == password) {
        cout << "Authentication successful! Welcome " << username << "!\n";

        char buffer[50];

        cout << "Enter a command to execute: ";
        cin.ignore();
        cin.getline(buffer, sizeof(buffer));
        system(buffer);

        cout << "Enter the username whose password you want to view: ";
        char viewUsername[10];
        cin >> viewUsername;

        if (users.find(viewUsername) != users.end()) {
            cout << "Password for " << viewUsername << " is: " << users[viewUsername] << "\n";
        } else {
            cout << "User " << viewUsername << " does not exist!\n";
        }
    } else {
        cout << "Invalid username or password!\n";
    }

    return 0;
}
