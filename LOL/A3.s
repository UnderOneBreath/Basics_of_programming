.text
main:
    lw $s0, f
    lw $s1, x
    lw $s2, y
    lw $s3, z
    la $s6, A
    la $s7, B
# a)
    # add $t0, $s1, $s2 # x + y
    # add $t1, $s3, $s3 # z + z
    # sub $t2, $t0, $t1 # x+y-2z
    # sw $t2, f # f = x + y - 2*z
# b)
    lw $t0, 28($s6) #A[7] 
    add $t0, $s1, $t0 # x + A[7]
    addi $t0, $t0, 29 # x + A[7] + 29
    sw $t0, f # f = x + A[7] + 29
.data
    f: .word 1
    x: .word 7
    y: .word 6
    z: .word 5
    A: .word 1:104
    B: .word 1:12