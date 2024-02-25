#include <stdio.h>

int binarySearch(int arr[], int r, int z);
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40, 50 };
	int n = sizeof(arr) / sizeof(arr[0]);
    int z;
    printf("Enter the element to be searched");
    scanf("%d",&z);
	int result = binarySearch(arr, n - 1, z);
	(result == -1) ? printf("Element is not present in array"): printf("Element is present at index %d",result);
}

int binarySearch(int arr[], int r, int z)
{
    int l = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (arr[m] == z)
        {
            return m;
        }
		if (arr[m] < z)
        {
            l = m + 1;
        }
		else
        {
            r = m - 1;
        }
	}
	return -1;
}
