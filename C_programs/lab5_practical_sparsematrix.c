#include<stdio.h>

void convertToSparse(int matrix[][100], int n, int m);
int main(void) 
{
    int n, m;
    int non_zero = 0;
    int numberof_zeroes  = 0;
    printf("Enter the order of the matrix nXm (n and m): ");
    scanf("%d %d", &n, &m);
    int matrix[n][100];
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            printf("Enter the element to be entered at the position a%d%d: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nThe entered matrix is:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            if(matrix[i][j] == 0) 
            {
                numberof_zeroes++;
            } else {
                non_zero++;
            }
        }
    }
    if(numberof_zeroes > (m * n) / 2) {
        printf("The given matrix is a sparse matrix\n");
        convertToSparse(matrix, n, m);
    } else {
        printf("The given matrix is not a sparse matrix\n");
    }
}
void convertToSparse(int matrix[][100], int n, int m) 
{
    int non_zero = 0;
    int numberof_zeroes  = 0;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            if(matrix[i][j] == 0) 
            {
                numberof_zeroes++;
            } else {
                non_zero++;
            }
        }
    }
    printf("\nTotal number of elements having zero value is %d\n", numberof_zeroes);
    int arraysparse[3][non_zero];
    int k = 0;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            if(matrix[i][j] != 0) 
            {
                arraysparse[0][k] = i;
                arraysparse[1][k] = j;
                arraysparse[2][k] = matrix[i][j];
                k++;
            }
        }
    }
    printf("\nSparse Representation:\n");
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < non_zero; j++) 
        {
            printf("%d\t", arraysparse[i][j]);
        }
        printf("\n");
    }
}