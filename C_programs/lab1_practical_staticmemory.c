#include <stdio.h>

void outputArray(int a[], int size) 
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void linearSearch(int a[], int size) 
{
    int n, flag = 0;
    printf("Enter element you want to search: ");
    scanf("%d", &n);

    for (int i = 0; i < size; i++) 
    {
        if (a[i] == n) {
            printf("Entered element found at index %d\n", i);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("Entered element is not found in array\n");
}
void reverseArray(int a[], int size) 
{

    int i = 0, j = size - 1;

    while (j > i) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }

    printf("Reversed array: ");
    outputArray(a, size);
}

void updateArray(int a[], int size) {
    printf("Updated array: ");
    for (int i = 0; i < size; i++) 
    {
        if (i % 2 == 0)
            a[i] *= 2;
        else
            a[i] += 5;
    }

    outputArray(a, size);
}

void insertElement(int a[], int *size) {
    int index, element;
    printf("Enter index you want to insert element in: ");
    scanf("%d", &index);

    printf("Enter element you want to insert: ");
    scanf("%d", &element);
(*size)++;

    for (int i = *size - 1; i > index; i--) {
        a[i] = a[i - 1];
    }
    a[index] = element;

    printf("Array after insertion:\n");
    outputArray(a, *size);
}

void deleteElement(int a[], int *size) {
    int index;
    printf("Enter index to be deleted: ");
    scanf("%d", &index);

    if (index < 0 || index >= *size) 
    {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) 
    {
        a[i] = a[i + 1];
    }

    (*size)--;

    printf("Array after deletion:\n");
    outputArray(a, *size);
}

int main(void) {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int a[size];

    printf("Enter elements in the array: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &a[i]);
    }

    outputArray(a,size);

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Reverse Array\n");
        printf("3. Update Array\n");
        printf("4. Insert Element\n");
        printf("5. Delete Element\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linearSearch(a, size);
                break;
            case 2:
                reverseArray(a, size);
                break;
            case 3:
                updateArray(a, size);
                break;
            case 4:
                insertElement(a, &size);
                break;
            case 5:
                deleteElement(a, &size);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);
}