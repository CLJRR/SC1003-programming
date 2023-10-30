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
int removeBook(int *Num);
void findBook(int bookNum);
void updateBook(int bookNum);

int main()
{
    int choice;
    int bookNum = 0; // num of books
    printf("NTU BOOKSHOP MANAGEMENT PROGRAM:\n1: listBooks()\n2: addBook()\n3: removeBook()\n4: findBook()\n5: updateBook()\n6: quit\nEnter your choice:\n");
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
            removeBook(&bookNum);
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
        printf("Enter your choice:\n");
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
        printf("The bookshop is empty\n");
    else
        for (int i = 0; i < bookNum; i++)
            printf("BookID: %d\nBook title: %s\nAuthor name: %s\nBook price: %.2lf\nQuantity: %d\n", bookshop[i].bookID, bookshop[i].title, bookshop[i].author, bookshop[i].price, bookshop[i].quantity);
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
    char s[40];
    int input;
    printf("addBook():\nEnter bookID:\n");
    scanf("%d", &bookshop[*bookNum].bookID);
    printf("Enter book title:\n");
    fgets(s, 40, stdin);
    if (fgets(s, 40, stdin))
    {
        s[strcspn(s, "\n")] = 0;
    }
    strcpy(bookshop[*bookNum].title, s);
    printf("Enter author name:\n");
    if (fgets(s, 40, stdin))
    {
        s[strcspn(s, "\n")] = 0;
    }
    strcpy(bookshop[*bookNum].author, s);
    printf("Enter price:\n");
    scanf("%lf", &bookshop[*bookNum].price);
    printf("Enter quantity:\n");
    scanf("%d", &bookshop[*bookNum].quantity);
    if (*bookNum == 5)
        printf("The bookshop is full! Unable to addBook()\n");
    else if (bookIdChecker(*bookNum) == 1)
        printf("The bookID has already existed! Unable to addBook()\n");
    else
    {
        printf("The book has been added successfully\n");
        *bookNum += 1;
        Rearrange(*bookNum);
    }
}
int removeBook(int *Num)
{
    printf("removeBook():\n");
    int count;
    char targetTitle[40], targetAuthor[40];
    printf("Enter the targetbook title:\n");
    scanf("%s", targetTitle);
    printf("Enter the target author name:\n");
    scanf("%s", targetAuthor);
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

void findBook(int bookNum)
{
    printf("findBook():\n");
}
void updateBook(int bookNum)
{
    printf("updateBook():\n");
}