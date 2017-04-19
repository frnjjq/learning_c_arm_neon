
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define LENGHT 16

void populateArray( int8_t array[], int8_t number);
void increasingArray( int8_t array[]);
void sumArray( int8_t array1[], int8_t array2[], int8_t resultArr[]);
extern void _sumArray( int8_t array1[], int8_t array2[], int8_t resultArr[]);
void multArray( int8_t array1[], int8_t array2[], int8_t resultArr[]);
void printResults(int8_t array[]);

int main()
{
    clock_t begin = clock();
    printf("Test 1 running\n");

    int8_t array1[LENGHT];
    int8_t array2[LENGHT];
    int8_t result[LENGHT];

    populateArray( array1, 8);
    increasingArray( array2);

    //sumArray( array1, array2, result);
    //multArray( array1, array2, result);
    printf("Calling ASM\n");
    _sumArray( array1, array2, result);
    printf("Finished ASM part\n");
    printResults( result);

    clock_t end = clock();
    printf("Finished execution. Duration: %f ms\n",(double)(end - begin)*1000 / CLOCKS_PER_SEC);
    return 0;
}

void populateArray(int8_t array[], int8_t number)
{
    for(int i = 0; i< LENGHT; i++)
    {
        array[i] = number;
    }
    return;
}

void increasingArray( int8_t array[])
{
    for(int i = 0; i< LENGHT; i++)
    {
        array[i] = i;
    }
    return;
}

void sumArray( int8_t array1[], int8_t array2[], int8_t resultArr[])
{
    for(int i = 0; i< LENGHT; i++)
    {
        resultArr[i] = array1[i] + array2[i];
    }
    return;
}

void multArray( int8_t array1[], int8_t array2[], int8_t resultArr[])
{
    for(int i = 0; i< LENGHT; i++)
    {
        resultArr[i] = array1[i] * array2[i];
    }
    return;
}

void printResults(int8_t array[])
{
    printf("Printing Results!\n");
    for(int i = 0; i< LENGHT; i++)
    {
        printf("Array[%d] = %d\n", i, array[i]);
    }
    return;
}
