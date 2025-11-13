/*
============================================================
  Fichero: movil.c
  Creado: 11-11-2025
  Ultima Modificacion: dimecres, 12 de novembre de 2025, 20:11:33
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

void movil_move(Movil* m) {
	m->vx+=m->ax;
	m->vy+=m->ay;
	int sgvx=SGN(m->vx);
	int sgvy=SGN(m->vy);
	if(ABS(m->vx)>VEMAX) m->vx=sgvx*VEMAX;
	if(ABS(m->vy)>VEMAX) m->vy=sgvy*VEMAX;
	int fx=m->x+sgvx;
	int fy=m->y+sgvy;


	
		
	
