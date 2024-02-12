import java.util.*;
public class binarysearch_recursive 
{
    int binarySearch(int arr[], int l, int r, int x) 
    {
        if (r >= l) 
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
            {
                return mid;
            }
            if (arr[mid] > x)
            {
                return binarySearch(arr, l, mid - 1, x);
            }
            else
            {
                return binarySearch(arr, mid + 1, r, x);
            }
        }
        return -1;
    }

    public static void main(String args[]) 
    {
        binarysearch_recursive ob = new binarysearch_recursive();
        int arr[] = {2, 3, 4, 10, 40};
        int n = arr.length;
        Scanner scr = new Scanner(System.in);
        System.out.print("Enter the value to be searched: ");
        int x = scr.nextInt();
        int result = ob.binarySearch(arr, 0, n - 1, x);
        if (result == -1) 
        {
            System.out.println("Element is not present in array");
        } 
        else 
        {
            System.out.println("Element is present at index " + result);
        }
    }
}
