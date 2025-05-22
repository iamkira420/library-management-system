#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
using namespace std;

#include "LibraryItem.h"

class Book : public LibraryItem {
    private:
        string genre;


    public:
        Book();
        Book(Book&, string);
        Book (string, string, int, bool, string);
        void setGenre(string);
        string getGenre() const;
        void displayItem() override;
        ~Book();
};

#endif // BOOK_H