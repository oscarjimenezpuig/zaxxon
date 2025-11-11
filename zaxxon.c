/*
============================================================
  Fichero: zaxxon.c
  Creado: 11-11-2025
  Ultima Modificacion: dimarts, 11 de novembre de 2025, 05:09:24
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "zaxxon.h"

begin
	sprites_init();
	sprins(snavei,10,7,100,100);
	sprins(snaved,10,7,100,150);
	show;
	while(inkey('q')==0) listen;
end
