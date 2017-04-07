# Aplicacion intensiva en el manejo de I/O
En este repositorio se encuentran los archivos de la implementacion del programa tanto de manera secuencial como la version fork.

## Integrantes
1. Natalia lenis castillo 1710074
2. Sebastian Molina 1531441

## Descripcion
1. Make file: la funcion basica de este archivo consiste en determinar que partes del codigo requieren ser compiladas
2. Fileutil.c: se encuentra  la informacion acerca de las funciones y como  implementarla
3. io:  su funcion es obtener el numero de bytes de los archivos contenidos en el directorio, a traves de un solo proceso el cual invoca tres funciones realizadas en el iofork
4. iofork: Es similar al io, se diferencian en que en el iofork implementamos el uso de la funcion fork, que crea otro proceso.
