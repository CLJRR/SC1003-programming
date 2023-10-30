#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
typedef struct
{
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity;
} Book;
int MAX = 5;
Book bookshop[5];
void listBooks(int bookNum);
int addBook(int *bookNum);
void removeBook(int bookNum, int *Num);
void findBook(int bookNum);
void updateBook(int bookNum);

int main()
{
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
            addBook(&bookNum);
            break;
        case 3:
            removeBook(bookNum, &bookNum);
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
    Book temp;
    int min, arr;
    for (int i = 0; i < bookNum; i++)
    {
        min = bookshop[i].bookID;
        arr = i;
        for (int j = i + 1; j < bookNum; j++)
        {
            if (bookshop[j].bookID < min)
            {
                min = bookshop[j].bookID;
                arr = j;
            }
        }
        temp = bookshop[arr];
        bookshop[arr] = bookshop[i];
        bookshop[i] = temp;
    }
}

void listBooks(int bookNum)
{
    printf("listBooks():\n");
    if (bookNum == 0)
        printf("The bookshop is empty");
    else
        for (int i = 0; i < bookNum; i++)
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
int addBook(int *bookNum)
{
    char *a = "test";
    for (int i = 5, j = 0; j < 5; i--, j++)
    {
        bookshop[j].bookID = i;
        strcpy(bookshop[j].title, a);
        strcpy(bookshop[j].author, a);
        bookshop[j].price = i;
        bookshop[j].quantity = i;
        *bookNum += 1;
    }

    bookshop[2].bookID = 99;
    strcpy(bookshop[2].title, a);
    strcpy(bookshop[2].author, a);
    bookshop[2].price = 1;
    bookshop[2].quantity = 1;

    Rearrange(*bookNum);
    // bookshop[0].bookID = 1;
    // strcpy(bookshop[0].title, a);
    // strcpy(bookshop[0].author, a);
    // bookshop[0].price = 1;
    // bookshop[0].quantity = 1;

    // bookshop[0].bookID = 1;
    // strcpy(bookshop[0].title, a);
    // strcpy(bookshop[0].author, a);
    // bookshop[0].price = 1;
    // bookshop[0].quantity = 1;

    // bookshop[0].bookID = 1;
    // strcpy(bookshop[0].title, a);
    // strcpy(bookshop[0].author, a);
    // bookshop[0].price = 1;
    // bookshop[0].quantity = 1;
}
void removeBook(int bookNum, int *Num)
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