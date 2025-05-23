/**
 * This is the brain for the Library Management System. 
 * It manages the library items, including adding, borrowing, returning, and displaying items.
 * It also handles loading and saving data to a file.
 * @author Lutho Mboniswa
 * @studentNumber 69428867
 * @date 23 May 2025
 * @version 1.0
 * @note This class is intended to be used with the LibraryItem, Book, and Magazine classes.
 */

#include "LibraryManager.h"
#include "Book.h"
#include "Magazine.h"
#include "LibraryItem.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <unordered_map>

/*
LibraryManager::LibraryManager() {
    loadDataFromFile("library_data.txt");
}
*/

/**
 * Add a book to the library.
 * Prompts the user for book details such as title, author, genre, ID, and availability.
 * Validates the ID and checks for duplicates before adding the book to the library.
 * Saves the updated library data to a file.
 */
void LibraryManager::addBook() {
    string title, author, genre;
    bool isBorrowed;
    int id;

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter book genre: ";
    getline(cin, genre);

    do { // ensure the user enters the correct ID value
        cout << "Enter book id (100 - 499): ";
        cin >> id;
        if (id < 100 || id > 499) {
            cout << "Invalid book ID! Please enter a number between 100 and 499 inclusive." << endl;
        } else if (libraryItems.count(id) > 0) { // check if the ID already exists
            cout << "Book ID already exists! Please enter a unique ID." << endl;
            id = -1; // reset id to an invalid value to continue the loop
        }

        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    } while (id < 100 || id > 499);

    cout << "Is the book available, i.e., not borrowed? (true for borrowed, false for not borrowed)? ";
    cin >> isBorrowed;
    cin.ignore(); // Clear a newline character from the input buffer

    Book* newBook = new Book();
    newBook->setTitle(title);
    newBook->setAuthor(author);
    newBook->setGenre(genre);
    newBook->setId(id);
    newBook->setIsBorrowed(isBorrowed);
    //newBook->setType("Book");
    
    libraryItems[id] = newBook; // add the book to the library
    cout << "\nBook added successfully!" << endl;
    saveDataToFile("library_data.txt"); // save the updated library data to file
}
/**
 * Add a magazine to the library.
 * Prompts the user for magazine details such as title, author, issue number, ID, and availability.
 * Validates the ID and issue number and checks for duplicates before adding the magazine to the library.
 * Saves the updated library data to a file.
 */
void LibraryManager::addMagazine() {
    string title, author;
    bool isBorrowed;
    int id, issueNumber;

    cout << "Enter magazine title: ";
    getline(cin, title);
    cout << "Enter magazine publisher (author): ";
    getline(cin, author);
    do { // ensure the user enters the correct ID value
        cout << "Enter magazine id (500 - 999): ";
        cin >> id;
        if (id < 500 || id > 999) {
            cout << "Invalid magazine ID! Please enter a number between 500 and 999 inclusive." << endl;
        } else if (libraryItems.count(id) > 0) { // check if the ID already exists
            cout << "Magazine ID already exists! Please enter a unique ID." << endl;
            id = -1; // reset id to an invalid value to continue the loop
        }
    } while (id < 500 || id > 999);

    bool duplicateIssueNum;
    do { // ensure the user enters the correct issue number 
        duplicateIssueNum = false; // tracker for duplicate issue numbers
        cout << "Enter the magazine issue number (1000 - 9999): ";
        cin >> issueNumber;
        if (issueNumber < 1000 || issueNumber > 9999) {
            cout << "Invalid Issue Number! Please enter a number between 1000 and 9999." << endl;
        } else {
            // check if the issue number already exists
            for (const auto& mgzn : libraryItems) {
                Magazine* mag = dynamic_cast<Magazine*>(mgzn.second);
                if (mag && mag->getIssueNumber() == issueNumber) {
                    cout << "That issue number already exists! Please enter a unique issue number." << endl;
                    duplicateIssueNum = true;
                    break;
                }
            }
        }

        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    } while (issueNumber < 1000 || issueNumber > 9999 || duplicateIssueNum);

    cout << "Is the magazine available, i.e., not borrowed? (true for borrowed, false for not borrowed)? ";
    cin >> isBorrowed;
    cin.ignore(); // Clear a newline character from the input buffer

    Magazine* newMagazine = new Magazine();
    newMagazine->setTitle(title);
    newMagazine->setAuthor(author);
    newMagazine->setId(id);
    newMagazine->setIssueNumber(issueNumber);
    newMagazine->setIsBorrowed(isBorrowed);
    //newMagazine->setType("Magazine");
    
    libraryItems[id] = newMagazine; // add the magazine to the library
    cout << "\nMagazine added successfully!" << endl;
    saveDataToFile("library_data.txt"); // save the updated library data to file
}


/**
 * Search for an item in the library by its ID.
 * If the item is found, it displays the item details.
 * If not found, it prompts the user to try again.
 */
void LibraryManager::searchById(int id) {
    auto iterator = libraryItems.find(id);

    if (iterator != libraryItems.end()) {
        cout << endl;
        iterator->second->displayItem();
    } else {
        cout << "\nItem not found, please try again!" << endl;
    }
}

