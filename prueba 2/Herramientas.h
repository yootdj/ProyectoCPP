#pragma once
#include <iostream>
#include <locale>

#include "ModeloUsuario.h"

void limpiarPantalla();

void TiempoEsperaPantalla();
ModeloUsuario* ConvertirUsuarioApuntador(ModeloUsuario usuario);

ModeloUsuario ConvertirUsuarioObjeto(ModeloUsuario* usuario);

//va ca configurar la aplicacion para que los caracteres se vean con asento
std::locale ConfigurarCaracteres();

void limpiarCin();
