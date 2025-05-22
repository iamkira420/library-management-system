#include <stdio.h>
#include <iostream>
#include <string>
#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << "This is the start of the Library Management System" << endl;

    Book* myItem = new Book();
    myItem->setAuthor("BK201");
    myItem->setTitle("Library Management System");
    myItem->setId(2036);
    myItem->setIsBorrowed(true);
    myItem->setGenre("Seinen");
    myItem->displayItem();
    cout << "What is the genre: ";
    cout << myItem->getGenre() << endl;

    delete myItem;
    return 0;
}
