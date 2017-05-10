.text
.globl __start
__start:
li $v0, 4
la $a0, prmp01
syscall # imprime_"ingrese_radio"
li $v0, 7 
syscall # lee double

la $a0, pi #guardas pi en a0
l.d $f12, 0($a0) # f12 es pi

mul.d $f12, $f12, $f0 # pi * radio
mul.d $f12, $f12, $f0 # (pi * radio) * radio

li $v0, 4 
la $a0, prmp02 
syscall # imprime_"area_circulo_es"
li $v0, 3 
syscall # imprime_area
li $v0, 10 
syscall # termina_programa


.data
pi: .double 3.141592653589793
prmp01: .asciiz "Ingrese radio: "
prmp02: .asciiz "area circulo es: "