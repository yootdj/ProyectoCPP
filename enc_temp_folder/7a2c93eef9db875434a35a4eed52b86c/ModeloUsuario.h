#pragma once
#include <string>
#include <fstream>
class ModeloUsuario
{
public:
	std::string nombre;
	std::string apellidoPaterno;
	std::string apellidoMaterno;
	std::string alias;
	short aniodenacimiento;
	short mesdenacimiento;
	short diadenacimiento;
	std::string correoElectronico;
	std::string password;

	ModeloUsuario();

	std::string toString();
};
