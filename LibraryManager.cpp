#include "LibraryManager.h"
#include "Book.h"
#include "Magazine.h"
#include "LibraryItem.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>


LibraryManager::LibraryManager() {}


// add books to the library
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
    cout << "Enter book id: ";
    cin >> id;
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
    cout << "Book added successfully!" << endl;
}
// add magazines to the library
void LibraryManager::addMagazine() {
    string title, author;
    bool isBorrowed;
    int id, issueNumber;

    cout << "Enter magazine title: ";
    getline(cin, title);
    cout << "Enter magazine publisher (author): ";
    getline(cin, author);
    cout << "Enter magazine id: ";
    cin >> id;
    cout << "Enter magazine issue number: ";
    cin >> issueNumber;
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
    cout << "Magazine added successfully!" << endl;
}


// search for a book or magazine by id
void LibraryManager::searchById(int id) {
    auto iterator = libraryItems.find(id);

    if (iterator != libraryItems.end()) {
        iterator->second->displayItem();
    } else {
        cout << "Item not found, please try again!" << endl;
    }
}

// display all items in the library
void LibraryManager::displayAllItems() {
    if (libraryItems.empty()) {
        cout << "Currently no items in the library. Please add items and try again!" << endl;
        //return;
    }
    for (auto& item: libraryItems) {
        item.second->displayItem();
    }
}

// boorrowing a book/magazine given its id
bool LibraryManager::borrowItem(int id) {
    if (libraryItems.find(id) != libraryItems.end()) {
        if (libraryItems[id]->getIsBorrowed()) {
            cout << "Item is already borrowed! Please return later!" << endl;
            return false;
        } else {
            libraryItems[id]->setIsBorrowed(true);
            cout << "Item borrowed successfully! Please do return it on time!" << endl;
            return true;
        }
    } else {
        cout << "Item not found! Please try again!" << endl;
        return false;
    }
}

bool LibraryManager::returnItem(int id) {
    if (libraryItems.find(id) != libraryItems.end()) {
        if (!libraryItems[id]->getIsBorrowed()) { // if isBorrowed is false
            cout << "Item is not borrowed! Please borrow it first!" << endl;
            return false;
        } else {
            libraryItems[id]->setIsBorrowed(false);
            cout << "Item returned successfully! Thank you!" << endl;
            return true;
        }
    } else {
        cout << "Item not found! Please try again!" << endl;
        return false;
    }
}

// load data into the library (map) from the text file
void LibraryManager::loadDataFromFile(const string& filename) {
    Book* book = new Book();
    Magazine* magazine = new Magazine();
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
    cout << "Data loaded successfully!" << endl;
}