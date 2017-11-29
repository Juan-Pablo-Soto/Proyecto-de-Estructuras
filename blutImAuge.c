#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Carro {
	int tipo;
	int velocidad;
	int tamano;
	int x, y;
	char simbolo;
	char debajo;
	
	int llego; // es un booleano
	int destinox, destinoy;
	
	struct Carro *siguiente;
};

struct Carro *primero, *ultimo;

struct Mapa {
	int alto, ancho;	
	
	char ** matriz;
	
};

struct Mapa map;

void imprimirMapa(){
	for(int i = 0; i < map.alto; i++) {
		for(int j = 0; j < map.ancho+1; j++){
			printf("%c", map.matriz[i][j]);
		}
		printf("\n");
	}
	
};

void cambiarCaracter(char caracter, int x, int y) {
	map.matriz[x][y] = caracter;
	}


int generarCarro(int ox,int oy,int dx,int dy, int tipo){
	struct Carro *nuevo;
	nuevo = (struct Carro *) malloc (sizeof(struct Carro));
	nuevo->tipo = tipo;
	nuevo->llego = 0;
	nuevo->destinox = dx;
	nuevo->destinoy = dy;
	nuevo->x = ox;
	nuevo->y = oy;
	if(tipo == 1){
		nuevo->tamano = 1;
		nuevo->simbolo = 207;
		}
	else {
		printf("Error en el tipo de carro");		
		return 1;
		}
	if (nuevo == NULL){
		printf("no hay espacio en memoria");
		return 1;
		}	
		
	if(map.matriz[ox][oy] != 60 && map.matriz[ox][oy] != 94 && map.matriz[ox][oy] != 62 && map.matriz[ox][oy] != 118) {
		return 1;
		}
	nuevo->debajo = map.matriz[ox][oy];
	cambiarCaracter(nuevo->simbolo, ox, oy);
	nuevo->siguiente = NULL;
	if (primero == NULL) {
		primero = nuevo;
		ultimo = nuevo;
		}
	else {
		ultimo->siguiente = nuevo ;
		ultimo = nuevo;
		}	
	return 0;
	}
	
void hacerMapa(){
	FILE *fp;
	
	fp = fopen("Mapa850.txt", "r");
	
	
	int ancho;
	int alto;


	/*extrae el alto*/
	fscanf(fp, "%d", &alto);

	//printf("%d \n",alto);

	/*extrae el ancho*/

	fscanf(fp, "%d", &ancho);
	//printf("%d \n",ancho);


	map.alto=alto;
	map.ancho=ancho;

	map.matriz=(char**) malloc (alto*sizeof(char *));


	for (int x=0; x<alto;x++){
		map.matriz[x]=(char*)malloc(ancho*sizeof(char));
	}
	
	char c;
	for(int i = 0; i < alto; i++) {
		for(int j = 0; j < ancho; j++){
			c = fgetc(fp);
			if (c == '\n') {
				c = fgetc(fp);
				}
			map.matriz[i][j] = c;
		}
	}
}

void simular(int c) {
	printf("Corriendo Simulacion \n");
	struct Carro *aux;
	aux = primero;
	int pasos = 0;
	while(aux->llego != 1 && pasos < c){
		printf("Pos del carro\n");
		printf("%d \t %d \n", aux->x, aux->y);
		cambiarCaracter(aux->debajo, aux->x, aux->y);
		if(aux->debajo == 60) {
			aux->y = aux->y-1;
			}	
		if(aux->debajo == 62) {
			aux->y = aux->y+1;
			}	
		if(aux->debajo == 94) {
			aux->x = aux->x-1;
			}
		if(aux->debajo == 118) {
			aux->x = aux->x+1;
			}
		aux->debajo = map.matriz[aux->x][aux->y];
		cambiarCaracter(aux->simbolo, aux->x, aux->y);
		sleep(1);
		imprimirMapa();		
		pasos++;
		
		if (aux->siguiente == NULL){
			aux = primero;
			}
		else {
			aux = aux->siguiente;
			}
		
	}

	};


int main(){
	hacerMapa();
	imprimirMapa();
	printf("Mapa generado \n");
	sleep(1);
	generarCarro(1,19,1,1,1);
	generarCarro(3,20,1,1,1);
	generarCarro(15,7,1,1,1);
	imprimirMapa();
	printf("Carros generado \n");
	sleep(1);
	simular(9);
	}




