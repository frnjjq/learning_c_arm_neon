/*
 * Test1_intrinsics.c
 * This test imitates Test1 but it will use AMR NEON intrinsics to
 * perform the calculations required.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <arm_neon.h>
#include <time.h>

#define LENGHT 16

void populateArray( int8_t array[], int8_t number);
void sumArray( int8_t array1[], int8_t array2[], int8_t resultArr[]);
void printResults(int8_t array[]);

int main()
{
    clock_t begin = clock();
    printf("Test 1 instrinsics running\n");

    int8_t array1[LENGHT];
    int8_t array2[LENGHT];
    int8_t result[LENGHT];

    populateArray( array1, 1);
    increasingArray( array2);

    //sumArray( array1, array2, result);
    multArray( array1, array2, result);
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

void increasingArray( int array[])
{
    for(int i = 0; i< LENGHT; i++)
    {
        array[i] = i;
    }
    return;
}

void sumArray( int8_t array1[], int8_t array2[], int8_t resultArr[])
{
    int8x16_t op1; // declare a vector of eight by eight. It has 64 bits so it is a Q register
    int8x16_t op2;
    int8x16_t result;
    op1 = vld1q_s8( array1);
    op2 = vld1q_s8( array2);

    result = vadd_s8( op1, op2);

    vst1_s8( resultArr, result); // store the vector back to memory
    return;
}

void multArray( int array1[], int array2[], int resultArr[])
{
    int8x16_t op1; // declare a vector of eight by eight. It has 64 bits so it is a Q register
    int8x16_t op2;
    int8x16_t result;
    op1 = vld1q_s8( array1);
    op2 = vld1q_s8( array2);

    result = vmul_s8( op1, op2);

    vst1_s8( resultArr, result); // store the vector back to memory
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
