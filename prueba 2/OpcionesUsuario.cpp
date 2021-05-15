#include "OpcionesUsuario.h"

std::istream& operator>>(std::istream& in, OpcionesUsuario& opcionesUsuario)
{
	int valor;
	if (in >> valor)
	{
		switch (OpcionesUsuario(valor))
		{
		case OpcionesUsuario::Ninguno:
		case OpcionesUsuario::Agregar:
		case OpcionesUsuario::Editar:
		case OpcionesUsuario::Consultar:
		case OpcionesUsuario::Lista:
		case OpcionesUsuario::salir:
			opcionesUsuario = OpcionesUsuario(valor);
			break;
		default:
			opcionesUsuario = OpcionesUsuario::Ninguno;
			break;
		}
	}

	return in;
}