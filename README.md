Description of the Contact Management Program
Overview
The Contact Management Program is a simple console-based application designed to help users manage their personal or professional contacts effectively. It allows users to add new contacts, view existing contacts, edit contact details, and delete contacts as needed. The program stores contacts in a file, ensuring data is retained even after the application is closed.

Features
Add Contact:

Users can add a new contact by entering the contact's name, phone number, and email address.
The program validates the input to ensure that it follows a basic format (e.g., phone numbers are numeric).
View Contacts:

Users can view all stored contacts in a neatly formatted list.
Each contact is displayed with their name, phone number, and email address.
Edit Contact:

Users can edit the details of an existing contact by selecting the contact they wish to modify.
The program allows updating any of the contact's information, including name, phone number, and email address.
Delete Contact:

Users can delete a contact from their list by selecting it from the displayed contacts.
The program prompts for confirmation before deleting a contact to prevent accidental deletion.
Persistent Storage:

Contacts are stored in a text file, ensuring that all information is saved between sessions.
The program loads the contacts from the file when it starts and saves any changes made to the contacts back to the file.
Implementation
Data Structure:

Contacts are represented as a structure containing fields for the name, phone number, and email address.
A vector is used to hold all contacts in memory, allowing dynamic addition and removal of contacts.
File Handling:

The program uses file input and output streams to read from and write to a text file (e.g., contacts.txt).
Each line in the file corresponds to a single contact, with fields separated by commas.
User Interface:

The program operates through a simple command-line interface, presenting a menu to the user with options for each available action.
Users navigate the menu using numeric input.
Example Workflow
Start the Program: The user runs the application, which loads existing contacts from the contacts.txt file.
Add a New Contact:
The user selects the option to add a contact.
They input the name, phone number, and email address when prompted.
View Contacts: The user chooses to view all contacts and sees a list of stored contacts.
Edit a Contact:
The user selects a contact to edit.
They change the desired information and save the changes.
Delete a Contact: The user selects a contact to delete and confirms the deletion.
Exit the Program: When finished, the user exits the program, which saves all changes to the contacts file.
