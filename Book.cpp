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
void Book::setId(int bookId) {
    if (bookId >= 100 && bookId <= 499) {
        LibraryItem::setId(bookId);
    } else {
        cout << "Invalid book ID! Please enter a number between 100 and 499." << endl;
    }
}

void Book::setGenre(string bookGenre) {
    genre = bookGenre;
}

string Book::getGenre() const {
    return genre;
}

void Book::displayItem() {
    LibraryItem::displayItem();
    cout << "Genre: " << genre << endl;
}


Book::~Book() { }