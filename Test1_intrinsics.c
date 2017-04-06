/*
 * Test1_intrinsics.c
 * This test imitates Test1 but it will use AMR NEON intrinsics to
 * perform the calculations required.
 */

#include <stdio.h>
#include <neon_arm.h>

void populateArray(int array[], int lenght);
int sumArray(int array[], int lenght);
void printResults(int array[], int *sum, int lenght);

int main()
{
    printf("Test1_instrinsics on the Go!\n");
    int lenght = 6;
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
    uint8x8 start_value = vreinterpret_u8_u64(vcreate_u64(0x123456789ABCDEFULL))


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
