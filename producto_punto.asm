.text
.globl __start
__start:

lw $t0, tam # guardas tam en t0
la $t2, vector1
la $t3, vector2

punto:
l.s $f2, ($t2) #vector 1
l.s $f3, ($t3) #vector 2
beqz $t0,imprime1 
mul.s $f4,$f2,$f3 # guardas la multiplicacion en f4
add.s $f1, $f1, $f4  # guardas la multiplicacion en f1
addi $t2,$t2,4 #avanza el puntero en el vector 1
addi $t3,$t3,4  
addi $t0,$t0,-1
j punto

imprime1:
li $v0, 4
la $a0, print1
syscall  # imprime_print1
li $v0,2
mov.s $f12,$f1
syscall 




li $v0, 10 
syscall # termina_programa

######################################

.data
tam: .word 3
vector1: .float 2.1,1.5,1.1
vector2: .float 1.7,3.2,0.2
print1: .asciiz "El producto escalar es: "

