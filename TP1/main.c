#include <stdio.h>
#include "ParseCmdLine.h"

int parseCallback (char *, char *, void *);	 //Declaracion de la funcion de callback

int main(int argc, char *argv[])
{
	char	*UserData[MAX_ARGS];		//Arreglo de strings donde se guardan los parametros
	int		parseCmdLine_Return;		//Variable que almacena el retorno de parseCmdLine

	//banco_de_prueba()
	//Aca pueden ir las funciones de los bancos de pruebas que modifican
	//argc y argv para "imitar" la entrada

	parseCmdLine_Return = parseCmdLine(argc, argv, parseCallback, UserData);	//Invoco al parse y almaceno su retorno

	switch (parseCmdLine_Return)																//Si hubo errores durante la ejecucion																						//de parseCmdLine se muestra en pantalla
	{																							//su origen
		case EMPTY_ARGS: printf("No ha ingresado ningun argumento en linea de comandos\n");
						 break;

		case OVERFLOW_ARGS: printf("La cantidad de argumentos excede el maximo de %d\n", MAX_ARGS);
							break;

		case SINTAX_ERROR: printf("Su ingreso ha sido incorrecto (Formato: -clave valor // parametro)\n");
						   break;
		default: printf("La suma de las Opciones y Parametros ingresados son: %d\n", parseCmdLine_Return);						//En el caso de una ejecucion
																									//exitosa, muestra la cantidad
																									//de argumentos
	}


	return 0;
}


int parseCallback(char *key, char *value, void *UserData)
{
	/*
	printf("key: %s\n", key);
	printf("value: %s\n", value);
	*/
	if (key == NULL)
	{
		//Guardar value en UserData, ya que lo que ingreso
		//es un parámetro
		return 1;	//Interpretacion correcta
	}
	if (key != NULL && value != NULL && (*value) != '-')
	{
		//Guardar key (sin el guion) y value en UserData, ya que lo que ingreso
		//es una clave con un valor
		return 1;	//Interpretacion correcta
	}
	if (key != NULL && value == NULL)
	{
		if(NULL == (void*)*(key + 1))
		{
			printf("%c\n", *(key + 1));
			printf("opcion sin clave\n");
		}
		else
		{
			printf("Opcion %s sin valor\n", key);
		}
			
		return 0; //si tengo una clave sin valor, devuelvo 0
	}
	printf("Opcion %s sin valor\n", key);
	return 0;
}