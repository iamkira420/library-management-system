# COS2614 Assignment - Library Management System
A simple Library Management System implemented using C++. The system allows users to perform basic operations such as adding books, searching for books, borrowing books, and returning books, all via a console interface.

## 📚 Features

- Add books and magazines seperately
- Borrow and return items (books or magazines)
- Search for items by ID
- Display all library items
- Load and save library data items from aand to a text file
- Input validation for ID ranges and duplicate entries

---

## 🛠️ How to Compile

This project uses multiple `.cpp` and `.h` files. To compile using `g++`, run:
```
g++ main.cpp LibraryManager.cpp LibraryItem.cpp Book.cpp Magazine.cpp -o library
```

# How to Run 
```
./library
```
You will see a menu-based interface to interact with the library system. Feast! 

# File Requirements

Make sure the library_data.txt file is present in the same directory. This file stores:
- Book records (IDs from 101–199)
- Magazine records (IDs from 500–999, issue numbers from 1000–9999)

New records and status updates are automatically saved back to this file.

# Sample Data Formar of the data in the File mentioned above

Fornat:
```
<ITEM_TYPE>,<ID>,<TITLE>,<AUTHOR>,<GENRE or ISSUE_NUMBER>,<IS_BORROWED>
```
Sample Data:
```
BOOK,105,The Art of Aura Farming,Piccolo,Animanga,true
MAGAZINE,205,Cyberika,Cyberpunk,1105,false
```

# Project Structure

- main.cpp
- LibraryManager.cpp
- LibraryManager.h
- LibraryItem.cpp
- LibraryItem.cpp
- Book.cpp
- Book.h
- Magazine.cpp
- Magazine.h
- library_data.txt
- library (this file will appear after compilation with g++)

# Author

Lutho Mboniswa | 69428867


