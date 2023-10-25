#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
int MAX = 5;
typedef struct
{
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity;
} Book;

Book bookshop[4];
void listBooks(int bookNum);
int addBook(int bookNum, int *p);
void removeBook(int bookNum, int *p);
void findBook(int bookNum);
void updateBook(int bookNum);

int main()
{
    int a[MAX];
    int choice;
    int bookNum = 0; // num of books
    printf("NTU BOOKSHOP MANAGEMENT PROGRAM:\n1: listBooks()\n2: addBook()\n3: removeBook()\n4: findBook()\n5: updateBook()\n6: quit\n");
    scanf("%d", &choice);
    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            listBooks(bookNum);
            break;
        case 2:
            addBook(bookNum, &bookNum);

            printf("%d", bookNum);
            // bookNum++;
            break;
        case 3:
            removeBook(bookNum, &bookNum);
            // bookNum--;
            break;
        case 4:
            findBook(bookNum);
            break;
        case 5:
            updateBook(bookNum);
            break;
        case 6:
            break;
        default:
            break;
        }
        scanf("%d", &choice);
    }
}
void Rearrange(int bookNum)
{
}

void listBooks(int bookNum)
{
    printf("listBooks():\n");
    if (bookNum == 0)
        printf("The bookshop is empty");
    else
        for (int i = 0; i < bookNum + 1; i++)
            printf("BookID: %d\nBook title: %s\nAuthor name: %s\nBook price: %.2lf\nQuantity: %d\n\n", bookshop[i].bookID, bookshop[i].title, bookshop[i].author, bookshop[i].price, bookshop[i].quantity);
}
int bookIdChecker(int bookNum)
{
    for (int i = 0; i < bookNum; i++)
    {
        if (bookshop[bookNum].bookID == bookshop[i].bookID)
            return 1;
    }
    return 0;
}
int addBook(int bookNum, int *p)
{
    printf("addBook():\n");
    char s[40];
    printf("Enter bookID:\n");
    scanf("%d", &bookshop[bookNum].bookID);
    printf("Enter book title:\n");
    scanf("%s", &s);
    strcpy(bookshop[bookNum].title, s);
    printf("Enter author name:\n");
    scanf("%s", &s);
    strcpy(bookshop[bookNum].author, s);
    printf("Enter price:\n");
    scanf("%lf", &bookshop[bookNum].price);
    printf("Enter quantity:\n");
    scanf("%d", &bookshop[bookNum].quantity);
    if (bookNum == 5)
        printf("The bookshop is full! Unable to addBook()\n");
    else if (bookIdChecker(bookNum) == 1)
        printf("The bookID has already existed! Unable to addBook()\n");
    else
    {
        printf("The book has been added successfully\n");
        *p += 1;
    }
    // bookshop[bookNum].bookID = bookNum + 1;
    // char *a = "test";
    // strcpy(bookshop[bookNum].title, a);
    // strcpy(bookshop[bookNum].author, a);
    // bookshop[bookNum].price = bookNum + 2;
    // bookshop[bookNum].quantity = bookNum + 3;
}
void removeBook(int bookNum, int *p)
{
    printf("removeBook():\n");
}
void findBook(int bookNum)
{
    printf("findBook():\n");
}
void updateBook(int bookNum)
{
    printf("updateBook():\n");
}