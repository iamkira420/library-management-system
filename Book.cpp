/**
 * Book class implementation
 * This class represents a book in the library system.
 * It inherits from the LibraryItem class and adds a genre attribute.
 * The class provides methods to set and get the genre, as well as to display the book information.
 * @author Lutho Mboniswa
 * @studentNumber 69428867
 * @date 23 May 2025
 * @version 1.0
 * @note This class is intended to be used in conjunction with the LibraryManager class to manage library items.
 */

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
// This method sets the ID of the book. Overrides the setId method from the LibraryItem base class.
// It checks if the ID is within the valid range (100 - 499) before setting it.
// If the ID is invalid, it prints an error message.
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