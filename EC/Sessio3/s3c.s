	# Sessio 3

	.data 
mat:	.word 0,0,2,0,0,0
	.word 0,0,4,0,0,0
	.word 0,0,6,0,0,0
	.word 0,0,8,0,0,0

resultat: .space 4

	.text 
	.globl main
main:
	addiu	$sp, $sp, -4		#Create cushion to store the return address
	sw 	$ra, 0($sp)
	
	la 	$a0, mat		#Load arguments with correct values
	jal 	suma_col		#Call the function
	la 	$s0, resultat		#The function returns a value that is stored in $v0
	sw	$v0, 0($s0)		#Store the returned value in the variable "resultat"
	
	lw	$ra, 0($sp)		#Recuperate the return address and eliminate the activation block
	addiu	$sp, $sp, 4
	jr	$ra

suma_col:
	addiu	$sp, $sp, -20		#Create new cushion to store the secure registries
	sw	$s0, 0($sp)
	sw	$s1, 4($sp)
	sw	$s2, 8($sp)
	sw	$s3, 12($sp)
	sw	$ra, 16($sp)
	
#i and suma are elemental variables, therefore they don't need to be stored in the memory
	move 	$s0, $a0		#$s0 = @mat[0][0] or @mat
	move	$s1, $zero		#$s1 = 0; s1 is the counter for the loop
	move	$s2, $zero		#$s2 = 0; s2 represents "suma"
	
	la 	$t0, mat		#$t0 = @mat
	addiu	$s3, $t0, 8		#$s3 = @mat[0][2]
	li 	$t0, 4			#Used for the comparison at the start of the loop

for:
	bge	$s1, $t0, end_for
	lw 	$t1, 0($s3)
	addu	$s2, $s2, $t1
	addiu	$s3, $s3, 24
	addiu	$s1, $s1, 1
	b for

end_for:
	move	$v0, $s2		#Store the sum in the correct registry before its contents are corrupted
	lw	$s0, 0($sp)		#Remove the cushion created at the start of the function
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw	$s3, 12($sp)
	lw	$ra, 16($sp)
	addiu	$sp, $sp, 20
	jr	$ra			#Return to the previous function
	
	