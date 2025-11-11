/*
============================================================
  Fichero: movil.c
  Creado: 11-11-2025
  Ultima Modificacion: dimarts, 11 de novembre de 2025, 05:24:31
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "zaxxon.h"

Movil movil[MOVILES];
int moviles=1;

byte movil_new(Movil m) {
	if(m.tipo==JUGADOR) {
		movil[0]=m;
	} else if(moviles<MOVILES) {
		movil[moviles++]=m;
	} else return 0;
	return 1;
}
		
	
