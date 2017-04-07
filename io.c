#include <stdio.h>
#include <stdlib.h>
#include "fileutil.h"

int main(int argc, char** argv)
{
	char ** arreglo1;
	int length;
	int contador;
	arreglo1 = (char **) malloc(5000 * sizeof(char *));
	length = archivos(argv[1]);
    arreglo1 = list(argv[1]);
	for(int i=1;i<=length;i++){
		
		contador = contador + filesize(arreglo1[i]);
	
	}  
	printf("Estudiante_1: 1531441-Jhoam Sebastian Molina\n");
    printf("Estudiante_2: 1710074-Natalia Lenis Castillo\n");		
	printf("tamaño : %d\n",contador);
    printf("cantidad de archivos :   %d\n", length);
	return 0;
}



