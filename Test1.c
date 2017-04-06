#include <stdio.h>

void populateArray(int array[], int lenght);
int sumArray(int array[], int lenght);
void printResults(int array[], int *sum, int lenght);

int main()
{
    printf("Test 1 on the Go!\n");
    int lenght = 3;
    int array[lenght];
    populateArray( array, lenght);
    int sum = sumArray( array, lenght);
    printResults( array, &sum, lenght);
    printf("Test 1 finished\n");
    return 0;
}

void populateArray(int array[], int lenght)
{
    printf("populateArray called!\n");
    for(int i = 0; i< lenght; i++)
    {
        array[i] = i;
    }
    return;
}

int sumArray(int array[], int lenght)
{
    printf("sumArray called!\n");
    int sum = 0;
    for(int i = 0; i< lenght; i++)
    {
        sum += array[i];
    }
    return sum;
}

void printResults(int array[], int *sum, int lenght)
{
    printf("printResults called!\n");
    for(int i = 0; i< lenght; i++)
    {
        printf("Line number %d has a value of: %d\n", i, array[i]);
    }
    printf("The total sum of the array is: %d\n", *sum);
    return;
}
