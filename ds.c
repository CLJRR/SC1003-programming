#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#define maxBooks 5

typedef struct
{
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity;
} Book;
Book bookshop[maxBooks];

// declare functions here
void listBooks(int *bookCount);
int addBook(int *bookCount, Book bookshop[maxBooks]);
int removeBook(int *bookCount, Book bookshop[maxBooks]);
int stringcompare(int location, char Ttitle[40], char Tauthor[40]);

int main()
{

    int choice;
    int bookCount = 0;

    printf("NTU BOOKSHOP MANAGEMENT PROGRAM:\n");
    printf("1: listBooks()\n");
    printf("2: addBook()\n");
    printf("3: removeBook()\n");
    printf("4: findBook()\n");
    printf("5: updateBook()\n");
    printf("6: quit\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);

    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            listBooks(&bookCount);
            break;

        case 2:
            bookCount = addBook(&bookCount, bookshop);
            break;

        case 3:
            removeBook(&bookCount, bookshop);
            break;
        }

        printf("Enter your choice: \n");
        scanf("%d", &choice);
    }
}

void listBooks(int *bookCount)
{
    int i;
    printf("listBooks(): \n");
    if (*bookCount == 0)
    {
        printf("The bookshop is empty \n");
    }

    else
    {
        for (i = 0; i < *bookCount; i++)

        {
            printf("BookID: %d \n", bookshop[i].bookID);
            printf("Book title: %s \n", bookshop[i].title);
            printf("Author name: %s \n", bookshop[i].author);
            printf("Book price: %.2lf \n", bookshop[i].price);
            printf("Quantity: %d \n", bookshop[i].quantity);
        }
    }
}

int addBook(int *bookCount, Book bookshop[])
{
    char *p;
    Book newBooks;

    printf("addBook(): \n");

    printf("Enter bookID: \n");
    scanf("%d", &newBooks.bookID);

    while (getchar() != '\n')
        ;

    printf("Enter book title: \n");
    fgets(newBooks.title, 40, stdin);
    if (p = strchr(newBooks.title, '\n'))
    {
        *p = '\0';
    }

    printf("Enter author name: \n");
    fgets(newBooks.author, 40, stdin);
    if (p = strchr(newBooks.author, '\n'))
    {
        *p = '\0';
    }

    printf("Enter price: \n");
    scanf("%lf", &newBooks.price);

    printf("Enter quantity: \n");
    scanf("%d", &newBooks.quantity);

    for (int i = 0; i < *bookCount; i++)
    {
        if (bookshop[i].bookID == newBooks.bookID)
        {
            printf("The bookID has already existed! Unable to addBook() \n");
            return *bookCount;
        }
    }
    if (*bookCount == maxBooks)
    {
        printf("The bookshop is full! Unable to addBook() \n");
        return *bookCount;
    }

    int i = *bookCount;
    while (i > 0 && bookshop[i - 1].bookID > newBooks.bookID)
    {
        bookshop[i] = bookshop[i - 1];
        i--;
    }

    bookshop[i] = newBooks;

    printf("The book has been added successfully \n");
    return *bookCount + 1;
}
int removeBook(int *bookCount, Book bookshop[])
{

    printf("removeBook():\n");
    char removeTitle[40], removeAuthor[40];
    printf("Enter the target book title:\n");
    fgets(removeTitle, 40, stdin);
    if (fgets(removeTitle, 40, stdin))
    {
        removeTitle[strcspn(removeTitle, "\n")] = 0;
    }
    printf("Enter the target author name:\n");
    if (fgets(removeAuthor, 40, stdin))
    {
        removeAuthor[strcspn(removeAuthor, "\n")] = 0;
    }
    if (*bookCount == 0)
    {
        printf("The bookshop is empty\n");
        return 1;
    }
    for (int i = 0; i < *bookCount; i++)
    {
        if (stringcompare(i, removeTitle, removeAuthor) == 0)
        {
            printf("The target book is removed\n");
            printf("BookID: %d \n", bookshop[i].bookID);
            printf("Book title: %s \n", bookshop[i].title);
            printf("Author name: %s \n", bookshop[i].author);
            printf("Book price: %.2lf \n", bookshop[i].price);
            printf("Quantity: %d \n", bookshop[i].quantity);

            for (int j = i; j < *bookCount; j++)
                bookshop[j] = bookshop[j + 1];
            (*bookCount)--;
            return 0;
        }
    }
    printf("The target book is not in the bookshop \n");
    return *bookCount;
}