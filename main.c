#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
//---------------------------------------------------------------------------
struct Mapa {
	int alto, ancho;	
	
	char ** matriz;
	
};

struct Mapa map;
//---------------------------------------------------------------------------
void imprimirMapa(struct Mapa map){
	
	for(int i = 0; i < map.alto; i++) {
	for(int j = 0; j < map.ancho+1; j++){
	printf("%c", map.matriz[i][j]);
	}
	}
	
	};
//---------------------------------------------------------------------------	
void generarPosicion(struct Mapa map, struct Carro * car){

	srand(time(NULL));
	int x = rand() % map.alto+1;
	int y = rand() % map.ancho+1;

;
	
	if(map.matriz[x][y]==60 || map.matriz[x][y]==84 ||map.matriz[x][y]==62 ||map.matriz[x][y]==118){
		car->x=x;
		car->y=y;
		car->debajo = map.matriz[x][y];
		map.matriz[x][y]=207;
		}
	else{
		sleep(1);
		generarPosicion(map, car);
		

		}
	
	};


//---------------------------------------------------------------------------
void generarCarro(struct Mapa map,struct Carro *primero){
	
	struct Carro *nuevo;
	
	nuevo = (struct Carro *) malloc (sizeof(struct Carro));
	
	if (nuevo == NULL){printf("no hay espacio en memoria");}
	
	
	nuevo->tipo=1;
	nuevo->velocidad=1;
	nuevo->tamano=1;
	nuevo->simbolo=207;
	generarPosicion(map, nuevo);
	nuevo->llego=1;
	/*falta generar el destino*/
	
	nuevo->siguiente=NULL;
	
	if(primero==NULL){
		primero=nuevo;
		ultimo=nuevo;
		}
	else{
		ultimo->siguiente=nuevo;
		ultimo=nuevo;
		}
	
	imprimirMapa(map);
	};

//---------------------------------------------------------------------------
/*void simulation(struct Mapa map, struct Carro* primero){
	
	struct Carro * aux;
	
	int i=20;
	
	while (i!=0){
			
		aux=primero;
		
		while(aux=NULL){
			
			if(aux->debajo==60)
			
			aux=aux->siguiente;
			}
		i++;
		}
	
	
	};

*/
//---------------------------------------------------------------------------
void main(int argc, char const *argv[])
{
	
primero = (struct Carro *) NULL;
ultimo = (struct Carro *) NULL;

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


int c;

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
/*
generarCarro(map, primero);
printf("\n -------------------------------------- \n");
generarCarro(map, primero);
printf("\n -------------------------------------- \n");
generarCarro(map, primero);
printf("\n -------------------------------------- \n");
generarCarro(map, primero);

*/

imprimirMapa(map);

fclose(fp);





return;
}

