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

To run the executable: 
```
./library
```

