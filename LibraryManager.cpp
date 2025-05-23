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
        cout << "No items in the library." << endl;
        //return;
    }
    for (auto& item: libraryItems) {
        item.second->displayItem();
    }
}