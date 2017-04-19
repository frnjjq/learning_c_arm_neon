
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define LENGHT 16

void populateArray( int array[], int number);
void increasingArray( int array[]);
void sumArray( int array1[], int array2[], int resultArr[]);
void _sumArray( int array1[], int array2[], int resultArr[]);
void multArray( int array1[], int array2[], int resultArr[]);
void printResults(int array[]);

int main()
{
    clock_t begin = clock();
    printf("Test 1 running\n");

    int array1[LENGHT];
    int array2[LENGHT];
    int result[LENGHT];

    populateArray( array1, 8);
    increasingArray( array2);

    //sumArray( array1, array2, result);
    //multArray( array1, array2, result);
    printf("Calling ASM");
    _sumArray( array1, array2, result);
    printf("fINISHED asm ASM");
    printResults( result);

    clock_t end = clock();
    printf("Finished execution. Duration: %f ms\n",(double)(end - begin)*1000 / CLOCKS_PER_SEC);
    return 0;
}

void populateArray(int array[], int number)
{
    for(int i = 0; i< LENGHT; i++)
    {
        array[i] = number;
    }
    return;
}

void increasingArray( int array[])
{
    for(int i = 0; i< LENGHT; i++)
    {
        array[i] = i;
    }
    return;
}

void sumArray( int array1[], int array2[], int resultArr[])
{
    for(int i = 0; i< LENGHT; i++)
    {
        resultArr[i] = array1[i] + array2[i];
    }
    return;
}

void multArray( int array1[], int array2[], int resultArr[])
{
    for(int i = 0; i< LENGHT; i++)
    {
        resultArr[i] = array1[i] * array2[i];
    }
    return;
}

void printResults(int array[])
{
    printf("Printing Results!\n");
    for(int i = 0; i< LENGHT; i++)
    {
        printf("Array[%d] = %d\n", i, array[i]);
    }
    return;
}
