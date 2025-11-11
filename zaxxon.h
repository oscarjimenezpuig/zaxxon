/*
============================================================
  Fichero: zaxxon.h
  Creado: 11-11-2025
  Ultima Modificacion: dimarts, 11 de novembre de 2025, 05:24:31
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef ZAXXON_H
#define ZAXXON_H

#include "sprite.h"

//CONSTANTES

#define MOVILES 10 //numero de moviles maximo en pantalla

//tipos de moviles
#define JUGADOR 0
#define COHETE 1

//METODOS

//TIPOS

typedef struct {
	byte tipo; //tipo del movil
	address sprite; //sprite actual del movil
	byte w,h; //dimension del sprite actual
	int x,y; //posicion en pantalla en pixels
	int vx,vy; //velocidad 
	int ax,ay; //aceleracion
	int delay; //contador del retraso
	int max_delay; //maximo retraso	
} Movil;

//VARIABLES

extern address snavei,snaved; //direcciones de los sprites

extern Movil movil[MOVILES]; //almacen de los moviles en pantalla (jugador siempre el 0)
extern int moviles; //numero de moviles en pantalla

//FUNCIONES

void sprites_init();
//define todos los sprites

byte movil_new(Movil movil);
//definicion de un nuevo movil

#endif //ZAXXON_H
