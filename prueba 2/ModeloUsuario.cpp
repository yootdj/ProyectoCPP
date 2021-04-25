#include "ModeloUsuario.h"

ModeloUsuario::ModeloUsuario()
{
	aniodenacimiento = 0;
	mesdenacimiento = 0;
	diadenacimiento = 0;
}

std::string ModeloUsuario::toString()
{
	return nombre + " " +
		apellidoPaterno + " " +
		apellidoMaterno;
}