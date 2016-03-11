
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


En profile_me2.c no vemos ninguna diferencia en el 
tiempo de ejecución al cambiar los distintos niveles
de optimizacion, y en el profiling no vemos las funciones separadas.


