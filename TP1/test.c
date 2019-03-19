#include <stdio.h>
#include "ParseCmdLine.h"

int parseCallback(char *, char *, void *);	 //Declaracion de la funcion de callback
int main2(int argc, char *argv[]);

int main (void)
{
	char *array[4] = { "TP1.exe","-opc1","valor1","param1" };
	printf("---------Prueba 1---------\nArgumentos de entrada = TP1.exe -opc1 valor1 param1\n");
	main2(4, array);			//deberia devolver 2

	char *array2[6] = { "TP1.exe","-opc1","valor1","param1","-opc2", NULL };
	printf("\n---------Prueba 2---------\nArgumentos de entrada = TP1.exe -opc1 valor1 param1 -opc2\n");
	main2(5, array2);			//ERROR -opc2 sin valor

	char *array3[5] = { "TP1.exe","-opc1","valor","-" };
	printf("\n---------Prueba 3---------\nArgumentos de entrada = TP1.exe -opc1 valor -\n");
	main2(4, array3);			//ERROR - sin clave

	char *array4[5] = { "TP1.exe","-opc1","-opc2","valor2" };
	printf("\n---------Prueba 4---------\nArgumentos de entrada = TP1.exe -opc1 -opc2 valor2\n");
	main2(4, array4);			//ERROR -opc1 sin valor

	char *array5[5] = { "TP1.exe" };
	printf("\n---------Prueba 5---------\nArgumentos de entrada = TP1.exe\n");
	main2(1, array5);			//ERROR No ha ingresado ningun argumento en linea de comandos

	

}


int main2(int argc, char *argv[])
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
		if ((void*)*(key + 1) == NULL)
		{
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