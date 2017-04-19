/* sum.s
 * Sum mustreplace and do the same as
 * before
 */

.data

.text

.globl _sumArray
_sumArray:
    VLD1.8  D0, [R1]!
    VLD1.8  D1, [R1]

    VLD1.8  D2, [R2]!
    VLD1.8  D3, [R2]

    VADD.I8 Q3, Q0, Q1

    VST1.8  D4, [R3]!
    VST1.8  D5, [R3]!

    MOV     R0, #0x0000
