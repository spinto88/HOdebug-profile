
Compilamos la funcion profile_me1.c con distintos niveles de optimizacion:

midiendo el tiempo de corrida con time ./program.e, el tiempo con -O0 
fue de 0.623 s, con -O1 se redujo a la mitad, y con -O2 y -O3 se redujo
a practicamente 0.

Haciendo un profiling con perf y gprof, encontramos que con los niveles 
-O0 -O1 la funcion first assigment ocuapaba aproximadamente entre
el 50% y 60% del tiempo, seccond assigment alrededor del 20 %.
Lo que vimos es q first assigment asigna valores saltando entre 
espacios de memoria no contiguos, mientras q second_assigment lo
hace en forma secuencial, lo cual lo hace mas rápido.

Con niveles de optimizacion mas alto, creemos que las funciones 
se integran al main, evitando la llamada a funciones externas,
lo cual hace que el tiempo de ejecucion se reduzca drasticamente,
como vimos en el profiling donde las llamadas a las funciones 
desaparecieron, llamando solo a main.

En profile_me2.c no vemos ninguna diferencia al utilizar gprof,
se ve que no es una herramienta adecuada en este ejemplo ya que no vemos
las funciones separadas.
Con perf obtenemos la siguiente salida con -O0:

```
 43,69%  programa.e  programa.e         [.] main
 14,30%  programa.e  libm-2.19.so       [.] __sin_avx
 14,01%  programa.e  libm-2.19.so       [.] __ieee754_exp_avx
  8,50%  programa.e  libm-2.19.so       [.] __kernel_standard
  7,09%  programa.e  libm-2.19.so       [.] __sqrt
  6,89%  programa.e  [kernel.kallsyms]  [k] 0xffffffff8104f45a
  4,88%  programa.e  libm-2.19.so       [.] __GI___exp
  0,65%  programa.e  programa.e         [.] sqrt@plt

```

y con -O3:

```
 44,47%  programa.e  programa.e         [.] main
 17,85%  programa.e  libm-2.19.so       [.] __sin_avx
 13,83%  programa.e  libm-2.19.so       [.] __ieee754_exp_avx
  9,61%  programa.e  [kernel.kallsyms]  [k] 0xffffffff8104f45a
  7,80%  programa.e  libm-2.19.so       [.] __GI___exp
  6,44%  programa.e  libm-2.19.so       [.] __kernel_standard
```

En el ultimo nivel de optimizacion no se observa la funcion sqrt,
se ve que al optimizar deja de llamarla externamente incluyendola
en el main.