/**
 * Display all items currently in the library.
 */
void LibraryManager::displayAllItems() {
    if (libraryItems.empty()) {
        cout << "\nCurrently no items in the library. Please add items and try again!" << endl;
        //return;
    }
    for (auto& item: libraryItems) {
        item.second->displayItem();
        cout << endl;
    }
}

/**
 * Borrow an item from the library.
 * Checks if the item is already borrowed.
 * If not, it marks the item as borrowed and saves the updated data to a file.
 */
bool LibraryManager::borrowItem(int id) {
    if (libraryItems.find(id) != libraryItems.end()) {
        if (libraryItems[id]->getIsBorrowed()) {
            cout << "\nItem is already borrowed! Please return later!" << endl;
            return false;
        } else {
            libraryItems[id]->setIsBorrowed(true);
            cout << "\nItem borrowed successfully! Please do return it on time!" << endl;
            return true;
        }
    } else {
        cout << "\nItem not found! Please try again!" << endl;
        return false;
    }

    saveDataToFile("library_data.txt"); // save the updated library data to file
}

/**
 * Return an item to the library.
 * Checks if the item is already borrowed.
 * If not, it marks the item as not borrowed and saves the updated data to a file.
 */
bool LibraryManager::returnItem(int id) {
    if (libraryItems.find(id) != libraryItems.end()) {
        if (!libraryItems[id]->getIsBorrowed()) { // if isBorrowed is false
            cout << "\nItem is not borrowed! Please borrow it first!" << endl;
            return false;
        } else {
            libraryItems[id]->setIsBorrowed(false);
            cout << "\nItem returned successfully! Thank you!" << endl;
            return true;
        }
    } else {
        cout << "Item not found! Please try again!" << endl;
        return false;
    }

    saveDataToFile("library_data.txt"); // save the updated library data to file
}

/**
 * Load data from a file into the library.
 * The file should contain information about books and magazines in a specific format documented in the README.txt file.
 */
void LibraryManager::loadDataFromFile(const string& filename) {
    ifstream MyReadfile(filename);
    if (!MyReadfile) {
        cerr << "Error opening file!" << filename << endl;
        return;
    }

    string line; // string to hold each line in the text file
    while (getline(MyReadfile, line)) {
        stringstream ss(line);
        string type;
        getline(ss, type, ','); // read the type of item (Book or Magazine)
        string title, author;
        int id;
        bool isBorrowed;

        if (type == "BOOK") {
            Book* book = new Book(); // create a new book object
            string genre, holder;
            getline(ss, holder, ',');
            id = stoi(holder);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, genre, ',');
            getline(ss, holder);
            isBorrowed = (holder == "true");

            book->setId(id);
            book->setTitle(title);
            book->setAuthor(author);
            book->setGenre(genre);
            book->setIsBorrowed(isBorrowed);
            libraryItems[id] = book; // add the book to the library
        }
        else if (type == "MAGAZINE") {
            Magazine* magazine = new Magazine(); // create a new magazine object
            string holder;
            int issueNumber;
            getline(ss, holder, ',');
            id = stoi(holder);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, holder);
            issueNumber = stoi(holder);
            isBorrowed = (holder == "true");

            magazine->setId(id);
            magazine->setTitle(title);
            magazine->setAuthor(author);
            magazine->setIssueNumber(issueNumber);
            magazine->setIsBorrowed(isBorrowed);
            libraryItems[id] = magazine; // add the magazine to the library
        }
        else {
            cout << "Unknown item type: " << type << endl;
            continue; // skip this line and continue to the next one
        }
    }

    MyReadfile.close(); // close file after use
    cout << "\nData loaded successfully!" << endl;
}

/**
 * Save the current library data to a file.
 * The data is saved in a specific format documented in the README.txt file.
 */
void LibraryManager::saveDataToFile(const string& filename) {
    ofstream MyWriteFile(filename);
    if (!MyWriteFile) {
        cerr << "Error opening file!" << filename << endl;
        return;
    }

    for (const auto& item: libraryItems) {
        LibraryItem* libraryItem = item.second;

        // using dynamic cast to determine the type of item (is it book or magazine?)
        Book* book = dynamic_cast<Book*>(libraryItem);
        if (book) {
            MyWriteFile << "BOOK,"
                        << book->getId() << ","
                        << book->getTitle() << ","
                        << book->getAuthor() << ","
                        << book->getGenre() << ","
                        << (book->getIsBorrowed() ? "true" : "false") 
                        << endl;
            continue;
        }

        Magazine* magazine = dynamic_cast<Magazine*>(libraryItem);
        if (magazine) {
            MyWriteFile << "MAGAZINE,"
                        << magazine->getId() << ","
                        << magazine->getTitle() << ","
                        << magazine->getAuthor() << ","
                        << magazine->getIssueNumber() << ","
                        << (magazine->getIsBorrowed() ? "true" : "false") 
                        << endl;
            continue;
        }
        cout << "Unknown item type!" << endl; // if the item is neither book nor magazine
    }

    MyWriteFile.close(); // close file after use
    // cout << "Library data saved successfully to << " << filename << "!" << endl;
}