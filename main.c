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
void simulation(struct Mapa map, struct Carro* primero){
	
	struct Carro * aux;
	
	int i=10;
	
	while (i!=0){
			
		aux=primero;
		
		while(aux!=NULL){
			
			if(aux->debajo==60){
				map.matriz[aux->x][aux->y]=aux->debajo;
				
				if(map.matriz[aux->x][aux->y-1]==169||map.matriz[aux->x][aux->y-1]==184||map.matriz[aux->x][aux->y-1]==189||map.matriz[aux->x][aux->y-1]==245){
						
						aux->y=aux->y-2;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					
				if(map.matriz[aux->x][aux->y-1]==192){
					    if(map.matriz[aux->x-1][aux->y-1]==176){
						
						aux->y=aux->y-1;
					    aux->x=aux->x-2;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
							}
						else{	
					    aux->y=aux->y-1;
					    aux->x=aux->x-1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					}
				if(map.matriz[aux->x][aux->y-1]==218){
					    
					    if(map.matriz[aux->x+1][aux->y-1]==176){
						
						aux->y=aux->y-1;
					    aux->x=aux->x+2;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
							}
					    else{
					    aux->y=aux->y-1;
					    aux->x=aux->x+1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					}
				if(map.matriz[aux->x][aux->y-1]==193){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x-1][aux->y-1]==176){
						
								aux->y=aux->y-1;
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						else{
							if(map.matriz[aux->x][aux->y-2]==176){
						
								aux->y=aux->y-3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-2;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    
					}
				if(map.matriz[aux->x][aux->y-1]==194){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x+1][aux->y-1]==176){
						
								aux->y=aux->y-1;
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						else{
							if(map.matriz[aux->x][aux->y-2]==176){
						
								aux->y=aux->y-3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
									}
							else{
							aux->y=aux->y-2;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					    
					}
					if(map.matriz[aux->x][aux->y-1]==195){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x+1][aux->y-1]==176){
						
								aux->y=aux->y-1;
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
						else{
							if(map.matriz[aux->x-1][aux->y-1]==176){
						
								aux->y=aux->y-1;
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					if(map.matriz[aux->x][aux->y-1]==197){
						
						srand(time(NULL));
					    int d= rand() %3;
					    
					    if(d==0){
							if(map.matriz[aux->x-1][aux->y-1]==176){
						
								aux->y=aux->y-1;
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    if(d==1){
							if(map.matriz[aux->x][aux->y-2]==176){
						
								aux->y=aux->y-3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-2;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    else{
							if(map.matriz[aux->x+1][aux->y-1]==176){
						
								aux->y=aux->y-1;
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						
						} 
				}
				if(map.matriz[aux->x][aux->y-1]==207){}
							
				else{
					aux->y=aux->y-1;
					aux->debajo=map.matriz[aux->x][aux->y];
					map.matriz[aux->x][aux->y]=207;
					}
				
				
				}
			if(aux->debajo==94){
				
				map.matriz[aux->x][aux->y]=aux->debajo;
				
				if(map.matriz[aux->x-1][aux->y]==169||map.matriz[aux->x-1][aux->y]==184||map.matriz[aux->x-1][aux->y]==189||map.matriz[aux->x-1][aux->y]==245){
						
						aux->x=aux->x-2;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					//--------------------------------------------------------
					if(map.matriz[aux->x-1][aux->y]==191){
					    if(map.matriz[aux->x-1][aux->y-1]==176){
						
						aux->y=aux->y-2;
					    aux->x=aux->x-1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
							}
						else{	
					    aux->y=aux->y-1;
					    aux->x=aux->x-1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					}
				if(map.matriz[aux->x-1][aux->y]==218){
					    
					    if(map.matriz[aux->x-1][aux->y+1]==176){
						
						aux->y=aux->y+2;
					    aux->x=aux->x-1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
							}
					    else{
					    aux->y=aux->y+1;
					    aux->x=aux->x-1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					}
				if(map.matriz[aux->x-1][aux->y]==180){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x-1][aux->y-1]==176){
						
								aux->y=aux->y-2;
								aux->x=aux->x-1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						else{
							if(map.matriz[aux->x-2][aux->y]==176){
						
								aux->x=aux->x-3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->x=aux->x-2;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    
					}
				if(map.matriz[aux->x-1][aux->y]==194){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x-1][aux->y-1]==176){
						
								aux->y=aux->y-2;
								aux->x=aux->x-1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						else{
							if(map.matriz[aux->x-1][aux->y+1]==176){
								aux->x=aux->x-1;
								aux->y=aux->y+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
									}
							else{
							aux->x=aux->x-1;
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					    
					}
					if(map.matriz[aux->x-1][aux->y]==195){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x-1][aux->y+1]==176){
						
								aux->y=aux->y+2;
								aux->x=aux->x-1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
						else{
							if(map.matriz[aux->x-2][aux->y]==176){
						
								
								aux->x=aux->x-3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x-2;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					if(map.matriz[aux->x-1][aux->y]==197){
						
						srand(time(NULL));
					    int d= rand() %3;
					    
					    if(d==0){
							if(map.matriz[aux->x-1][aux->y-1]==176){
						
								aux->y=aux->y-2;
								aux->x=aux->x-1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    if(d==1){
							if(map.matriz[aux->x-2][aux->y]==176){
						
								aux->x=aux->x-3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->x=aux->x-2;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    else{
							if(map.matriz[aux->x-1][aux->y+1]==176){
						
								aux->y=aux->y+2;
								aux->x=aux->x-1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						
						} 
				}
				if(map.matriz[aux->x][aux->y-1]==207){}
					
					//------------------------------------------------------------
				else{
					aux->x=aux->x-1;
					aux->debajo=map.matriz[aux->x][aux->y];
					map.matriz[aux->x][aux->y]=207;
					}
				
				
				}
			if(aux->debajo==62){
				
				map.matriz[aux->x][aux->y]=aux->debajo;
				
				if(map.matriz[aux->x][aux->y+1]==169||map.matriz[aux->x][aux->y+1]==184||map.matriz[aux->x][aux->y+1]==189||map.matriz[aux->x][aux->y+1]==245){
						
						aux->y=aux->y+2;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					
					//--------------------------------------------------------
					if(map.matriz[aux->x][aux->y+1]==191){
					    if(map.matriz[aux->x+1][aux->y+1]==176){
						
						aux->y=aux->y+1;
					    aux->x=aux->x+2;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
							}
						else{	
					    aux->y=aux->y+1;
					    aux->x=aux->x+1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					}
				if(map.matriz[aux->x][aux->y+1]==217){
					    
					    if(map.matriz[aux->x-1][aux->y+1]==176){
						
						aux->y=aux->y+1;
					    aux->x=aux->x-2;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
							}
					    else{
					    aux->y=aux->y+1;
					    aux->x=aux->x-1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					}
				if(map.matriz[aux->x][aux->y+1]==180){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x-1][aux->y+1]==176){
						
								aux->y=aux->y+1;
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						else{
							if(map.matriz[aux->x+1][aux->y+1]==176){
						
								aux->x=aux->x+2;
								aux->y=aux->y+1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->x=aux->x-1;
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    
					}
				if(map.matriz[aux->x][aux->y+1]==194){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x+1][aux->y+1]==176){
						
								aux->y=aux->y+1;
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+1;
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						else{
							if(map.matriz[aux->x][aux->y+2]==176){
								
								aux->y=aux->y+3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
									}
							else{
							
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					    
					}
					if(map.matriz[aux->x][aux->y+1]==193){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x][aux->y+2]==176){
						
								aux->y=aux->y+3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+2;
							
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
						else{
							if(map.matriz[aux->x-1][aux->y+1]==176){
						
								
								aux->x=aux->x-2;
								aux->y=aux->y+1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x-1;
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					if(map.matriz[aux->x][aux->y+1]==197){
						
						srand(time(NULL));
					    int d= rand() %3;
					    
					    if(d==0){
							if(map.matriz[aux->x+1][aux->y+1]==176){
						
								aux->y=aux->y+1;
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+1;
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    if(d==1){
							if(map.matriz[aux->x][aux->y+2]==176){
						
								aux->y=aux->y+3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+2;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    else{
							if(map.matriz[aux->x-1][aux->y+1]==176){
						
								aux->y=aux->y+1;
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+1;
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						
						} 
				}
				if(map.matriz[aux->x][aux->y+1]==207){}
					
					//------------------------------------------------------------
					
					
				else{
					aux->y=aux->y+1;
					aux->debajo=map.matriz[aux->x][aux->y];
					map.matriz[aux->x][aux->y]=207;
					}
				
				}
			if(aux->debajo==118){
				map.matriz[aux->x][aux->y]=aux->debajo;
				
				if(map.matriz[aux->x+1][aux->y]==169||map.matriz[aux->x+1][aux->y]==184||map.matriz[aux->x+1][aux->y]==189||map.matriz[aux->x+1][aux->y]==245){
						
						aux->x=aux->x+2;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					
					//--------------------------------------------------------
					if(map.matriz[aux->x+1][aux->y]==192){
					    if(map.matriz[aux->x+1][aux->y+1]==176){
						
						aux->y=aux->y+2;
					    aux->x=aux->x+1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
							}
						else{	
					    aux->y=aux->y+1;
					    aux->x=aux->x+1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					}
				if(map.matriz[aux->x+1][aux->y]==217){
					    
					    if(map.matriz[aux->x+1][aux->y-1]==176){
						
						aux->y=aux->y-2;
					    aux->x=aux->x-1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
							}
					    else{
					    aux->y=aux->y-1;
					    aux->x=aux->x+1;
						aux->debajo=map.matriz[aux->x][aux->y];
						map.matriz[aux->x][aux->y]=207;
					}
					}
				if(map.matriz[aux->x+1][aux->y]==180){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x+1][aux->y-1]==176){
						
								aux->y=aux->y-21;
								aux->x=aux->x+1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						else{
							if(map.matriz[aux->x+2][aux->y]==176){
						
								aux->x=aux->x+3;
								
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->x=aux->x+2;
							
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    
					}
				if(map.matriz[aux->x+1][aux->y]==193){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x+1][aux->y+1]==176){
						
								aux->y=aux->y+2;
								aux->x=aux->x+1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+1;
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						else{
							if(map.matriz[aux->x+1][aux->y-1]==176){
								
								aux->y=aux->y-2;
								aux->x=aux->x+1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
									}
							else{
							aux->x=aux->x+1;
							aux->y=aux->y-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					    
					}
					if(map.matriz[aux->x+1][aux->y]==195){
					    
					    srand(time(NULL));
					    int d= rand() %2;
					    
					    if(d==0){
							if(map.matriz[aux->x+2][aux->y]==176){
						
								aux->x=aux->x+3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->x=aux->x+2;
							
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
						else{
							if(map.matriz[aux->x+1][aux->y+1]==176){
						
								
								aux->x=aux->x+1;
								aux->y=aux->y+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x+1;
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					if(map.matriz[aux->x+1][aux->y]==197){
						
						srand(time(NULL));
					    int d= rand() %3;
					    
					    if(d==0){
							if(map.matriz[aux->x+1][aux->y+1]==176){
						
								aux->y=aux->y+2;
								aux->x=aux->x+1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y+1;
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    if(d==1){
							if(map.matriz[aux->x+2][aux->y]==176){
						
								aux->x=aux->x+3;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->x=aux->x+2;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
					    else{
							if(map.matriz[aux->x+1][aux->y-1]==176){
						
								aux->y=aux->y-2;
								aux->x=aux->x+1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							aux->y=aux->y-1;
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
							}
						
						} 
				}
				if(map.matriz[aux->x+1][aux->y]==207){}
					
					//------------------------------------------------------------
					
				else{
					aux->x=aux->x+1;
					aux->debajo=map.matriz[aux->x][aux->y];
					map.matriz[aux->x][aux->y]=207;
					}
				}
				
				if(aux->debajo==191){
					map.matriz[aux->x][aux->y]=aux->debajo;
					
					srand(time(NULL));
					int d= rand()%2;
					
					if(d==0){
						if(map.matriz[aux->x-1][aux->y]==176){
						
							
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
					
					
					else{
						if(map.matriz[aux->x+1][aux->y]==176){
						
							
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					
					}
				if(aux->debajo==192){
					
					map.matriz[aux->x][aux->y]=aux->debajo;
					
					srand(time(NULL));
					int d= rand()%2;
					
					if(d==0){
						if(map.matriz[aux->x-1][aux->y]==176){
						
							
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
					
					
					else{
						if(map.matriz[aux->x][aux->y+1]==176){
						
							
								aux->y=aux->y+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					
					}
				if(aux->debajo==217){
					
					map.matriz[aux->x][aux->y]=aux->debajo;
					
					srand(time(NULL));
					int d= rand()%2;
					
					if(d==0){
						if(map.matriz[aux->x-1][aux->y]==176){
						
							
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
					
					
					else{
						if(map.matriz[aux->x][aux->y+1]==176){
						
							
								aux->y=aux->y+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					
					}
				if(aux->debajo==218){
					
					map.matriz[aux->x][aux->y]=aux->debajo;
					
					srand(time(NULL));
					int d= rand()%2;
					
					if(d==0){
						if(map.matriz[aux->x+1][aux->y]==176){
						
							
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
					
					
					else{
						if(map.matriz[aux->x][aux->y+1]==176){
						
							
								aux->y=aux->y+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					
					}
				if(aux->debajo==180){
					
					map.matriz[aux->x][aux->y]=aux->debajo;
					
					srand(time(NULL));
					int d= rand()%3;
					
					if(d==0){
						if(map.matriz[aux->x-1][aux->y]==176){
						
							
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
						
					if(d==1){
						if(map.matriz[aux->x][aux->y-1]==176){
						
							
								aux->y=aux->y-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
					
					else{
						if(map.matriz[aux->x+1][aux->y]==176){
						
							
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					
					}
				if(aux->debajo==193){
					
					map.matriz[aux->x][aux->y]=aux->debajo;
					
					srand(time(NULL));
					int d= rand()%3;
					
					if(d==0){
						if(map.matriz[aux->x-1][aux->y]==176){
						
							
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
						
					if(d==1){
						if(map.matriz[aux->x][aux->y-1]==176){
						
							
								aux->y=aux->y-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
					
					else{
						if(map.matriz[aux->x][aux->y+1]==176){
						
							
								aux->y=aux->y+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					
					}
				if(aux->debajo==194){
					
					map.matriz[aux->x][aux->y]=aux->debajo;
					
					srand(time(NULL));
					int d= rand()%3;
					
					if(d==0){
						if(map.matriz[aux->x+1][aux->y]==176){
						
							
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
						
					if(d==1){
						if(map.matriz[aux->x][aux->y-1]==176){
						
							
								aux->y=aux->y-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
					
					else{
						if(map.matriz[aux->x][aux->y+1]==176){
						
							
								aux->y=aux->y+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					
					}
				if(aux->debajo==195){
					
					map.matriz[aux->x][aux->y]=aux->debajo;
					
					srand(time(NULL));
					int d= rand()%3;
					
					if(d==0){
						if(map.matriz[aux->x-1][aux->y]==176){
						
							
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
						
					if(d==1){
						if(map.matriz[aux->x][aux->y+1]==176){
						
							
								aux->y=aux->y+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
					
					else{
						if(map.matriz[aux->x+1][aux->y]==176){
						
							
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					
					}
				if(aux->debajo==197){
					
					map.matriz[aux->x][aux->y]=aux->debajo;
					
					srand(time(NULL));
					int d= rand()%3;
					
					if(d==0){
						if(map.matriz[aux->x-1][aux->y]==176){
						
							
								aux->x=aux->x-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
						
					if(d==1){
						if(map.matriz[aux->x][aux->y-1]==176){
						
							
								aux->y=aux->y-2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y-1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
						
					if(d==2){
						if(map.matriz[aux->x][aux->y+1]==176){
						
							
								aux->y=aux->y+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->y=aux->y+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						
						}
					
					else{
						if(map.matriz[aux->x+1][aux->y]==176){
						
							
								aux->x=aux->x+2;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
							else{
							
							aux->x=aux->x+1;
							aux->debajo=map.matriz[aux->x][aux->y];
							map.matriz[aux->x][aux->y]=207;
							}
						}
					
					}
				if(aux->debajo==190){
				
							map.matriz[aux->x][aux->y]=aux->debajo;
					
								aux->y=aux->y-1;
								aux->debajo=map.matriz[aux->x][aux->y];
								map.matriz[aux->x][aux->y]=207;
							}
						
						
					
					
			
			
			
			aux=aux->siguiente;
			}
		sleep(2);	
		imprimirMapa(map);	
		i++;
		}
	
	
	};


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

generarCarro(map, primero);
printf("\n primer carro Generado-------------------------------------- \n");
generarCarro(map, primero);
printf("\n segundo carro Generado-------------------------------------- \n");

//simulation(map,primero); no funciona xD


/*generarCarro(map, primero);
printf("\n -------------------------------------- \n");
generarCarro(map, primero);

*/

//imprimirMapa(map);

fclose(fp);





return;
}
