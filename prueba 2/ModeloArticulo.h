#pragma once

#include <string>

class  ModeloArticulo
{
public:
	unsigned long id;
	unsigned long idUsuario;
	std::string nombre;
	std::string descripcion;
	int anioRegistro;
	int mesRegistro;
	int diaRegistro;
	int horasRegistro;
	int minutosRegistro;
	int segundosRegistros;

	//Constructor
	ModeloArticulo();
};