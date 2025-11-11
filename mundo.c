/*
============================================================
  Fichero: mundo.c
  Creado: 11-11-2025
  Ultima Modificacion: dimarts, 11 de novembre de 2025, 19:16:58
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "zaxxon.h"

#define RAI 88 //bit que indica la altura inicial
#define SPRW 10 //ancho del sprite de suelo
#define SPRH 9 //alto del sprite de suelo

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

#define ABS(A) (((A)>0)?(A):(-(A)))

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
	int altura[MUNLEN];
	altura_define(0,0,altura);
	if(!altura_arregla(altura+MUNLEN-1,0)) puts("FALLO EN EL ARREGLO DE LA ALTURA");
	altura_print();
}

void mundo_show(int altura*,int posini) {
	const int RETROCESO=(SCRWP/2); //en pixels
	int primero=(posini-RETROCESO)/SPRW;
	if(primero<0) primero=MUNLEN-primero;
	int* ptr=altura+primero;
	int x=0





