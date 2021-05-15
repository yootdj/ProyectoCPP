#pragma once
#include <iostream>
enum class OpcionesUsuario : int
{
	Ninguno,
	Agregar,
	Editar,
	Consultar,
	Lista,
	GuardarArchivo,
	CargarArhivo,
	salir
};

std::istream& operator>> (std::istream& in, OpcionesUsuario& opcionesUsuario);