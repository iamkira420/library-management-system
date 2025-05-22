#ifndef BOOMAGAZINE_H
#define MAGAZINE_H
#include <string>
#include <iostream>
using namespace std;

#include "LibraryItem.h"

class Magazine : public LibraryItem {
    private:
        int issueNumber;


    public:
        Magazine();
        Magazine(Magazine&, int);
        Magazine (string, string, int, bool, int);
        void setIssueNumber(int);
        int getIssueNumber() const;
        void displayItem() override;
        ~Magazine();
};

#endif // MAGAZINE_H