/*
============================================================
  Fichero: zaxxon.c
  Creado: 11-11-2025
  Ultima Modificacion: mié 12 nov 2025 11:14:16
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "zaxxon.h"

begin
	sprites_init();
	mundo_init();
	int pos=0;
	while(inkey('q')==0) {
		sprins(snaved,10,7,100,100);
		mundo_show(pos++);
		show;
		pause(0.01);
		cls;
		listen;
	}
end
