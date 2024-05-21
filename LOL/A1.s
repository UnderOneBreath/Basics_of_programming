.text
main:
    # g + h - x
    lw $s0, g
    lw $s1, h
    lw $s2, x		
    add $t0, $s0, $s1
    sub $t0, $t0, $s2
    sw $t0, f
.data
    f: .word 0
    g: .word 11
    h: .word 12
    x: .word 18