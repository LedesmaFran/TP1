#include <stdio.h>

//Todos los valores de los "defines" estan entre parentesis para 
//protegerlos de un error de precedencia

#define		NO_ARGUMENTS	(1)			//Valor de argc cuando se ejecuta el programa sin argumentos
#define		SINTAX_ERROR	(-1)		//Valor que devuleve si hubo error de sintaxis
#define		EMPTY_ARGS		(SINTAX_ERROR-1)	//Valor que devuleve parseCmdLine si no se ingresaron argumentos
#define		OVERFLOW_ARGS	(EMPTY_ARGS-1)		//Valor que devuleve parseCmdLine si se excedieron los argumentos
#define		MAX_ARGS		(5000)				//Valor maximo de argumentos de entrada


typedef int (*pCallback) (char *, char *, void *);			//Declaracion de la funcion de callback (se encuentra en main.c)
int			parseCmdLine (int, char **, pCallback, void *);	//Declaracion de la funcion de parseo de los argumentos