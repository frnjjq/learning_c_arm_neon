/*
 * Test1_intrinsics.c
 * This test imitates Test1 but it will use AMR NEON intrinsics to
 * perform the calculations required.
 */

#include <stdio.h>
#include <stdint.h>
#include <neon_arm.h>


void populateArray(int8_t array[], int8_t lenght);
int sumArray(int8_t array[], int8_t lenght);
void printResults(int8_t array[], int8_t *sum, int8_t lenght);

int main()
{
    printf("Test1_instrinsics on the Go!\n");
    int8_t lenght = 64;
    int8_t array[lenght];
    populateArray( array, lenght);
    int8_t sum = sumArray( array, lenght);
    printResults( array, &sum, lenght);
    printf("Test 1 finished\n");
    return 0;
}

void populateArray(int8_t array[], int8_t lenght)
{
    printf("populateArray called!\n");
    uint8x8_t vector;
    uint8_t subvector[8];

    for(int8_t i = 0; i< lenght/8; i=i+8)
    {
        subvector = {i, i+1, i+2, i+3, i+4, i+5, i+6, i+7};
        vector = vld1_u8(subvector);
        vst1_u8(vector[i], vector);

    }
    return;
}

int8_t sumArray(int8_t array[], int8_t lenght)
{
    printf("sumArray called!\n");
    int8_t sum = 0;
    for(int8_t i = 0; i< lenght; i++)
    {
        sum += array[i];
    }
    return sum;
}

void printResults(int8_t array[], int8_t *sum, int8_t lenght)
{
    printf("printResults called!\n");
    for(int8_t i = 0; i< lenght; i++)
    {
        printf("Line number %d has a value of: %d\n", i, array[i]);
    }
    printf("The total sum of the array is: %d\n", *sum);
    return;
}
