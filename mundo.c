/*
============================================================
  Fichero: mundo.c
  Creado: 11-11-2025
  Ultima Modificacion: dimecres, 12 de novembre de 2025, 20:06:54
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "zaxxon.h"

#define RAI 128 //sprite que indica la altura inicial
#define SPRW 10 //ancho del sprite de suelo
#define SPRH 10 //alto del sprite de suelo

static int altura[MUNLEN];

static void altura_define(int hactual,int hfutura,int* ptr) {
	const int MAXH=10;
	const int MINH=-10;
	const int MAXLL=10;
	const int LLINI=10;
	static int llano=LLINI;
	if(hactual==hfutura && llano==0) {
		llano=rnd(0,MAXLL);
		hfutura=rnd(MINH,MAXH);
	}
	int dir=0;
	if(hfutura>hactual) dir=1;
	else if(hfutura<hactual) dir=-1;
	else if(llano) dir=0;
	if(ptr!=altura+MUNLEN) {
		*ptr++=hactual+dir;
		if(dir==0 && llano) --llano;
		altura_define(*(ptr-1),hfutura,ptr);
	}
}

static int altura_arregla(int* ptr,int hact) {
	if(ptr!=altura) {
		int hfut=*(ptr-1);
		if(ABS(hact-hfut)<=1) return 1;
		else if(hact<hfut) hact=hact+1;
		else hact=hact-1;
		*ptr--=hact;
		return altura_arregla(ptr,hact);
	} else return 0;
}

static void altura_print() {
	int *ptr=altura;
	while(ptr!=altura+MUNLEN) {
		printf("%02i  ",*ptr++);
	}
	printf("\n");
}

void mundo_init() {
	randomize(-1);
	altura_define(0,0,altura);
	if(!altura_arregla(altura+MUNLEN-1,0)) puts("FALLO EN EL ARREGLO DE LA ALTURA");
	altura_print();
}

void mundo_show(int posini) {
	const int LENALP=MUNLEN*SPRW;
	posini=posini%LENALP;
	int pos=posini/SPRW;
	int res=posini%SPRW;
	int x=0-res;
	while(x<SCRWP) {
		int ala=altura[pos];
		int y=RAI-SPRH*ala;
		sprins(smun,SPRW,SPRH,x,y);
		pos=(pos+1)%MUNLEN;
		x+=SPRW;
	}
	puts("");//dbg
}

	



