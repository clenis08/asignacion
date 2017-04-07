#include <stdio.h>
#include "fileutil.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv)
{	

	char ** arreglo1;
	int length;
	arreglo1 = (char **) malloc(5000 * sizeof(char *));
	length = archivos(argv[1]);
    arreglo1 = list(argv[1]);
	int i, count;	
	int pid;
	int fd[2];
	count = 0;
	
	pipe(fd);
	if (pid = fork()) {
		int counth;
		close(fd[1]);
		for (i = 1; i <= length/2;i++) {
			count = count + filesize(arreglo1[i]);
		}	
		printf("Estudiante_1: 1531441-Jhoam Sebastian Molina\n");
 	    printf("Estudiante_2: 1710074-Natalia Lenis Castillo\n");
		printf("Total de archivos:    %d\n",length);
		printf("[%d] conto:      %d bytes\n",getpid(),count);
		printf("Esperando por %d\n",pid);
		read(fd[0],&counth,sizeof(counth));
		printf("%d bytes + %d bytes = %d bytes\n", counth, count, counth + count);
	}else {
				
		close(fd[0]);
		for (i = length/2 + 1;i <= length;i++){

		count = count + filesize(arreglo1[i]);
		}
		printf("[%d] conto:       %d bytes\n",getpid(),count);
		write(fd[1],&count,sizeof(count));
}

return 0;

		}








