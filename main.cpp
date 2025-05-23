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
    libManager.loadDataFromFile("library_data.txt");

    while (true) {
        cout << "\n\t\t\t\tEspanda Library Main Menu" << endl;
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
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number." << endl;
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
                cout << "Enter the ID of the item to borrow: ";
                cin >> id;
                libManager.borrowItem(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter the ID of the item to return: ";
                cin >> id;
                libManager.returnItem(id);
                break;
            }
            case 5: {
                int id;
                cout << "Enter the ID of the item to search: ";
                cin >> id;
                libManager.searchById(id);
                break;
            }
            case 6:
                libManager.displayAllItems();
                break;
            case 7:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
