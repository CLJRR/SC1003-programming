#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
int MAX = 5;
Book bookshop[5];
typedef struct
{
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity;
} Book;
void listBooks(Book bookshop[]);
void addBook(Book bookshop[]);
void removeBook(Book bookshop[]);
void findBook(Book bookshop[]);
void updateBook(Book bookshop[]);
int emptyChecker(Book bookshop[], int current);
void ascendingOrder(Book bookshop[]);
int main()
{
    int a[MAX];
    int choice;
    printf("NTU BOOKSHOP MANAGEMENT PROGRAM:\n1: listBooks()\n2: addBook()\n3: removeBook()\n4: findBook()\n5: updateBook()\n6: quit\n");
    scanf("%d", &choice);
    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            listBooks(bookshop);
            break;
        case 2:
            addBook(bookshop);
            break;
        case 3:
            removeBook(bookshop);
            break;
        case 4:
            findBook(bookshop);
            break;
        case 5:
            updateBook(bookshop);
            break;
        case 6:
            break;
        default:
            break;
        }
        scanf("%d", &choice);
    }
}
void ascendingOrder(Book bookshop[])
{
}
int emptyChecker(Book bookshop[], int current)
{
    if (bookshop[0].bookID == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void listBooks(Book bookshop[])
{
    printf("listBooks():\n");
    for (int i = 0; i < 5; i++)
    {
        if (emptyChecker(bookshop, i) == 1)
        {
            printf("empty\n");
            break;
        }
        else
        {
            printf("BookID: %d\nBook title: %s\nAuthor name: %s\nBook price: %f\nQuantity: %d\n", bookshop[0].bookID, bookshop[0].title, bookshop[0].author, bookshop[0].price = 1, bookshop[0].quantity = 1);
        }
    }
}
void addBook(Book bookshop[MAX])
{
    printf("addBook():\n");

    bookshop[0].bookID = 1;
    char *a = "test";
    strcpy(bookshop[0].title, a);
    strcpy(bookshop[0].author, a);
    // for (int i = 0; i < 5; i++)
    // {
    //     bookshop[0].title[i] = a[i];
    //     bookshop[0].author[i] = a[i];
    // }
    bookshop[0].price = 1;
    bookshop[0].quantity = 1;
    printf("BookID: %d\nBook title: %s\nAuthor name: %s\nBook price: %.2f\nQuantity: %d\n", bookshop[0].bookID, bookshop[0].title, bookshop[0].author, bookshop[0].price = 1, bookshop[0].quantity = 1);
}
void removeBook(Book bookshop[])
{
    printf("removeBook():\n");
}
void findBook(Book bookshop[])
{
    printf("findBook():\n");
}
void updateBook(Book bookshop[MAX])
{
    printf("updateBook():\n");
}