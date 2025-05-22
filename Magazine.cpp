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
void Magazine::setIssueNumber(int issueNum) {
    issueNumber = issueNum;
}

int Magazine::getIssueNumber() const {
    return issueNumber;
}

void Magazine::displayItem() {
    cout << "Title: " << getTitle() << endl;
    cout << "Author: " << getAuthor() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Is Borrowed: " << (getIsBorrowed() ? "Yes" : "No") << endl;
    cout << "Issue Number: " << getIssueNumber() << endl;
}


Magazine::~Magazine() { }