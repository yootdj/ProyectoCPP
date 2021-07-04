#pragma once

#include <iostream>

enum  class OpcionesMenu : int
{
	Ninguno,
	Usuarios,
	Articulos,
	Salir
};

//este operador nos ayuda a guardar el dato leido desde el teclado para guardarlo directamente en la variable del tipo Opcionesmenu
std::istream& operator>> (std::istream& in, OpcionesMenu& opcionesMenu);
