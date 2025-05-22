#include "LibraryItem.h" // include the corresponding header file
#include <iostream>
#include <string>
using namespace std;

LibraryItem::LibraryItem() : title(""), author(""), id(0), isBorrowed(false) { }

LibraryItem::LibraryItem(LibraryItem& item) {
    title = item.title;
    author = item.author;
    id = item.id;
    isBorrowed = item.isBorrowed;
}

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

void LibraryItem::displayItem() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ID: " << id << endl;
    cout << "Is Borrowed: " << (isBorrowed ? "Yes" : "No") << endl;
}

LibraryItem::~LibraryItem() { }