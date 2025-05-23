/**
 * Base class for library items
 * This class represents a library item with attributes such as title, author, ID, and borrowed status.
 * It provides methods to set and get these attributes, as well as to display the item information.
 * @author Lutho Mboniswa
 * @studentNumber 69428867
 * @date 23 May 2025
 * @version 1.0
 * @note This class is intended to be inherited by specific item types such as Book and Magazine. 
 */

#include "LibraryItem.h" // include the corresponding header file
#include <iostream>
#include <string>
using namespace std;

LibraryItem::LibraryItem() : title(""), author(""), id(0), isBorrowed(false) { } // default constructor

// Copy constructor
// This constructor initializes a LibraryItem object using another LibraryItem object
LibraryItem::LibraryItem(LibraryItem& item) { 
    title = item.title;
    author = item.author;
    id = item.id;
    isBorrowed = item.isBorrowed;
}

// Constructor with parameters
LibraryItem::LibraryItem(string title, string author, int id, bool isBorrowed) {
    setLibraryItem(title, author, id, isBorrowed);
}

// Setters
void LibraryItem::setLibraryItem(string itemTitle, string itemAuthor, int itemId, bool itemIsBorrowed) {
    title = itemTitle;
    author = itemAuthor;
    id = itemId;
    isBorrowed = itemIsBorrowed;
}

void LibraryItem::setTitle(string itemTitle) {
    title = itemTitle;
}

void LibraryItem::setAuthor(string itemAuthor) {
    author = itemAuthor;
}

void LibraryItem::setId(int itemId) {
    id = itemId;
}

void LibraryItem::setIsBorrowed(bool itemIsBorrowed) {
    isBorrowed = itemIsBorrowed;
}

void LibraryItem::setLibraryItem(LibraryItem& item) {
    title = item.title;
    author = item.author;
    id = item.id;
    isBorrowed = item.isBorrowed;
}

// Getters
string LibraryItem::getTitle() {
    return title;
}

string LibraryItem::getAuthor() {
    return author;
}

int LibraryItem::getId() {
    return id;
}

bool LibraryItem::getIsBorrowed() {
    return isBorrowed;
}

const LibraryItem& LibraryItem::getLibraryItem() {
    return *this;
}

LibraryItem LibraryItem::getLibraryItem(LibraryItem& item) {
    return LibraryItem(item);
}

// Display item information
void LibraryItem::displayItem() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ID: " << id << endl;
    cout << "Is Borrowed: " << (isBorrowed ? "Yes" : "No") << endl;
}

// Destructor
// This destructor is virtual to ensure proper cleanup of derived classes
LibraryItem::~LibraryItem() { }