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

struct carro {
	int tipo;
	int velocidad;
	int tamagno;
	int x, y;
	char nombre[10];
	char simbolo[10];
	char debajo[10];

	int llego; // es un booleano
	int destinox, destinoy;
	
};

struct mapa {
	int alto, ancho;	
	
	char matriz;
	
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
