#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
int removeBook(int *Num);
void listBooks(int bookNum);
int addBook(int *bookNum);
void Rearrange(int bookNum);
int main()
{
    int num = 0;
    listBooks(num);
    // addBook(&num);
    listBooks(num);
    removeBook(&num);
    listBooks(num);
}
int removeBook(int *Num)
{
    printf("removeBook():\n");
    int count;
    printf("Enter the targetbook title:\n");
    // scanf("%s", targetTitle);
    printf("Enter the target author name:\n");
    // scanf("%s", targetAuthor);
    char targetTitle[40] = "test";
    char targetAuthor[40] = "test";
    if (*Num == 0)
    {
        printf("The bookshop is empty\n");
        return 1;
    }
    for (int i = 0; i < *Num; i++)
    {
        if (strcmp(targetTitle, bookshop[i].title) == 0 && strcmp(targetAuthor, bookshop[i].author) == 0)
        {
            for (int j = i; j < *Num; j++)
                bookshop[j] = bookshop[j + 1];
            *Num -= 1;
            i--;
            Rearrange(*Num);
            count++;
        }
    }
    if (count >= 1)
        printf("The target book is removed\n");
    else
        printf("The target book is not in the bookshop\n");
}

int addBook(int *bookNum)
{
    printf("addbook");
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
    strcpy(bookshop[2].title, "tesdd");
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
void listBooks(int bookNum)
{
    printf("listBooks():\n");
    if (bookNum == 0)
        printf("The bookshop is empty\n");
    else
        for (int i = 0; i < bookNum; i++)
            printf("BookID: %d\nBook title: %s\nAuthor name: %s\nBook price: %.2lf\nQuantity: %d\n\n", bookshop[i].bookID, bookshop[i].title, bookshop[i].author, bookshop[i].price, bookshop[i].quantity);
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
