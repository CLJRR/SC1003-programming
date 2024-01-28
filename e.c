#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
    char a[80], b[80];
    char ch, *p;

    printf("Enter a string: \n");
    fgets(a, 80, stdin);
    if (p = strchr(a, '\n'))
        *p = '\0';
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a, b, ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
    strncpy(str2, str1, 3);
    int length = strlen(str1);
    printf("len =%d", length);
    int length2 = length + length / 3;
    for (int i = 0; i < length; i++)
    {
        *(str2 + i) = *(str1 + i);
    }
    printf("%s", *str2);
}