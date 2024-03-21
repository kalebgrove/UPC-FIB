	# Sessio 3

	.data 
# Declara aqui les variables mat1, mat4 i col
mat1: 	.space 120
mat4: 	.word 2,3,1,2,4,3
col: 	.word 2

	.text 
	.globl main
main:
	addiu 	$sp, $sp, 4
	sw 	$ra, 0($sp)
	
	la 	$s0, mat1
	addiu 	$s1, $s0, 108  #$s1 = @mat1[4][3]
	la 	$s2, mat4
	addiu 	$s3, $s2, 8  #$s3 = @mat4[0][2]
	move 	$a0, $s2
	lw 	$a1, 0($s3)
	la 	$s4, col
	lw 	$a2, 0($s4)
	jal 	subr
	sw 	$v0, 0($s1)
	move 	$a0, $s2
	li 	$a1, 1
	li 	$a2, 1
	jal 	subr
	sw 	$v0, 0($s0)
	
	lw 	$ra, 0($sp)
	addiu 	$sp, $sp, 4
	jr 	$ra


subr:
	la 	$t0, mat1
	li 	$t1, 6			#$t4 = number of columns
	mult	$t1, $a2		#$lo = 6*j
	mflo	$t1
	addiu	$t1, $t1, 5
	sll 	$t1, $t1, 2		
	addu 	$t1, $t1, $t0		#$t1 = @mat[j][5]
	
	li 	$t2, 3
	mult	$a1, $t2
	mflo	$t2
	addu	$t2, $t2, $a2
	sll	$t2, $t2, 2
	addu	$t2, $t2, $a0		#$t2 = @x[i][j]
	lw 	$t2, 0($t2)		#$t2 = x[i][j]
	sw 	$t2, 0($t1)		#@mat[j][5] = $t2
	move 	$v0, $a1
	
	jr 	$ra


