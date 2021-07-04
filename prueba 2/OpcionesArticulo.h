#pragma once
#include <iostream>
enum class OpcionesArticulo : int
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

std::istream& operator>> (std::istream& in, OpcionesArticulo& opcionesArticulo);