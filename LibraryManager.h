#include <unordered_map>
#include <string>
#include <iostream>
#include "LibraryItem.h"
using namespace std;

class LibraryManager {
    private:
        unordered_map<int, LibraryItem*> libraryItems;
    public:
        //void loadData(const string& filename);
        //void saveData(const string& filename);
        void addBook();
        void addMagazine();
        bool borrowItem(int);
        bool returnItem(int);
        void displayAllItems();
        void searchById(int);
        LibraryItem* findItemById(int id);
        void loadDataFromFile(const string& filename);
};

