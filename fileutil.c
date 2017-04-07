#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>


int filesize(char *filename) {
        // Definicion e inicializacion de variables
        FILE *fp;
        int count = 0;

        // Se abre el archivo y se contara caracter por caracter el numero
        // de bytes del archivo
        fp = fopen(filename,"r");
        if (fp == NULL) {
                perror("filesize - No se pudo abrir archivo\n");
                return -1;
        }
        while (fgetc(fp) != EOF) {
                count++;
        }
        fclose(fp);
        return count;
}

// Funcion list recibo una ruta a un directoria y de este sacara la cantidad de archivos que hay y el peso de todos ellos usand o la funcion
// file size, esta función imprimirá en pantalla los codigos de estudiantes con sus rnombres el peso y la cantidad de archivos que hay en el directorio
char ** list(char* path) {
//int * arreglo1;
struct dirent *directory;
DIR *pdirectory;
struct stat fileinfo;
int contador = 0;
char **arreglo;
char * concatenador;
int contador2 = 0;
arreglo = (char **)malloc(250*sizeof(char **));
//arreglo1 = (int *) malloc(2 * sizeof(int *));


if ((pdirectory = opendir(path)) == NULL) {

            printf("Error: Unable to open directory\n");
            exit(0);
    }

    chdir(path);
    while ((directory=readdir(pdirectory)) != NULL)
    {

        if (!stat(directory->d_name,&fileinfo))
        {
            if (S_ISREG(fileinfo.st_mode))
            {
				concatenador = (char *)malloc(strlen(path)+1+strlen(directory->d_name) * sizeof(char *));
              strcpy(concatenador,path);
              strcat(concatenador,"/");
              strcat(concatenador,directory->d_name);
              contador++;
              arreglo[contador] = (char *)malloc(sizeof(char) * strlen(directory->d_name));
              arreglo[contador] = concatenador;

              //printf("File Name:              %s\n",arreglo[contador]);
              //contador2 = contador2 + filesize(concatenador);

            }
            }


    }
   // printf("Estudiante_1: 1531441-Jhoam Sebastian Molina\n");
   // printf("Estudiante_2: 1710074-Natalia Lenis Castillo\n");
  //  arreglo1[0] = contador2;
  //  arreglo1[1] = contador;
closedir(pdirectory);

    return arreglo;

        

   }

int archivos(char* path) {

struct dirent *directory;
DIR *pdirectory;
struct stat fileinfo;
int contador = 0;

if ((pdirectory = opendir(path)) == NULL) {

            printf("Error: Unable to open directory\n");
            exit(0);
    }

    chdir(path);
    while ((directory=readdir(pdirectory)) != NULL)
    {

        if (!stat(directory->d_name,&fileinfo))
        {
            if (S_ISREG(fileinfo.st_mode))
            {
				contador++;
			}
		}
	}
	closedir(pdirectory);
    return contador;
}


