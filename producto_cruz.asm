.text
.globl __start
__start:

lw $t0, tam # guardas tam en t0

la $t2, vector1
la $t3, vector2


cruz:
addi $t2,$t2,4
addi $t3,$t3,8
l.s $f5, ($t2)
l.s $f6, ($t3)
mul.s $f7,$f5,$f6
add.s $f8, $f8, $f7

addi $t2,$t2,4
addi $t3,$t3,-4
l.s $f5, ($t2)
l.s $f6, ($t3)
mul.s $f7,$f5,$f6
sub.s $f8, $f8, $f7

addi $t2,$t2,-8
addi $t3,$t3,4
l.s $f5, ($t2)
l.s $f6, ($t3)
mul.s $f7,$f5,$f6
add.s $f9, $f9, $f7

addi $t2,$t2,8
addi $t3,$t3,-8
l.s $f5, ($t2)
l.s $f6, ($t3)
mul.s $f7,$f5,$f6
sub.s $f9, $f9, $f7

addi $t2,$t2,-8
addi $t3,$t3,4
l.s $f5, ($t2)
l.s $f6, ($t3)
mul.s $f7,$f5,$f6
add.s $f10, $f10, $f7


addi $t2,$t2,4
addi $t3,$t3,-4
l.s $f5, ($t2)
l.s $f6, ($t3)
mul.s $f7,$f5,$f6
sub.s $f10, $f10, $f7


li $v0, 4
la $a0, print2
syscall # imprime_print2
li $v0, 4
la $a0, space
syscall # imprime_espacio
li $v0,2
mov.s $f12,$f8
syscall 
li $v0, 4
la $a0, space
syscall # imprime_espacio
li $v0,2
mov.s $f12,$f9
syscall 
li $v0, 4
la $a0, space
syscall # imprime_espacio
li $v0,2
mov.s $f12,$f10
syscall 



li $v0, 10 
syscall # termina_programa

######################################

.data
tam: .word 3
vector1: .float 2.1,1.5,1.1
vector2: .float 1.7,3.2,0.2
print1: .asciiz "El producto escalar es: "
print2: .asciiz "\nEl producto vectorial es: "
space: .asciiz "\n"



