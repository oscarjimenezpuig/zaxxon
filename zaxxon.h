/*
============================================================
  Fichero: zaxxon.h
  Creado: 11-11-2025
  Ultima Modificacion: dimecres, 12 de novembre de 2025, 20:09:44
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef ZAXXON_H
#define ZAXXON_H

#include <stdio.h>

#include "sprite.h"

//CONSTANTES

#define MOVILES 10 //numero de moviles maximo en pantalla

#define MUNLEN 100 //longitud del mundo en sectores

//tipos de moviles
#define JUGADOR 0
#define COHETE 1

//cinematica
#define ACMAX 5
#define VEMAX 5 

//METODOS

#define ABS(A) (((A)>0)?(A):(-(A)))
#define SGN(A) ((A)>0)?1:((A)<0)?-1:0

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

extern address snavei,snaved,smun; //direcciones de los sprites

extern Movil movil[MOVILES]; //almacen de los moviles en pantalla (jugador siempre el 0)
extern int moviles; //numero de moviles en pantalla

//FUNCIONES

void sprites_init();
//define todos los sprites

void mundo_init();
//define el mundo

void mundo_show(int posini);
//indica el pixel de la altura que ocupa la posicion x=0 de la pantalla

byte movil_new(Movil movil);
//definicion de un nuevo movil

void movil_move(Movil* movil);
//mueve un movil a partir de su cinematica

#endif //ZAXXON_H
