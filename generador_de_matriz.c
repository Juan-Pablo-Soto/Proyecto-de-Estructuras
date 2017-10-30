	#include <stdio.h>

int main()
{
		
FILE *fp;
	fp = fopen("Mapa850.txt", "r");
	
	char control=' ';
	int ancho;
	int alto;
	
	
	/*extrae el ancho*/
	fscanf(fp, "%d", &ancho);
	printf("%d \n",ancho);
	
	/*extrae el alto*/

	fscanf(fp, "%d", &alto);
	printf("%d \n",alto);

	char matriz[alto][ancho];
	/*extrae el mapa*/
	int i = 0;
	int j = 0;
	int contador = 0;
	while(!feof(fp)){
		control = fgetc(fp);
		
		
		printf("iteracion %d \n",contador);
		contador++;
		
		if(control == '\n' || control==' '){
			printf("aqui hay salto de linea o espacio \n");
			i++;
			j = 0;
			//control = fgetc(fp);
			}
		else {
			printf("aqui inserta en matriz el elemento: %c \n", control);
			matriz[i][j] = control;
			j++;
		}
		}
	
	for(i = 0; i < alto; i++){
		for(j = 0; j < ancho;j ++){
			char x = matriz[i][j];
			printf("%c", x);
			}
		printf("\n");
		}
	
	

fclose(fp);
		


		
        
return 0;
}

