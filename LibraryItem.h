#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>
using namespace std;

class LibraryItem {
    private:
        string title;
        string author;
        int id;
        bool isBorrowed;

    public:
        LibraryItem();
        LibraryItem(LibraryItem&);
        LibraryItem(string, string, int, bool);
        void setLibraryItem(string, string, int, bool);
        void setTitle(string);
        void setAuthor(string);
        virtual void setId(int);
        void setIsBorrowed(bool);
        void setLibraryItem(LibraryItem&);
        string getTitle();
        string getAuthor();
        int getId();
        bool getIsBorrowed();
        const LibraryItem& getLibraryItem();
        LibraryItem getLibraryItem(LibraryItem&);
        virtual void displayItem();
        virtual ~LibraryItem(); // virtual destructor

};

#endif // LIBRARYITEM_H