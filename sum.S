/* sum.s
 * Sum must replace and do the same as
 * before
 */

# A program to be called from a C program
# Declaring data that doesn't change
.section .data


# The actual code
.section .text
.globl _sumArray
.func  _sumArray

_sumArray:
    VLD1.8  D0, [R0]
    VLD1.8  D1, [R0, #+8]

    VLD1.8  D2, [R1]!
    VLD1.8  D3, [R1, #+8]

    VADD.I8 Q3, Q0, Q1

    VST1.8  D4, [R2]!
    VST1.8  D5, [R2, #+8]

    bx       lr

.endfunc
