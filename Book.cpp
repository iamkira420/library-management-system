#include "Book.h"
#include "LibraryItem.h"
#include <iostream>
#include <string>
using namespace std;


Book::Book() : genre("") { }

Book::Book(Book& book, string gen) : LibraryItem(book.getTitle(), book.getAuthor(), book.getId(), book.getIsBorrowed()), genre(gen) { }

Book::Book(string title, string author, int id, bool isBorrowed, string gen) :
    LibraryItem(title, author, id, isBorrowed), genre(gen) { }

// setters
void Book::setGenre(string bookGenre) {
    genre = bookGenre;
}

string Book::getGenre() const {
    return genre;
}

void Book::displayItem() {
    cout << "Title: " << getTitle() << endl;
    cout << "Author: " << getAuthor() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Is Borrowed: " << (getIsBorrowed() ? "Yes" : "No") << endl;
    cout << "Genre: " << genre << endl;
}


Book::~Book() { }