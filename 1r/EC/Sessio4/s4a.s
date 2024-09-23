	.data
signe:		.word 0			#0x10010000
exponent:	.word 0			#0x10010004
mantissa:	.word 0			#0x10010008
cfixa:		.word 0x10000001	#0x1001000C
cflotant:	.float 0.0		#0x10010010

	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)

	la	$t0, cfixa
	lw	$a0, 0($t0)
	la	$a1, signe
	la	$a2, exponent
	la	$a3, mantissa
	jal	descompon

	la	$a0, signe
	lw	$a0,0($a0)
	la	$a1, exponent
	lw	$a1,0($a1)
	la	$a2, mantissa
	lw	$a2,0($a2)
	jal	compon

	la	$t0, cflotant
	swc1	$f0, 0($t0)

	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr	$ra


descompon:
	addiu 	$sp, $sp, -4
	sw	$ra, 0($sp)

	slt	$t0, $a0, $zero
	sw	$t0, 0($a1)	#we store in *s cf<0
	sll	$a0, $a0, 1
if:	
	bne	$a0, $zero, else
	move	$t2, $zero	#$t2 contains 'exp'
	b 	endif
else:
	li	$t2, 18
loop:
	blt 	$a0, $zero, end_loop
	sll	$a0, $a0, 1
	addiu	$t2, $t2, -1
	b 	loop
end_loop:
	srl	$a0, $a0, 8
	li	$t0, 0x7FFFFF
	and	$a0, $a0, $t0
	addiu	$t2, $t2, 127
endif:
	sw	$t2, 0($a2)	#we store in *e exp
	sw	$a0, 0($a3)	#we store in *m cf
	
	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	
	jr 	$ra

compon:
	addiu 	$sp, $sp, -4
	sw 	$ra, 0($sp)

	sll	$a0, $a0, 31
	sll	$a1, $a1, 23
	or	$v0, $a0, $a1
	or	$v0, $v0, $a2
	mtc1	$v0, $f0
	
	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	
	jr	$ra
	

