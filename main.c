#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Carro {
	int tipo;
	int velocidad;
	int tamano;
	int x, y;
	char simbolo[1];
	char debajo[1];

	int llego; // es un booleano
	int destinox, destinoy;
	
};

struct Carro *primero, *ultimo;

struct Mapa {
	int alto, ancho;	
	
	char ** matriz;
	
};

struct Mapa map;

void imprimirMapa(struct Mapa map){
	
	for(int i = 0; i < map.alto; i++) {
	for(int j = 0; j < map.ancho+1; j++){
	printf("%c", map.matriz[i][j]);
	}
	}
	
	};


void main(int argc, char const *argv[])
{





FILE *fp;
fp = fopen("Mapa850.txt", "r");

int ancho;
int alto;


/*extrae el alto*/
fscanf(fp, "%d", &alto);

printf("%d \n",alto);

/*extrae el ancho*/

fscanf(fp, "%d", &ancho);
printf("%d \n",ancho);


//int i = 0;
//int j = 0;
int c;


//char matriz[alto][ancho];
map.alto=alto;
map.ancho=ancho;

map.matriz=(char**) malloc (alto*sizeof(char *));


for (int x=0; x<alto;x++){
	map.matriz[x]=(char*)malloc(ancho*sizeof(char));
	
	}
		

for(int i = 0; i < alto; i++) {
for(int j = 0; j < ancho+1; j++){
char c = fgetc(fp);
//printf("%c \n",c);
map.matriz[i][j] = c;
}
}

imprimirMapa(map);


fclose(fp);





return;
}
