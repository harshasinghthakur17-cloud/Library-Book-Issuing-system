#include <stdio.h>
#include <string.h>

struct Book
{
    char title[50];
    char author[50];
    int issuedornot;
    int issuedtostudent;

    int issue_day;
    int issue_month;
    int issue_year;

    int return_day;
    int return_month;
    int return_year;
};

struct Book library[100];
int bookcount = 0;

void addbook();
void displaybook();
void issuebook();
void returnbook();
int findbookindex(char a[], char b[]);
int isduplicatebook(char a[], char b[]);

int main()
{
    int choice;

    for(int i = 0; i < 100; i++){
        library[i].issuedornot = 0;
        library[i].issuedtostudent = -1;
    }

    while(1)
    {
        printf("\n===== LIBRARY BOOK ISSUING SYSTEM =====\n\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue a Book\n");
        printf("4. Return a Book\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addbook();
                break;

            case 2:
                displaybook();
                break;

            case 3:
                issuebook();
                break;

            case 4:
                returnbook();
                break;

            case 5:
                printf("\nProgram successfully Exited.\n");
                return 0;

            default:
                printf("\nInvalid Choice.\n");
        }

    }
}

void addbook()                              // func to add new book
{
    char title[50];
    char auth[50];

    if(bookcount == 100)
    {
        printf("\nLibrary is full.\n");
        return;
    }

    printf("Enter Book Title (No spaces): ");
    scanf("%s", title);

    printf("Enter Author Name (No spaces): ");
    scanf("%s", auth);

    if(isduplicatebook(title, auth) == 1){
        printf("\nThis book already exists in the library.\n");
        return;
    }

    strcpy(library[bookcount].title, title);
    strcpy(library[bookcount].author, auth);

    library[bookcount].issuedornot = 0;             // book is available
    library[bookcount].issuedtostudent = -1;        // no student has taken

    bookcount++;

    printf("\nBook added successfully.\n");
}

void displaybook()                          // func to display books
{
    if(bookcount == 0)
    {
        printf("\nNo Books in the Library.\n");
        return;
    }

    printf("\n\t---- List of Books  ----\n\n");
    for(int i = 0; i < bookcount ; i++)
    {
        printf("\tBook %d:\n", i + 1);
        printf("\t\tTitle  : %s\n", library[i].title);
        printf("\t\tAuthor : %s\n", library[i].author);

    if(library[i].issuedornot == 0){
        printf("\t\tStatus : Available\n");
    }
    else{
        printf("\t\tStatus : Issued to Student ID %d\n", library[i].issuedtostudent);
    }
    printf("\n");
    }
}

int findbookindex(char a[], char b[])
{
    for(int i = 0; i < bookcount; i++){
        if(strcmp(library[i].title, a) == 0 && strcmp(library[i].author, b) == 0){
            return i;
        }
    }
    return -1;
}

void issuebook()
{
    char title[50];
    char auth[50];                                  // store author name entered by user
    int studentid;                                  // stores student id entered by user
    int index;                                      // store index position of book id

    printf("Enter Book Title: ");
    scanf("%s", title);

    printf("Enter Author Name: ");
    scanf("%s", auth);

    index = findbookindex(title, auth);            // finding position of book by author name and storing it in index

    if(index == -1)                                 // index = -1 mean book doesnt exist in library
    {
        printf("Book not found.\n");
        return;
    }

    if(library[index].issuedornot == 1)                     // to check if book is already issued , if = 1 mean book is taken by student
    {
        printf("Book is already issued to student ID %d.\n", library[index].issuedtostudent);
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &studentid);

    printf("Enter Issue Date (DD MM YYYY): ");
    scanf("%d %d %d", &library[index].issue_day, &library[index].issue_month, &library[index].issue_year);

    library[index].issuedornot = 1;                         // marking the book as issued at that index
    library[index].issuedtostudent = studentid;             // marking student id who has taken the book at that index

    printf("\nBook issued successfully.\n");
}

void returnbook()
{
    char title[50];
    char auth [50];                                 // store author name entered by user
    int index;                                      // store index position of that book id

    printf("Enter Book Title: ");
    scanf("%s", title);

    printf("Enter Author Name: ");
    scanf("%s", auth);

    index = findbookindex(title, auth);            // finding position of book by author name and storing it in index

    if(index == -1)                                 // index = -1 mean book doesnt exist in library
    {
        printf("Book not found.\n");
        return;
    }

    if (library[index].issuedornot == 0)                    // to check if book is issued or not
    {
        printf("This Book is not currently issued.\n");
        return;
    }

    printf("Enter Return Date (DD MM YYYY): ");
    scanf("%d %d %d", &library[index].return_day, &library[index].return_month, &library[index].return_year);

    int issue_days = library[index].issue_year * 365 + library[index].issue_month * 30 + library[index].issue_day;
    int return_days = library[index].return_year * 365 + library[index].return_month * 30 + library[index].return_day;
    int total_days = return_days - issue_days;
    int fine = 0;

    if(total_days > 7){
        fine = (total_days - 7) * 5;
    }

    library[index].issuedornot = 0;                         // marking the book as available
    library[index].issuedtostudent = -1;                    // removing the student id (book is not issued to any student)

    printf("\nBook returned successfully.\n");
    printf("Total days used: %d\n", total_days);

    if(fine > 0)
        printf("Fine: Rs %d\n", fine);
    else
        printf("No fine. Returned on time.\n");
}

int isduplicatebook(char a[], char b[])
{
    for(int i = 0; i < bookcount; i++){
        if(strcmp(library[i].title, a) == 0 && strcmp(library[i].author, b) == 0){
            return 1;
        }
    }
    return 0;
}
