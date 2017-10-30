	#include <stdio.h>

int main()
{
		
	FILE *fp;
	fp = fopen("Mapa850.txt", "r");
	
	char control;
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
	while(!feof(fp)){
		control = fgetc(fp);
		if(control == '\n'){
			i++;
			j = 0;
			control = fgetc(fp);
			}
		else {
			matriz[i][j] = control;
			j++;
		}
		}
	
	for(i = 0; i < alto; i++){
		for(j = 0; j < ancho;j ++){
			printf(" %c ",matriz[i][j]);
			}
		printf("\n");
		}
	
	

fclose(fp);
		


		
        
        return 0;
}

