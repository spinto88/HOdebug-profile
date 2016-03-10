# Debug

Aquí hay cuatro carpetas, cada una con sus ejercicios. Las respuestas a los ejercicios 
tienen que estar en esta carpeta, bajo el nombre `respuestas.md`

## Various bugs

En la carpeta `bugs/` hay varios bugs ya hechos y resueltos, con un `Makefile` que los compila todos

## Floating point exception

En la carpeta `fpe/` hay tres códigos de C, independientes, para compilar. 
Cada uno de estos códigos genera un ejecutable. Hay además una carpeta que
define la función `set_fpe_x87_sse_`. Una vez compilados los tres ejecutables
sin la opción `-DTRAPFPE`, responder las siguientes preguntas:

- ¿Qué función requiere agregar `-DTRAPFPE`? ¿Cómo pueden hacer que el
programa *linkee* adecuadamente?
- Para cada uno de los ejecutables, ¿qué hace agregar la opción `-DTRAPFPE` al compilar? ¿En qué se diferencian 
los mensajes de salida con y sin esa opción?

#Respuestas

Para compilar copie el archivo .c y .h de la carpeta fpe, genere el objeto correspondiente al compilarlo, y luego genere el ejecuble de los archivos test...c linkeando con el objeto creado antes, mas la libreria matematica -lm Con la opcion -DTRAPFPE defino el macro TRAPFPE y al hacer una operación no válida me genera el mensaje "Excepcion de coma flotante". Sin utilizar ese flag el resultado puede dar incorrecto sin saltarme error.


## Segmentation Fault

En la carpeta `sigsegv/` hay códigos de C y de FORTRAN. Elijan alguno
y compilen y corren el programa de acuerdo a los comentarios en el código,
para obtener los ejecutables `small.x` y `big.x`.
Identifiquen los errores que devuelven (¡si devuelven alguno!) los ejecutables.
Ahora ejecuten `ulimit -s unlimited` en la terminal y vuelvan a correrlo. Luego
responder las siguientes preguntas:

- ¿Devuelven el mismo error que antes?
- Averigüen qué hicieron al ejecutar la sentencia `ulimit -s unlimited`. Algunas pistas
son: abran otra terminal distinta y fíjense si vuelve al mismo error, fíjense la diferencia
entre `ulimit -a` antes y después de ejecutar `ulimit -s unlimited`, googleen, etcétera.
- La "solución" anterior, ¿es una solución en el sentido de debugging?

# Respuestas 

Al poner ulimit -s unlimited, el programa no devuelve el error de segmention
fault sino que comienza a correr normalmente. Al hacer eso, estamos poniendo
el espacio de memoria stack ilimitada, por lo tanto las funciones no estan
limitadas en memoria.
No parece ser una solución muy correcta, ya que para q corra un programa
deberiamos avisarle al usuario que primero setee la memoria de stack
ilimitada, lo cual puede depender de si el sistema operativo lo permite.

## Valgrind

En la carpeta `valgrind/` hay ejemplos en C y FORTRAN que se pueden ejecutar
con valgrind. Describan el error y por qué sucede

## Funny

En la carpeta `funny/` hay un código de C. Describan las diferencias de los ejecutables
al compilar con y sin el flag `-DDEBUG`. ¿De dónde vienen esas diferencias?

