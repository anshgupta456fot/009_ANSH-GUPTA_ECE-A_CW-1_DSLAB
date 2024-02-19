#include <iostream>

void output_array(int a[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void linear_search(int a[], int size) {
    int n;
    std::cout << "\nEnter n: ";
    std::cin >> n;

    int flag = 0; 
    for (int i = 0; i < size; i++) {
        if (a[i] == n) {
            std::cout << "Entered element " << a[i] << " found at index " << i << std::endl;
            flag = 1; 
        }
    }

    if (flag == 0) {
        std::cout << "Entered element " << n << " not found in the array" << std::endl;
    }
}

void reverse_array(int a[], int size) {
    int i = 0, j = size - 1;

    while (j > i) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }

    std::cout << "Reversed array: ";
    output_array(a, size);
}

void update_array(int a[], int size) {
    std::cout << "Updated array: ";
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            a[i] *= 2;
        else
            a[i] += 5;
    }

    output_array(a, size);
}

void insert_element(int a[], int& size) {
    int index, element;
    std::cout << "Enter index you want to insert element in: ";
    std::cin >> index;

    std::cout << "Enter element you want to insert: ";
    std::cin >> element;

    size++;

    for (int i = size - 1; i > index; i--) {
        a[i] = a[i - 1];
    }
    a[index] = element;

    std::cout << "Array after insertion:" << std::endl;
    output_array(a, size);
}

void delete_element(int a[], int& size) {
    int index;
    std::cout << "Enter index to be deleted: ";
    std::cin >> index;

    if (index < 0 || index >= size) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        a[i] = a[i + 1];
    }

    size--;

    std::cout << "Array after deletion:" << std::endl;
    output_array(a, size);
}

int main(void) 
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    int* a = new int[size];

    std::cout << "Enter elements in the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> a[i];
    }

    output_array(a, size);

    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Linear Search\n";
        std::cout << "2. Reverse Array\n";
        std::cout << "3. Update Array\n";
        std::cout << "4. Insert Element\n";
        std::cout << "5. Delete Element\n";
        std::cout << "6. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

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
                insert_element(a, size);
                break;
            case 5:
                delete_element(a, size);
                break;
            case 6:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                break;
        }

    } while (choice != 6);

    delete[] a; 
}