	.data
vector: .space 400

	.text
	.globl main
main:
        move    $t1, $zero          # $t1 = sum
        la      $t2, vector         # $t2 = @vector[i]
        move    $t0, $zero          # $t0 = i
        li      $t3, 100
for:
        bge     $t0, $t3, fi
        lw      $t4, 0($t2)
        addu    $t1, $t1, $t4
        addiu   $t2, $t2, 4
        addiu   $t0, $t0, 1
        b       for
fi:
	jr	$ra



