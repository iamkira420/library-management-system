#include "Magazine.h"
#include "LibraryItem.h"
#include <iostream>
#include <string>
using namespace std;


Magazine::Magazine() : issueNumber(0) { }

Magazine::Magazine(Magazine& mag, int issueNum) : LibraryItem(mag.getTitle(), mag.getAuthor(), mag.getId(), mag.getIsBorrowed()), issueNumber(issueNum) { }

Magazine::Magazine(string title, string author, int id, bool isBorrowed, int issueNum) :
    LibraryItem(title, author, id, isBorrowed), issueNumber(issueNum) { }

// setters
void Magazine::setId(int magId) {
    if (magId >= 500 && magId <= 999) {
        LibraryItem::setId(magId);
    } else {
        cout << "Invalid magazine ID! Please enter a number between 500 and 999." << endl;
    }
}

void Magazine::setIssueNumber(int issueNum) {
    if (issueNum >= 1000 && issueNum <= 9999) {
        issueNumber = issueNum;
    } else {
        cout << "Invalid issue number! Please enter a number between 1000 and 9999." << endl;
    }
}

int Magazine::getIssueNumber() const {
    return issueNumber;
}

void Magazine::displayItem() {
    LibraryItem::displayItem();
    cout << "Issue Number: " << getIssueNumber() << endl;
}


Magazine::~Magazine() { }