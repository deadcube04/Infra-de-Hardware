	.data

quant: 	.float 2.0
media: 	.float 7.0
minFreq:.float 75.0
pass: 	.asciiz "\nAprovado"
nopass:	.asciiz "\nReprovado "
string1:.asciiz "Media = "
label1:	.asciiz "Insira as Notas do aluno:\n"
label2:	.asciiz "Insira a frequencia do aluno:\n"
	.text
main:	
	
	
	la	$a0, label1
	li 	$v0, 4
	syscall
	
	li 	$v0, 6
	syscall 
	
	mov.s 	$f1, $f0 	#nota 1
	li 	$v0, 6
	syscall
	mov.s 	$f2, $f0 	#nota 2
	
	la	$a0, label2
	li 	$v0, 4
	syscall
	
	li 	$v0, 6
	syscall 
	mov.s 	$f3, $f0 	#frequencia
	
	#---------------------------
	
	add.s  	$f4, $f1, $f2
	l.s 	$f1, quant
	div.s 	$f12, $f4, $f1
	
	la	$a0, string1
	li 	$v0, 4
	syscall
	li 	$v0, 2
	syscall
	
	mov.s $f2, $f12
	l.s $f1, media
	c.le.s $f1, $f2
	bc1f else
	l.s $f1, minFreq
	c.le.s $f1, $f3
	bc1f else
	la	$a0, pass
	li 	$v0, 4
	syscall
	j end_else
	
else:
	la	$a0, nopass
	la 	$v0, 4
	syscall
end_else:
	
	li 	$v0, 10
	syscall