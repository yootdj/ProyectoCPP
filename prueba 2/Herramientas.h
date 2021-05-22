#pragma once
#include <iostream>
#include "ModeloUsuario.h"

void limpiarPantalla();

void TiempoEsperaPantalla();
ModeloUsuario* ConvertirUsuarioApuntador(ModeloUsuario usuario);

ModeloUsuario ConvertirUsuarioObjeto(ModeloUsuario* usuario);