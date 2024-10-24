

main:

	li $v0, 5
	syscall 
	move $t0, $v0
	
	li $t1, 9
	li $t2, 5
	mul $t3, $t1, $t0
	div $t0, $t3, $t2
	li $t1, 32
	add $a0, $t0, $t1
	
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall 
	