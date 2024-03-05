#include <stdio.h>

int stringLength(char str[]);
void stringReverse(char str[]);
int stringCompare(char str1[], char str2[]);
void stringConcatenate(char str1[], char str2[]);
void stringCopy(char destination[], char source[]);

int main(void) {
    char str1[100], str2[100];
    int choice;
    printf("Enter a string: ");
    scanf("%s", str1);
    do
    {
        printf("\nMenu:\n");
        printf("1. String Length\n");
        printf("2. String Reversal\n");
        printf("3. String Compare\n");
        printf("4. String Concatenate\n");
        printf("5. String Copy\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Length of string: %d\n", stringLength(str1));
                break;
            case 2:
                stringReverse(str1);
                printf("Reversed string: %s\n", str1);
                break;
            case 3:
                printf("Enter string 2: ");
                scanf("%s", str2);
                if (stringCompare(str1, str2) < 0)
                    printf("String 1 comes before string 2\n");
                else if (stringCompare(str1, str2) > 0)
                    printf("String 2 comes before string 1\n");
                else
                    printf("Both strings are equal\n");
                break;
            case 4:
                printf("Enter string 2: ");
                scanf("%s", str2);
                stringConcatenate(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 5:
                stringCopy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } 
    while (choice != 6);
}


int stringLength(char str[]) // CALCULATING LENGTH OF STRING
{
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    return length;
}
void stringReverse(char str[]) //REVERSING THE STRING
{
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
int stringCompare(char str1[], char str2[]) //COMPARING TWO STRINGS
{
    int i = 0;
    while (str1[i] == str2[i]) 
    {
        if (str1[i] == '\0' && str2[i] == '\0') 
        {
            return 0; // strings are equal
        }
        i++;
    }
    return str1[i] - str2[i];
}
void stringConcatenate(char str1[], char str2[]) //STRING CONCATENATION
{
    int i, j;
    i = stringLength(str1);
    j = 0;
    while (str2[j] != '\0') 
    {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
}

void stringCopy(char destination[], char source[]) 
{
    int i = 0;
    while (source[i] != '\0') 
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}
