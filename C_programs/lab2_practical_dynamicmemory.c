#include <stdio.h>
#include<stdlib.h>

void output_array(int a[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void linear_search(int a[], int size) {
    int n;
    printf("\nEnter n: ");
    scanf("%d", &n);

    int flag = 0; 
    for (int i = 0; i < size; i++) {
        if (a[i] == n) {
            printf("Entered element %d found at index %d\n", a[i], i);
            flag = 1; 
        }
    }

    if (flag == 0) {
        printf("Entered element %d not found in the array\n", n);
    }
}

void reverse_array(int a[], int size) 
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
    output_array(a, size);
}

void update_array(int a[], int size) {
    printf("Updated array: ");
    for (int i = 0; i < size; i++) 
    {
        if (i % 2 == 0)
            a[i] *= 2;
        else
            a[i] += 5;
    }

    output_array(a, size);
}

void insert_element(int **a, int *size ) {
    int index, element;
    printf("Enter index you want to insert element in: ");
    scanf("%d", &index);

    printf("Enter element you want to insert: ");
    scanf("%d", &element);

    (*size)++;
    *a = realloc(*a,(*size)*sizeof(int));

    for (int i = *size - 1; i > index; i--) {
        (*a)[i] = (*a)[i - 1];
    }
    (*a)[index] = element;

    printf("Array after insertion:\n");
    output_array(*a, *size);
}

void delete_element(int **a, int *size) {
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
        (*a)[i] = (*a)[i + 1];
    }

    (*size)--;

    printf("Array after deletion:\n");
    output_array(*a, *size);
}

int main(void) 
{
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);

    int* a = (int*)malloc(size*sizeof(int));
    
    printf("Enter elements in the array: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &a[i]);
    }

    output_array(a, size);

    int choice;

    do {
        printf("\n Menu:\n");
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
                linear_search(a, size);
                break;
            case 2:
                reverse_array(a, size);
                break;
            case 3:
                update_array(a, size);
                break;
            case 4:
                insert_element(&a, &size);
                break;
            case 5:
                delete_element(&a,&size);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

    } 
    while (choice != 6);

    free(a);
}