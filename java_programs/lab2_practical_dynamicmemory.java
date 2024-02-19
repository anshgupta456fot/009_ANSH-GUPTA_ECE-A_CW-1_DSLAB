import java.util.Scanner;

public class lab2_practical_dynamicmemory {
    public static void outputArray(int[] a) {
        System.out.print("Array elements: ");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public static void linearSearch(int[] a) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter n: ");
        int n = scanner.nextInt();
        boolean found = false;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == n) {
                System.out.println("Entered element " + a[i] + " found at index " + i);
                found = true;
            }
        }
        if (!found) {
            System.out.println("Entered element " + n + " not found in the array");
        }
    }

    public static void reverseArray(int[] a) {
        for (int i = 0, j = a.length - 1; j > i; i++, j--) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        System.out.print("Reversed array: ");
        outputArray(a);
    }

    public static void updateArray(int[] a) {
        System.out.print("Updated array: ");
        for (int i = 0; i < a.length; i++) {
            if (i % 2 == 0)
                a[i] *= 2;
            else
                a[i] += 5;
        }
        outputArray(a);
    }

    public static int[] insertElement(int[] a, int index, int element) {
        int[] newArray = new int[a.length + 1];
        for (int i = 0; i < index; i++) {
            newArray[i] = a[i];
        }
        newArray[index] = element;
        for (int i = index; i < a.length; i++) {
            newArray[i + 1] = a[i];
        }
        System.out.println("Array after insertion:");
        outputArray(newArray);
        return newArray;
    }

    public static int[] deleteElement(int[] a, int index) {
        int[] newArray = new int[a.length - 1];
        for (int i = 0; i < index; i++) {
            newArray[i] = a[i];
        }
        for (int i = index + 1; i < a.length; i++) {
            newArray[i - 1] = a[i];
        }
        System.out.println("Array after deletion:");
        outputArray(newArray);
        return newArray;
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int size = scanner.nextInt();
        int[] a = new int[size];
        System.out.print("Enter elements in the array: ");
        for (int i = 0; i < size; i++) {
            a[i] = scanner.nextInt();
        }
        outputArray(a);

        int choice;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Linear Search");
            System.out.println("2. Reverse Array");
            System.out.println("3. Update Array");
            System.out.println("4. Insert Element");
            System.out.println("5. Delete Element");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    linearSearch(a);
                    break;
                case 2:
                    reverseArray(a);
                    break;
                case 3:
                    updateArray(a);
                    break;
                case 4:
                    System.out.print("Enter index you want to insert element in: ");
                    int index = scanner.nextInt();
                    System.out.print("Enter element you want to insert: ");
                    int element = scanner.nextInt();
                    a = insertElement(a, index, element);
                    break;
                case 5:
                    System.out.print("Enter index to be deleted: ");
                    int delIndex = scanner.nextInt();
                    a = deleteElement(a, delIndex);
                    break;
                case 6:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
                    break;
            }
        } while (choice != 6);
        scanner.close();
    }
}
