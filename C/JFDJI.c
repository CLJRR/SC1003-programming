#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
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
int stringcompare(int location, char Ttitle[40], char Tauthor[40])
{
    char titleCopy[40], authorCopy[40];
    strcpy(titleCopy, bookshop[location].title);
    strcpy(authorCopy, bookshop[location].author);

    for (char *p = titleCopy; *p; p++)
        *p = toupper(*p);
    for (char *p = authorCopy; *p; p++)
        *p = toupper(*p);
    for (char *p = Ttitle; *p; p++)
        *p = toupper(*p);
    for (char *p = Tauthor; *p; p++)
        *p = toupper(*p);
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(Ttitle, titleCopy) == 0 && strcmp(Tauthor, authorCopy) == 0)
            return 0;
    }

    return 1;
}
int main()
{
    char a[40] = "test";
    bookshop[0].bookID = 1;
    strcpy(bookshop[0].title, a);
    strcpy(bookshop[0].author, a);
    bookshop[0].price = 1;
    bookshop[0].quantity = 1;
    int location = 0;
    // bookshop[0].bookID = 1;
    // strcpy(bookshop[0].title, a);
    // strcpy(bookshop[0].author, a);
    // bookshop[0].price = 1;
    // bookshop[0].quantity = 1;
    char Ttitle[40] = "test", Tauthor[40] = "test";
    stringcompare(location, Ttitle, Tauthor);
    // printf("%d", stringcompare(location, Ttitle, Tauthor));
}