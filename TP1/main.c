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
	
	if (parseCmdLine_Return == EMPTY_ARGS)										//Si hubo errores durante la ejecucion
		printf("No ha ingresado ningun argumento en linea de comandos");		//de parseCmdLine se muestra en pantalla
	else if (parseCmdLine_Return == OVERFLOW_ARGS)								//su origen
		printf("La cantidad de argumentos excede el maximo de %d", MAX_ARGS);
	else if (parseCmdLine_Return == SINTAX_ERROR)
		printf("Su ingreso ha sido incorrecto \n(Formato: -clave valor // parametro)");
	else 
		printf("La cantidad de parametros ingresados fueron: %d", parseCmdLine_Return); //En el caso de una ejecucion
																						//exitosa, muestra la cantidad
																						//de argumentos

	while (1); //solo sirve para que la consola de windowsno deparezca de pantalla cuando termina el programa *Borrar*
	
	return 0;
}

int parseCallback(char *key, char *value, void *UserData)
{
	if (key == NULL)
	{
		//Guardar value en UserData, ya que lo que ingreso
		//es un parámetro
		return 1;	//Interpretacion correcta
	}
	if (key != NULL && value != NULL)
	{
		//Guardar key (sin el guion) y value en UserData, ya que lo que ingreso
		//es una clave con un valor
		return 1;	//Interpretacion correcta
	}
	if (key != NULL && value == NULL)
	{
		return 0; //si tengo una clave sin valor, devuelvo 0
	}
}