#include "OpcionesMenu.h"

std::istream& operator>>(std::istream& in, OpcionesMenu& opcionesMenu)
{
	int valor;
	if (in >> valor)
	{
		switch (OpcionesMenu(valor))
		{
		case OpcionesMenu::Salir:
		case OpcionesMenu::Usuarios:
			opcionesMenu = OpcionesMenu(valor);
			break;
		default:
			opcionesMenu = OpcionesMenu::Ninguno;
			break;
		}
	}

	return in;
}