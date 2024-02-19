import java.util.Scanner;

public class lab1_practical_staticmemory 
{

    static void outputArray(int[] a, int size) 
    {
        System.out.print("Array elements: ");
        for (int i = 0; i < size; i++) 
        {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    static void linearSearch(int[] a, int size) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter element you want to search: ");
        int n = scanner.nextInt();
        int flag = 0;

        for (int i = 0; i < size; i++) 
        {
            if (a[i] == n) 
            {
                System.out.println("Entered element found at index " + i);
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            System.out.println("Entered element is not found in array");
    }

    static void reverseArray(int[] a, int size) 
    {
        int i = 0, j = size - 1;
        while (j > i) 
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        System.out.print("Reversed array: ");
        outputArray(a, size);
    }

    static void updateArray(int[] a, int size) 
    {
        System.out.print("Updated array: ");
        for (int i = 0; i < size; i++) 
        {
            if (i % 2 == 0)
                a[i] *= 2;
            else
                a[i] += 5;
        }
        outputArray(a, size);
    }

    static void insertElement(int[] a, int[] size) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter index you want to insert element in: ");
        int index = scanner.nextInt();

        System.out.print("Enter element you want to insert: ");
        int element = scanner.nextInt();
        size[0]++;

        for (int i = size[0] - 1; i > index; i--) 
        {
            a[i] = a[i - 1];
        }
        a[index] = element;

        System.out.println("Array after insertion:");
        outputArray(a, size[0]);
    }

    static void deleteElement(int[] a, int[] size) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter index to be deleted: ");
        int index = scanner.nextInt();

        if (index < 0 || index >= size[0]) 
        {
            System.out.println("Invalid index");
            return;
        }

        for (int i = index; i < size[0] - 1; i++) 
        {
            a[i] = a[i + 1];
        }

        size[0]--;

        System.out.println("Array after deletion:");
        outputArray(a, size[0]);
    }

    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int size = scanner.nextInt();
        int[] a = new int[size];

        System.out.print("Enter elements in the array: ");
        for (int i = 0; i < size; i++) 
        {
            a[i] = scanner.nextInt();
        }

        outputArray(a, size);

        int choice;

        do 
        {
            System.out.println("\nMenu:");
            System.out.println("1. Linear Search");
            System.out.println("2. Reverse Array");
            System.out.println("3. Update Array");
            System.out.println("4. Insert Element");
            System.out.println("5. Delete Element");
            System.out.println("6. Exit");

            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) 
            {
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
                    insertElement(a, new int[]{size});
                    break;
                case 5:
                    deleteElement(a, new int[]{size});
                    break;
                case 6:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }

        } while (choice != 6);
    }
}
