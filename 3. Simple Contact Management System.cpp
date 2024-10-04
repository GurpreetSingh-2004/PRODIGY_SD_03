#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

// Function to load contacts from the file
vector<Contact> loadContacts(const string &filename) {
    vector<Contact> contacts;
    ifstream file(filename);
    
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name, phone, email;
            getline(ss, name, ',');
            getline(ss, phone, ',');
            getline(ss, email, ',');
            contacts.push_back({name, phone, email});
        }
        file.close();
    }
    return contacts;
}

// Function to save contacts to the file
void saveContacts(const string &filename, const vector<Contact> &contacts) {
    ofstream file(filename);
    
    if (file.is_open()) {
        for (const auto &contact : contacts) {
            file << contact.name << "," << contact.phone << "," << contact.email << endl;
        }
        file.close();
    }
}

// Function to add a new contact
void addContact(vector<Contact> &contacts, const string &filename) {
    Contact newContact;
    cout << "Enter contact name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phone);
    cout << "Enter email address: ";
    getline(cin, newContact.email);

    contacts.push_back(newContact);
    saveContacts(filename, contacts);
    cout << "Contact added successfully." << endl;
}

// Function to view all contacts
void viewContacts(const vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts found." << endl;
        return;
    }

    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". Name: " << contacts[i].name
             << ", Phone: " << contacts[i].phone
             << ", Email: " << contacts[i].email << endl;
    }
}

// Function to edit an existing contact
void editContact(vector<Contact> &contacts, const string &filename) {
    viewContacts(contacts);
    
    int index;
    cout << "Enter the number of the contact you want to edit: ";
    cin >> index;
    index--;

    if (index >= 0 && index < contacts.size()) {
        cout << "Enter new name (leave blank to keep current): ";
        cin.ignore();
        string newName;
        getline(cin, newName);
        if (!newName.empty()) contacts[index].name = newName;

        cout << "Enter new phone number (leave blank to keep current): ";
        string newPhone;
        getline(cin, newPhone);
        if (!newPhone.empty()) contacts[index].phone = newPhone;

        cout << "Enter new email (leave blank to keep current): ";
        string newEmail;
        getline(cin, newEmail);
        if (!newEmail.empty()) contacts[index].email = newEmail;

        saveContacts(filename, contacts);
        cout << "Contact updated successfully." << endl;
    } else {
        cout << "Invalid contact number." << endl;
    }
}

// Function to delete a contact
void deleteContact(vector<Contact> &contacts, const string &filename) {
    viewContacts(contacts);
    
    int index;
    cout << "Enter the number of the contact you want to delete: ";
    cin >> index;
    index--;

    if (index >= 0 && index < contacts.size()) {
        contacts.erase(contacts.begin() + index);
        saveContacts(filename, contacts);
        cout << "Contact deleted successfully." << endl;
    } else {
        cout << "Invalid contact number." << endl;
    }
}

// Main menu for the contact manager
int main() {
    const string filename = "contacts.txt";
    vector<Contact> contacts = loadContacts(filename);

    while (true) {
        cout << "\nContact Manager" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts, filename);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                editContact(contacts, filename);
                break;
            case 4:
                deleteContact(contacts, filename);
                break;
            case 5:
                cout << "Exiting the Contact Manager." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
