#include "ModeloUsuario.h"

ModeloUsuario::ModeloUsuario()
{
	aniodenacimiento = 0;
	mesdenacimiento = 0;
	diadenacimiento = 0;
}

std::string ModeloUsuario::toString()
{
	//Todo eliminar el mostrar las contraseñas despues de las pruebas
	return nombre + " " +
		apellidoPaterno + " " +
		apellidoMaterno + "\n" +
		correoElectronico + "\n" +
		alias + "\n" +
		std::to_string(aniodenacimiento) + "_" +
		std::to_string(mesdenacimiento) + "_" +
		std::to_string(diadenacimiento) + "_" +
		password;
}