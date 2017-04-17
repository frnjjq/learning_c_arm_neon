/* sum.s
 * Sum mustreplace and do the same as
 * before
 */

.data

.text

.globl _sumArray
_sumArray:
    VLD1.8  Q0, [R1]
    VLD1.8  Q1, [R2]

    VADD.I8 Q0 Q0, Q1

    VST1.8  Q0, [R3]

    MOV     R0, #0x0000
    RET
