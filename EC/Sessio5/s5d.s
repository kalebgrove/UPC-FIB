	.data	
V1:     .space  64
M:      .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
V2:     .word   -5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10

	.text
	.globl main
	
main:
	li 	$s0, 0 		# $s0 = k
	la	$t0, M		# $t0 = @M[0][0]
	la	$t1, V2		# $t1 = @V2[0]
	la	$t2, V1		# $t2 = @V1[0]
	li	$t3, 4
	li 	$t4, 16

fork:
	bge	$s0, $t3, end_fork
	li	$s1, 0		# $s1 = i

fori:
        bge     $s1, $t4, end_fori
	li 	$t5, 0		# $t5 = tmp
	li	$s2, 0		# $s2 = j
        
forj:
        bge     $s2, $t3, end_forj
        sll	$t6, $s0, 2	# $t6 = 4*k
        addu	$t6, $t6, $s2	# $t6 = 4*k+j
        sll	$t6, $t6, 2	# $t6 = 4*(4*k+j) We adjust the value by multiplying times the number of bytes (4)
        sll	$t7, $s1, 6	# $t7 = 4*(i*16) The formula of random access to a matrix is i*NumCol*NumBytes + Col*NumBytes
        addu	$t8, $t1, $t6	# $t8 = @V2[4*k+j]
        lw	$t8, 0($t8)	# $t8 = V2[4*k+j]
        addu	$t7, $t7, $t6
        addu 	$t7, $t7, $t0	# $t7 = @M[i][4*k+j]
        lw	$t7, 0($t7)
        
        mult	$t7, $t8
        mflo	$t7
        
        addu 	$t5, $t5, $t7
        
        addiu   $s2, $s2, 1
        b       forj
        
end_forj:
	sll	$t9, $s1, 2
	addu	$t9, $t9, $t2
	lw	$t6, 0($t9)
	addu	$t6, $t6, $t5
        sw      $t6, 0($t9)
        
        addiu   $s1, $s1, 1
        b       fori
end_fori:
	addiu	$s0, $s0, 1
	b	fork

end_fork:
	jr	$ra

