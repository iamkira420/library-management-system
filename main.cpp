/**
 * Main menu for the library management system.
 * This program allows users to add books and magazines, borrow and return items,
 * search for items by ID, and display all items in the library.
 * The data is loaded from and saved to a text file.
 * @author Lutho Mboniswa
 * @studentNumber 69428867
 * @date 23 May 2025
 * @version 1.0
 * @note My output has a bug that appears after adding a book or magazine. Instead of prompting you for the next action, somehow it gets input which is invalid and proceeds to say invalid input, please try again. 
 *  On the next iteration, it will prompt you for the next action. I have tried to fix this but I am not sure how to do it. I have already ruined my previous codebase trying to fix it so now I just left it as is. 
 *  I will put my github below, in case of a possible solution.
 * @github https://github.com/iamkira420/library-management-system 
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "LibraryItem.h"
#include "LibraryManager.h"
#include "Book.h"
#include "Magazine.h"
#include <limits>
using namespace std;

int main() {
    LibraryManager libManager;
    libManager.loadDataFromFile("library_data.txt"); // load data into the library (map) from the text file

    // start of the main menu loop
    while (true) {
        cout << "\n\t\t\tLibrary Management System Main Menu" << endl;
        cout << "\n1. Add Book";
        cout << "\n2. Add Magazine";
        cout << "\n3. Borrow Item";
        cout << "\n4. Return Item";
        cout << "\n5. Search Item by ID";
        cout << "\n6. Display All Items";
        cout << "\n7. Exit";
        cout << "\nPlease select an option => ";
        int choice;
        cin >> choice; 

        if (cin.fail()) { // Check if the input is valid
            // If not, clear the error state and ignore the rest of the line
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid input! Please enter a number." << endl;
            continue; // Skip to the next iteration of the loop
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //  clears leftover newline after valid input

        switch (choice) {
            case 1:
                libManager.addBook();
                break;
            case 2:
                libManager.addMagazine();
                break;
            case 3: {
                int id;
                cout << "\nEnter the ID of the item to borrow: ";
                cin >> id;
                libManager.borrowItem(id);
                break;
            }
            case 4: {
                int id;
                cout << "\nEnter the ID of the item to return: ";
                cin >> id;
                libManager.returnItem(id);
                break;
            }
            case 5: {
                int id;
                cout << "\nEnter the ID of the item to search: ";
                cin >> id;
                libManager.searchById(id);
                break;
            }
            case 6:
                libManager.displayAllItems();
                break;
            case 7:
                cout << "\nExiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    }
}
