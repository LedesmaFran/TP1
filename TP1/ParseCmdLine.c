#include "ParseCmdLine.h"

int parseCmdLine (int argc, char *argv[], pCallback CallbackFunc, void *UserData)
{
	int index = 1;					//Contador de argumentos que comienza en 1 ya que el titulo del
									//archivo no se toma en cuenta
	int CountParam=0;

	if (argc == NO_ARGUMENTS)	//Filtros iniciales para desestimar los ingresos sin 
		return EMPTY_ARGS;		//argumentos, o lo ingresos con demasiados
	else if (argc > MAX_ARGS)	//argumentos definidos en MAX_ARGS (ParseCmdLine.h)
		return OVERFLOW_ARGS;

	while (index < argc)			
	{		
									//Evaluo si el primer caracter del argumento es un guion para
		if (*argv[index] == '-')	//determinar si es un parametro o una clave
		{						
			if (!CallbackFunc(argv[index], argv[index+1], UserData))	//Si es una clave, llamo a la funcion de callback
			{
				return SINTAX_ERROR;							//con el key, el value y un puntero para almacenarlos
			}
			index++;
		}														//En caso de devolver "0", termina la ejecucion
		else
		{
			CountParam++;
			if (!CallbackFunc(NULL, argv[index], UserData))			//Si es un parametro, llamo a la funcion de callback
				return SINTAX_ERROR;
		}														//para almacenarlo. En caso de devolver "0", termina la ejecucion
		index++;
	}
	return (CountParam);	//Si la ejecucion fue exitosa, devuelvo la cantidad de paramtros (Sin el nombre del archivo)
}