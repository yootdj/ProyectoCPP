#include "OpcionesArticulo.h"

std::istream& operator>>(std::istream& in, OpcionesArticulo& opcionesArticulo)
{
	int valor;
	if (in >> valor)
	{
		switch (OpcionesArticulo(valor))
		{
		case OpcionesArticulo::Ninguno:
		case OpcionesArticulo::Agregar:
		case OpcionesArticulo::Editar:
		case OpcionesArticulo::Consultar:
		case OpcionesArticulo::Lista:
		case OpcionesArticulo::salir:
			opcionesArticulo = OpcionesArticulo(valor);
			break;
		default:
			opcionesArticulo = OpcionesArticulo::Ninguno;
			break;
		}
	}

	return in;
}