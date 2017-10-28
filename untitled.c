/*
 * untitled.c
 * 
 * Copyright 2017 Juan Pablo Soto Rojas <sr-jp@sr-jp-laptop>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>

struct Carro {
	int tipo;
	int velocidad;
	int tamagno;
	int x, y;
	char simbolo;
	char debajo;

	int llego; // es un booleano
	int destinox, destinoy;
	
};

struct Mapa {
	int alto, ancho;	
	
	char matriz;
	
};


struct Nodo { //este es el nodo para hacer la lista de carros, con esta lista se llama a la funcion carro.avanzar o algo asi
	struct Carro carro;
	struct Nodo *siguiente;
};

void crear_mapa() {
	FILE *fp;
	fp = fopen("NOMBRE", "r");
	
	char control;
	int ancho = 0;
	int alto = 0;
	
	while (fgetc(fp) != '\n') {
		ancho = ancho * 10;
		control = fgetc(fp);
		ancho = ancho + (int)(control-1); 
		} 
	
	control = fgetc(fp);
	
	while (fgetc(fp) != '\n') {
		alto = alto * 10;
		control = fgetc(fp);
		alto = alto + (int)(control-1); 
	}
	

	control = fgetc(fp);
	char matriz[alto][ancho];
	int i = 0;

	while(!feof(fp)){
		int j = 0;		
		while(fgetc(fp)!='\n'){
			control = fgetc(fp);
			matriz[i][j] = control;
			j++;
			}
		i++;
}		
}


void general_auto(struct Mapa mapa, int tipo) { //Mae no se como es que se tiene que llamar al mapa para que se pueda modificar
	int x = rand(); //esto tiene que ser menor que mapa.matriz.alto
	int y = rand(); //esto tiene que ser menor que mapa.matriz.ancho
	while (mapa.matriz[x][y] != '<' && mapa.matriz[x][y] != 'v' && mapa.matriz[x][y] != '>' && mapa.matriz[x][y] != '^'){
		x = rand(); //esto tiene que ser menor que mapa.matriz.alto
		y = rand(); //esto tiene que ser menor que mapa.matriz.ancho
		}
	
	struct Carro *nuevo = malloc(sizeof(struct Carro));
	
	nuevo.x = x;
	nuevo.y = y;
	
	nuevo.debajo = mapa.matriz[x][y];
	nuevo.tipo = tipo;
	//AQUI SE MODIFICA EL MAPA PARA QUE SALGAN LOS CARROS
	if (nuevo.tipo = 1){	//el tipo 1 es un carro normal
		mapa.matriz[x][y] = '¤';
		nuevo.simbolo = '¤';
		nuevo.tamagno = 1;
	}
	//el tipo 2 puede ser una ambulancia
	
	else {
		//DAR ERROR DE QUE NO EXISTE ESE TIPO
		}
	
	//se agrega el carro a la lista
	
	
	
	}