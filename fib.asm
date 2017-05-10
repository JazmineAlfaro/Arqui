## minmax.a - imprime los valores maximos y minimos de un arreglo de

## enteros.

##

## Asume que el arreglo tiene al menos dos elementos (a[0],a[1]).

## Se inicializa como minimo y maximo a[0]

## despues con ayuda de instrucciones de bifurcacion hace un recorrido

## que recorre el arreglo.

##

## t0 - apunta a los elementos del arreglo

## t1 - contiene la cuanta de elementos

## t2 - contiene min

## t3 - contiene max

## t4 - para cada palabra del arreglo en cada iteracion

##

#################################################

# text segment #

#################################################

.text # Aqui empieza el segmento de codigo

.globl __start

__start:

la $a0, ask1

li $v0, 4

syscall

li $v0, 5

syscall

move $t1, $v0 # sale del bucle cuando $t1 es 0

move $t3, $v0 #guardando el numero ingresado

lw $t0,($zero) # inicializa fib de 0 ($t2) con 0

add $t1, $t0, 1 # fib de 1 = 1

loop:

add $t2, $t0, $t1 #se suma y se guarda en $t2

move $t0, ($t1) # t0 = t1

move $t1, ($t2) # incrementa el puntero una palabra

bnez $t1,loop # y continua si contador>0

move $a0, $t3 # cuando termina el bucle imprime respuestas

li $v0,1

syscall

move $a0,$t3

li $v0,1

syscall # imprime el valor del input

move $a0,$t2

li $v0,1

syscall # imprime el fibonacci

la $a0,endl # imprime un salto de linea

li $v0,4

syscall

li $v0,10

syscall # fin del programa...

#################################################

# data segment #

#################################################

.data # Aqui empieza el segmento de datos

#count: .word 15

endl: .asciiz "\n"

##

## fin de archivo