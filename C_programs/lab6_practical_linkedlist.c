#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row, col, value;
    struct Node* next;
};

void displaySparseMatrix(struct Node* head);
struct Node* createSparseMatrix(int matrix[][100], int n, int m);
int isSparse(int matrix[][100], int n, int m);
int main(void) 
{
    int n, m;
    printf("Enter the order of the matrix nXm (n and m): ");
    scanf("%d %d", &n, &m);
    int matrix[n][100];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            printf("enter the value for a%d%d position",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

    if (isSparse(matrix, n, m)) 
    {
        printf("The given matrix is a sparse matrix.\n");
        struct Node* sparseMatrix = createSparseMatrix(matrix, n, m);
        displaySparseMatrix(sparseMatrix);
    } 
    else 
    {
        printf("The given matrix is not a sparse matrix.\n");
    }
}
int isSparse(int matrix[][100], int n, int m) 
{
    int countZero = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            if (matrix[i][j] == 0)
                countZero++;
        }
    }
    return countZero > (n * m) / 2;
}
struct Node* createSparseMatrix(int matrix[][100], int n, int m) 
{
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->row = i;
                newNode->col = j;
                newNode->value = matrix[i][j];
                newNode->next = NULL;
                if (head == NULL) 
                {
                    head = newNode;
                } 
                else 
                {
                    struct Node* temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newNode;
                }
            }
        }
    }
    return head;
}
void displaySparseMatrix(struct Node* head) 
{
    struct Node* temp = head;
    printf("Sparse Matrix (row, col, value):\n");
    while (temp != NULL) 
    {
        printf("(%d, %d, %d)\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}