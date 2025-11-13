/*
============================================================
  Fichero: sprites.c
  Creado: 11-11-2025
  Ultima Modificacion: dimecres, 12 de novembre de 2025, 20:00:09
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "zaxxon.h"

address snaved,snavei,smun;

static address actdir=ORAM;

static void snave_init() {
	snaved=actdir;
	char* datad[]={	"011000000000",
					"011000000000",
					"011111111000",
					"011111100110",
					"111111111111",
					"000001100000",
					"000011000000"
	};
	actdir=sprnew(snaved,7,datad);
	snavei=actdir;
	char* datai[]={	"000000000110",
					"000000000110",
					"000111111110",
					"011001111110",
					"111111111111",
					"000001100000",
					"000000110000"
	};
	actdir=sprnew(snavei,7,datai);
}

static void smundo_init() {
	char* datam[]={	"0000000000",
					"0101010100",
					"0000000010",
					"0100000000",
					"0000000010",
					"0100000000",
					"0000000010",
					"0100000000",
					"0010101010",
					"0000000000"
	};
	smun=actdir;
	actdir=sprnew(smun,10,datam);
}

void sprites_init() {
	snave_init();
	smundo_init();
}


