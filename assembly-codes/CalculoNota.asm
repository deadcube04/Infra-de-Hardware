	.data

quant: 	.float 2.0
pass: 	.asciiz "Aprovado\n"
nopass:	.asciiz "Reprovado\n"

	.text
main:
	li 	$v0, 6
	syscall 
	mov.s 	$f1, $f0 	#nota 1
	li 	$v0, 6
	syscall
	mov.s 	$f2, $f0 	#nota 2
	li 	$v0, 6
	syscall 
	mov.s 	$f3, $f0 	#frequencia
	
	#---------------------------
	
	add.s  	$f4, $f1, $f2
	l.s 	$f1, quant
	div.s 	$f12, $f4, $f1
	
	
	
	li 	$v0, 2
	syscall
	li 	$v0, 10
	syscall
		
	