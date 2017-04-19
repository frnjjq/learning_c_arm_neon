/* sum.s
 * Sum mustreplace and do the same as
 * before
 */

# A program to be called from a C program
# Declaring data that doesn't change
.section .data


# The actual code
.section .text
.globl _sumArray
.type _sumArray, @function

_sumArray:
    VLD1.8  D0, [R1]!
    VLD1.8  D1, [R1]

    VLD1.8  D2, [R2]!
    VLD1.8  D3, [R2]

    VADD.I8 Q3, Q0, Q1

    VST1.8  D4, [R3]!
    VST1.8  D5, [R3]!

    bx       lr
