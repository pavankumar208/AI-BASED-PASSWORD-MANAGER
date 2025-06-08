#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Structure to store a credential
struct Credential {
    string username;
    string password;
};

// XOR Encryption/Decryption (conceptual)
string xorEncryptDecrypt(const string& data, const string& key) {
    string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key[i % key.size()];
    }
    return result;
}

// Function to add a new credential
void addCredential(vector<Credential>& credentials, const string& masterKey) {
    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    // Encrypt before storing
    string encryptedUser = xorEncryptDecrypt(username, masterKey);
    string encryptedPass = xorEncryptDecrypt(password, masterKey);

    credentials.push_back({encryptedUser, encryptedPass});

    cout << "\n✅ Credential saved successfully!\n";
    cout << "Stored Credential:\n";
    cout << "Username: " << username << "\n";
    cout << "Password: " << password << "\n";
}

// Function to view all stored credentials
void viewCredentials(const vector<Credential>& credentials, const string& masterKey) {
    if (credentials.empty()) {
        cout << "\nNo credentials stored yet.\n";
        return;
    }

    cout << "\n🔐 Stored Credentials:\n";
    for (const auto& cred : credentials) {
        string decryptedUser = xorEncryptDecrypt(cred.username, masterKey);
        string decryptedPass = xorEncryptDecrypt(cred.password, masterKey);
        cout << "--------------------------\n";
        cout << "Username: " << decryptedUser << "\n";
        cout << "Password: " << decryptedPass << "\n";
    }
    cout << "--------------------------\n";
}

// Menu display
void displayMenu() {
    cout << "\n===== Secure Password Manager =====\n";
    cout << "1. Add Credential\n";
    cout << "2. View All Credentials\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    const string correctMasterPassword = "admin123";
    string enteredPassword;
    vector<Credential> credentials;

    cout << "Enter Master Password to unlock: ";
    getline(cin, enteredPassword);

    if (enteredPassword != correctMasterPassword) {
        cerr << "❌ Access Denied. Incorrect password.\n";
        return 1;
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline

        switch (choice) {
            case 1:
                addCredential(credentials, enteredPassword);
                break;
            case 2:
                viewCredentials(credentials, enteredPassword);
                break;
            case 3:
                cout << "🔒 Exiting Secure Password Manager. Goodbye!\n";
                break;
            default:
                cout << "⚠️ Invalid option. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
