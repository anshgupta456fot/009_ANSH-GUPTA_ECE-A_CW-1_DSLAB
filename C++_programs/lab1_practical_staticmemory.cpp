#include <iostream>
#include <vector>
using namespace std;

void outputArray(const vector<int>& arr) {
    cout << "Array elements: ";
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

void linearSearch(const vector<int>& arr, int n) {
    bool found = false;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == n) {
            cout << "Entered element " << arr[i] << " found at index " << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Entered element " << n << " not found in the array" << endl;
    }
}

void reverseArray(const vector<int>& arr) {
    vector<int> reversedArr(arr.rbegin(), arr.rend());
    cout << "Reversed array: ";
    outputArray(reversedArr);
}

void updateArray(vector<int>& arr) {
    vector<int> updatedArr;
    for (int i = 0; i < arr.size(); ++i) {
        updatedArr.push_back(i % 2 == 0 ? arr[i] * 2 : arr[i] + 5);
    }
    cout << "Updated array: ";
    outputArray(updatedArr);
}

void insertElement(vector<int>& arr) {
    int index, element;
    cout << "Enter index you want to insert element in: ";
    cin >> index;
    cout << "Enter element you want to insert: ";
    cin >> element;

    if (index >= 0 && index <= arr.size()) {
        arr.insert(arr.begin() + index, element);
        cout << "Array after insertion:" << endl;
        outputArray(arr);
    } else {
        cout << "Invalid index" << endl;
    }
}

void deleteElement(vector<int>& arr) {
    int index;
    cout << "Enter index to be deleted: ";
    cin >> index;

    if (index >= 0 && index < arr.size()) {
        arr.erase(arr.begin() + index);
        cout << "Array after deletion:" << endl;
        outputArray(arr);
    } else {
        cout << "Invalid index" << endl;
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    vector<int> arr(size);

    cout << "Enter elements in the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    outputArray(arr);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Linear Search\n";
        cout << "2. Reverse Array\n";
        cout << "3. Update Array\n";
        cout << "4. Insert Element\n";
        cout << "5. Delete Element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int n;
                cout << "Enter n: ";
                cin >> n;
                linearSearch(arr, n);
                break;
            case 2:
                reverseArray(arr);
                break;
            case 3:
                updateArray(arr);
                break;
            case 4:
                insertElement(arr);
                break;
            case 5:
                deleteElement(arr);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }

    } while (choice != 6);

    return 0;
}
