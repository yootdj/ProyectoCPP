#pragma once
#include "Herramientas.h"

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "ModeloUsuario.h"
#include "OpcionesUsuario.h"
#include "LeerDatosConsola.h"

class Usuario
{
public:

	//contructor por defecto
	Usuario();

	//Metodos estaticos
	static void MostrarMenuUsuarios();
	static ModeloUsuario* CrearUsuario();
	static void AgregarUsuario();
	static void MostrarListaUsuarios();
	static ModeloUsuario* ConsultarUsuario();
	static void EditarUsuario();
	static void GuardarUsuarios();
	static void CargarUsuarios();

private:
	static std::list<ModeloUsuario*> listaUsuarios;
};
