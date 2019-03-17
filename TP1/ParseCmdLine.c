#include "ParseCmdLine.h"

int parseCmdLine (int argc, char *argv[], pCallback CallbackFunc, void *UserData)
{
	int i = 1;					//Contador de argumentos que comienza en 1 ya que el titulo del
								//archivo no se toma en cuenta

	if (argc == NO_ARGUMENTS)	//Filtros iniciales para desestimar los ingresos sin 
		return EMPTY_ARGS;		//argumentos, o lo ingresos con demasiados
	else if (argc > MAX_ARGS)	//argumentos definidos en MAX_ARGS (ParseCmdLine.h)
		return OVERFLOW_ARGS;

	while (i <= argc)			
	{							//Evaluo si el primer caracter del argumento es un guion para
		if (*argv[i] == '-')	//determinar si es un parametro o una clave
		{						
			if (!CallbackFunc(argv[i], argv[++i], UserData))	//Si es una clave, llamo a la funcion de callback
				return SINTAX_ERROR;							//con el key, el value y un puntero para almacenarlos
		}														//En caso de devolver "0", termina la ejecucion
		else 
		{
			if(!CallbackFunc(NULL, argv[i], UserData))			//Si es un parametro, llamo a la funcion de callback
				return SINTAX_ERROR;							//con NULL, el parametro en value y un puntero para almacenarlos
		}														//para almacenarlo. En caso de devolver "0", termina la ejecucion
		i++;
	}
	return (argc-1);	//Si la ejecucion fue exitosa, devuelvo la cantidad de paramtros (Sin el nombre del archivo)
}