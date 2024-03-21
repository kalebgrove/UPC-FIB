	.data
result: .word 0
num:	.byte '7'

	.text
	.globl main
main:
	la $s0, num
	lb $s2, 0($s0)
	la $s1, result
	li $t0, 'a'
	li $t1, 'z'
	li $t2, 'A'
	li $t3, 'Z'

if:	blt $s2, $t0, or
	bgt $s2, $t1, or
	sb $s2, 0($s1)
	b fi
	
or:	blt $s2, $t2, else
	bgt $s2, $t3, else
	sb $s2, 0($s1)
	b fi

else:	li $t0, '0'
	li $t1, '9'
	blt $s2, $t0, else2
	bgt $s2, $t1, else2
	subu $t2, $s0, $t0
	sb $t2, 0($s1)
	b fi

else2:	li $t2, -1
	sb $t2, 0($s1)

fi:	jr $ra

