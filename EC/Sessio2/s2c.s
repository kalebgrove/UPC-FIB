	.data
w:        .asciiz "8754830094826456674949263746929"
resultat: .byte 0

	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)
	la	$a0, w
	li	$a1, 31
	jal	moda
	la	$s0, resultat
	sb	$v0, 0($s0)
	move	$a0, $v0
	li	$v0, 11
	syscall
	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr 	$ra

nofares:
	li	$t0, 0x12345678
	move	$t1, $t0
	move	$t2, $t0
	move	$t3, $t0
	move	$t4, $t0
	move 	$t5, $t0
	move	$t6, $t0
	move 	$t7, $t0
	move 	$t8, $t0
	move 	$t9, $t0
	move	$a0, $t0
	move	$a1, $t0
	move	$a2, $t0
	move	$a3, $t0
	jr	$ra

moda:
	addiu 	$sp, $sp, -56	#Store in the stack histo[10] (4 bytes * 10 elements)
	sw 	$s0, 0($sp)
	sw 	$s1, 4($sp)
	sw	$s2, 8($sp)
	sw 	$ra, 52($sp)
	
	move 	$s0, $a0	#$s0 containts the address to vec[0], which is the vector w, necessary later in the program.
	move	$s1, $a1	#$a1 contains num
	
	li 	$t5, 10
	li 	$s2, 0
	addiu 	$t2, $sp, 12	#$t2 contains the address to histo[0], which is necessary for a call later in the program.
for1:	
	bge 	$s2, $t5, fi_for1
	
	sll 	$t1, $s2, 2	#4*k, such that k is the iterator for the for loop
	addu 	$t3, $t3, $t2	#4*k + @histo[0] = @histo[k]
	sw 	$zero, 0($t3)	#histo[k] = 0
	
	addiu 	$s2, $s2, 1
	b for1
fi_for1: 
	li 	$t4, '0'	#t4 is the variable 'max' that will end up being stored in $v0.
	li	$s2, 0		#$s2 is going to be the secure registry that will contain the iterator
	
for2:	
	bge 	$s2, $s1, fi_for2
	
	addiu	$a0, $sp, 12	#We initialize $a0 (*hist) to the correct address.
	addu 	$t1, $s2, $s0	#$t1 = @vec[k]
	lb 	$t1, 0($t1)	#$t2 = vec[k]
	addiu 	$a1, $t1, -48	#$a1 = vec[k] - '0'
	addiu 	$a2, $t4, -48	#$a2 = max - '0'
	
	jal update
	
	addiu 	$t4, $v0, '0'	#max = update + '0'
	addiu 	$s2, $s2, 1
	b for2
	
fi_for2:
	move 	$v0, $t4
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw 	$ra, 52($sp)
	addiu 	$sp, $sp, 56
	jr 	$ra
	
update:
	addiu 	$sp, $sp, -16	#We create enough space to safely store all the arguments that will be used in the function called later.
	sw 	$s0, 0($sp)
	sw 	$s1, 4($sp)
	sw 	$s2, 8($sp)
	sw 	$ra, 12($sp)
	
	move	$s0, $a0	#We move the arguments into secure registries in order to preserve their value.
	move	$s1, $a1	#$s0 = @hist[0], $s1 = i, $s2 = imax
	move	$s2, $a2
	
	jal nofares
	
	sll 	$t0, $s1, 2	#$t0 = i*4
	addu 	$t1, $t0, $s0	#$t1 = @hist[0] + i*4 = @hist[i]
	lw 	$t2, 0($t1)	#$t2 = hist[i]
	addiu 	$t2, $t2, 1	#$t2 = hist[i]++
	sw 	$t2, 0($t1)	#hist[i]++
	sll 	$t3, $s2, 2	#$t3 = imax*4
	addu 	$t3, $t3, $s0	#$t3 = imax*4 + @hist[0] = @hist[imax]
	lw 	$t4, 0($t3)	#$t4 = hist[imax]
if:	
	ble 	$t2, $t4, else
	move 	$v0, $s1
	b endif
else:
	move 	$v0, $s2
endif:	
	lw 	$s0, 0($sp)
	lw 	$s1, 4($sp)
	lw 	$s2, 8($sp)
	lw 	$ra, 12($sp)
	addiu 	$sp, $sp, 16
	jr 	$ra
