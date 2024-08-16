#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
  int bookID;
  char title[40];
  char author[40];
  double price;
  int quantity;
} Book;

void listBooks(Book *book, int size);
int addBook(Book *book, int size);
int removeBook(Book *book, int size);
void findBook(Book *book, int size);
void updateBook(Book *book, int size);

// Helper functions
void sortBooks(Book *book, int size);

int main()
{
  Book book[MAX];
  int choice, numBooks = 0;

  printf("NTU BOOKSHOP MANAGEMENT PROGRAM: \n");
  printf("1: listBooks() \n");
  printf("2: addBook() \n");
  printf("3: removeBook() \n");
  printf("4: findBook() \n");
  printf("5: updateBook() \n");
  printf("6: quit \n");

  while (choice != 6)
  {
    printf("Enter your choice: \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      listBooks(book, numBooks);
      break;
    case 2:
      numBooks = addBook(book, numBooks);
      break;
    case 3:
      numBooks = removeBook(book, numBooks);
      break;
    case 4:
      findBook(book, numBooks);
      break;
    case 5:
      updateBook(book, numBooks);
      break;
    default:
      break;
    }
  }
}

void listBooks(Book *book, int size)
{
  printf("listBooks():\n");

  if (size == 0)
  {
    printf("The bookshop is empty\n");
  }
  else
  {
    int i;
    for (i = 0; i < size; i++)
    {
      printf("BookID: %d\n", book[i].bookID);
      printf("Book title: %s\n", book[i].title);
      printf("Author name: %s\n", book[i].author);
      printf("Book price: %.2lf\n", book[i].price);
      printf("Quantity: %d\n", book[i].quantity);
    }
  }
}

int addBook(Book *book, int size)
{
  int bookID, quantity, i;
  char title[40], author[40];
  double price;

  printf("addBook():\n");
  printf("Enter bookID:\n");
  scanf("%d", &bookID);

  printf("Enter book title:\n");
  getchar();
  fgets(title, 40, stdin);
  title[strcspn(title, "\n")] = '\0';

  printf("Enter author name:\n");
  fgets(author, 40, stdin);
  author[strcspn(author, "\n")] = '\0';

  printf("Enter price:\n");
  scanf("%lf", &price);
  printf("Enter quantity:\n");
  scanf("%d", &quantity);

  for (i = 0; i < size; i++)
  {
    if (book[i].bookID == bookID)
    {
      printf("The bookID has already existed! Unable to addBook()\n");
      return size;
    }
  }

  if (size == MAX)
  {
    printf("The bookshop is full! Unable to addBook()\n");
    return size;
  }

  // add new book to array
  book[size].bookID = bookID;
  strcpy(book[size].title, title);
  strcpy(book[size].author, author);
  book[size].price = price;
  book[size].quantity = quantity;

  printf("The book has been added successfully\n");

  (size)++;

  // sort books
  sortBooks(book, size);

  return size;
}

int removeBook(Book *book, int size)
{
  char title[40], author[40];
  int i, j;

  printf("removeBook():\n");

  printf("Enter the target book title:\n");
  getchar();
  fgets(title, 40, stdin);
  title[strcspn(title, "\n")] = '\0';

  printf("Enter the target author name:\n");
  fgets(author, 40, stdin);
  author[strcspn(author, "\n")] = '\0';

  if (size == 0)
  {
    printf("The bookshop is empty\n");
    return size;
  }

  for (i = 0; i < size; i++)
  {
    // strcasecmp() -> case insensitive string comparison
    if (strcasecmp(book[i].title, title) == 0 && strcasecmp(book[i].author, author) == 0)
    {
      printf("The target book is removed\n");
      printf("BookID: %d\n", book[i].bookID);
      printf("Book title: %s\n", book[i].title);
      printf("Author name: %s\n", book[i].author);
      printf("Book price: %.2lf\n", book[i].price);
      printf("Quantity: %d\n", book[i].quantity);

      for (j = i; j < (size - 1); j++)
      {
        book[j] = book[j + 1];
      }

      (size)--;
      return size;
    }
  }

  printf("The target book is not in the bookshop\n");

  return size;
}

void findBook(Book *book, int size)
{
  char title[40], author[40];
  int i;

  printf("findBook():\n");

  printf("Enter the target book title:\n");
  getchar();
  fgets(title, 40, stdin);
  title[strcspn(title, "\n")] = '\0';

  printf("Enter the target author name:\n");
  fgets(author, 40, stdin);
  author[strcspn(author, "\n")] = '\0';

  for (i = 0; i < size; i++)
  {
    if (strcasecmp(book[i].title, title) == 0 && strcasecmp(book[i].author, author) == 0)
    {
      printf("The target book is found\n");
      printf("BookID: %d\n", book[i].bookID);
      printf("Book title: %s\n", book[i].title);
      printf("Author name: %s\n", book[i].author);
      printf("Book price: %.2lf\n", book[i].price);
      printf("Quantity: %d\n", book[i].quantity);

      return;
    }
  }

  printf("The target book is not found\n");

  return;
}

void updateBook(Book *book, int size)
{
  char title[40], author[40];
  int i;

  printf("updateBook():\n");

  printf("Enter the target book title:\n");
  getchar();
  fgets(title, 40, stdin);
  title[strcspn(title, "\n")] = '\0';

  printf("Enter the target author name:\n");
  fgets(author, 40, stdin);
  author[strcspn(author, "\n")] = '\0';

  for (i = 0; i < size; i++)
  {
    if (strcasecmp(book[i].title, title) == 0 && strcasecmp(book[i].author, author) == 0)
    {
      printf("Enter updated book price:\n");
      scanf("%lf", &book[i].price);
      printf("Enter updated quantity:\n");
      scanf("%d", &book[i].quantity);

      printf("The target book is updated\n");
      printf("BookID: %d\n", book[i].bookID);
      printf("Book title: %s\n", book[i].title);
      printf("Author name: %s\n", book[i].author);
      printf("Book price: %.2lf\n", book[i].price);
      printf("Quantity: %d\n", book[i].quantity);

      return;
    }
  }

  printf("The target book is not in the bookshop\n");

  return;
}

// Helper functions
/*
The compareBookIDs function takes two pointers to const void, named a and b. These are generic pointers used to refer to elements in the array to be sorted. To make them usable, they are cast to pointers of type const Book*. This allows the function to access the bookID field of the Book structures pointed to by a and `b.

Inside the function, it compares the bookID values of the two Book structures pointed to by bookA and bookB. The comparison is done as follows:

If bookA->bookID is less than bookB->bookID, it returns -1. This indicates that bookA should come before bookB in the sorted order.
If bookA->bookID is greater than bookB->bookID, it returns 1. This indicates that bookA should come after bookB in the sorted order.
If bookA->bookID is equal to bookB->bookID, it returns 0, signifying that both bookA and bookB have the same bookID, and their order in the sorted array is not significant.
*/
int compareBookIDs(const void *a, const void *b)
{
  const Book *bookA = (const Book *)a;
  const Book *bookB = (const Book *)b;

  if (bookA->bookID < bookB->bookID)
    return -1;
  if (bookA->bookID > bookB->bookID)
    return 1;
  return 0;
}

void sortBooks(Book *book, int size)
{
  // Sort the array of books by bookID in ascending order
  // Quick Sort instead of double for loop -> Time Complexity O(n log n) instead of O(n^2)
  qsort(book, size, sizeof(Book), compareBookIDs);
}