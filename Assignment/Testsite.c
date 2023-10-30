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
    char str[40];
    fgets(str, 40, stdin);
    printf("%s", str);
}