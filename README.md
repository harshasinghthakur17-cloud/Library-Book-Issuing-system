Library Book Issuing System (C Language)

This project is a menu driven Library Book Issuing System written in the C programming language.
It helps manage library books by allowing the user to add books, issue books to students, return
books, and calculate fines for late returns.

--------------------------------------------------

Features

Add new books with title and author name
Prevent duplicate book entries
Display all books with their current status
Issue books to students using student ID
Store issue and return dates
Calculate fine for late returns

--------------------------------------------------

Data Structures Used

A structure named Book is used to store book title, author name, issue status, student ID,
issue date, and return date.
An array of structures is used to store details of up to 100 books.

--------------------------------------------------

Working of the Program

The program runs in a loop and displays a menu until the user exits.
Each book is uniquely identified using its title and author name.
While issuing a book, the program checks whether the book exists and whether it is already issued.
When returning a book, the total number of days is calculated.
If the book is returned after 7 days, a fine is calculated and displayed.

--------------------------------------------------

Fine Calculation Logic

Allowed borrowing period is 7 days.
Fine is charged at Rs 5 per extra day.
Fine formula:
Fine = (Total Days - 7) * 5

--------------------------------------------------

Functions Used

addbook() is used to add a new book to the library.
displaybook() is used to display all books and their status.
issuebook() is used to issue a book to a student.
returnbook() is used to return a book and calculate fine.
findbookindex() is used to search a book using title and author name.
isduplicatebook() is used to prevent duplicate book entries.

--------------------------------------------------

How to Compile and Run

Windows (GCC / MinGW)

gcc library.c -o library
library

Linux / macOS

gcc library.c -o library
./library

--------------------------------------------------

Sample Menu Output

===== LIBRARY BOOK ISSUING SYSTEM =====
1. Add New Book
2. Display All Books
3. Issue a Book
4. Return a Book
5. Exit

--------------------------------------------------

Limitations

Book titles and author names should not contain spaces.
Date calculation is approximate.
Data is not stored permanently as file handling is not used.

--------------------------------------------------

Future Enhancements

File handling can be added for permanent storage.
Spaces can be allowed in book titles and author names.
Date calculation can be improved.
Student names can be stored instead of IDs.

--------------------------------------------------

Language Used

C Programming Language

--------------------------------------------------

Project Type

Console based academic project

