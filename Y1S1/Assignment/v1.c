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
// void listBooks(int bookNum);
int addBook(int *bookNum);
int removeBook(int *Num);
void findBook(int bookNum);
int updateBook(int bookNum);
int stringcompare(int location, char Ttitle[40], char Tauthor[40]);
void listBooks(int bookNum)
{
    printf("listBooks():\n");
    if (bookNum == 0)
        printf("The bookshop is empty\n");
    else
        for (int i = 0; i < bookNum; i++)
            printf("BookID: %d\nBook title: %s\nAuthor name: %s\nBook price: %.2lf\nQuantity: %d\n", bookshop[i].bookID, bookshop[i].title, bookshop[i].author, bookshop[i].price, bookshop[i].quantity);
}
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
    int count = 0;
    char Ttitle[40], Tauthor[40];
    printf("Enter the target book title:\n");
    fgets(Ttitle, 40, stdin);
    if (fgets(Ttitle, 40, stdin))
    {
        Ttitle[strcspn(Ttitle, "\n")] = 0;
    }
    printf("Enter the target author name:\n");
    if (fgets(Tauthor, 40, stdin))
    {
        Tauthor[strcspn(Tauthor, "\n")] = 0;
    }
    if (*Num == 0)
    {
        printf("The bookshop is empty\n");
        return 1;
    }
    for (int i = 0; i < *Num; i++)
    {
        if (stringcompare(i, Ttitle, Tauthor) == 0)
        {
            printf("The target book is removed\n");
            printf("BookID: %d\nBook title: %s\nAuthor name: %s\nBook price: %.2lf\nQuantity: %d\n", bookshop[i].bookID, bookshop[i].title, bookshop[i].author, bookshop[i].price, bookshop[i].quantity);
            for (int j = i; j < *Num; j++)
                bookshop[j] = bookshop[j + 1];
            *Num -= 1;
            Rearrange(*Num);
            count++;
        }
    }
    if (count == 0)
        printf("The target book is not in the bookshop\n");
}

void findBook(int bookNum)
{
    printf("findBook():\n");
    char Ttitle[40], Tauthor[40];
    int count = 0;
    printf("Enter the target book title:\n");
    fgets(Ttitle, 40, stdin);
    if (fgets(Ttitle, 40, stdin))
    {
        Ttitle[strcspn(Ttitle, "\n")] = 0;
    }
    printf("Enter the target author name:\n");
    if (fgets(Tauthor, 40, stdin))
    {
        Tauthor[strcspn(Tauthor, "\n")] = 0;
    }
    for (int i = 0; i < bookNum; i++)
    {
        if (stringcompare(i, Ttitle, Tauthor) == 0)
        {
            printf("The target book is found\n");
            printf("BookID: %d\nBook title: %s\nAuthor name: %s\nBook price: %.2lf\nQuantity: %d\n", bookshop[i].bookID, bookshop[i].title, bookshop[i].author, bookshop[i].price, bookshop[i].quantity);
            count++;
        }
    }
    if (count == 0)
    {
        printf("The target book is not found\n");
    }
}
int updateBook(int bookNum)
{
    printf("updateBook():\n");
    char Ttitle[40], Tauthor[40];
    int location = 99;
    printf("Enter the target book title:\n");
    fgets(Ttitle, 40, stdin);
    if (fgets(Ttitle, 40, stdin))
    {
        Ttitle[strcspn(Ttitle, "\n")] = 0;
    }
    printf("Enter the target author name:\n");
    if (fgets(Tauthor, 40, stdin))
    {
        Tauthor[strcspn(Tauthor, "\n")] = 0;
    }
    for (int i = 0; i < bookNum; i++)
        if (stringcompare(i, Ttitle, Tauthor) == 0)
        {
            location = i;
            break;
        }

    if (location == 99)
    {
        printf("The target book is not in the bookshop\n");
        return 99;
    }
    printf("Enter updated book price:\n");
    scanf("%lf", &bookshop[location].price);
    printf("Enter updated quantity:\n");
    scanf("%d", &bookshop[location].quantity);
    printf("The target book is updated\n");
    printf("BookID: %d\nBook title: %s\nAuthor name: %s\nBook price: %.2lf\nQuantity: %d\n", bookshop[location].bookID, bookshop[location].title, bookshop[location].author, bookshop[location].price, bookshop[location].quantity);
}
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
    if (strcmp(Ttitle, titleCopy) == 0 && strcmp(Tauthor, authorCopy) == 0)
        return 0;
    return 1;
}