#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity;
} Book;
int listBooks()
{
    printf("listBooks():\n");
}
int addBook()
{
    printf("addBook():\n");
}
int removeBook()
{
    printf("removeBook():\n");
}
int findBook()
{
    printf("findBook():\n");
}
int updateBook()
{
    printf("updateBook():\n");
}
int main()
{
    Book bookshop[100];
    int choice;
    printf("NTU BOOKSHOP MANAGEMENT PROGRAM:\n1: listBooks()\n2: addBook()\n3: removeBook()\n4: findBook()\n5: updateBook()\n6: quit\n");
    scanf("%d", &choice);
    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            listBooks();
            break;
        case 2:
            addBook();
            break;
        case 3:
            removeBook();
            break;
        case 4:
            findBook();
            break;
        case 5:
            updateBook();
            break;
        case 6:
            break;
        default:
            break;
        }
        scanf("%d", &choice);
    }
}
