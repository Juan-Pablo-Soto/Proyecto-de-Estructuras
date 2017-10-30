
#include <stdio.h>

int main()
{
		
FILE *fp;
	fp = fopen("Mapa850.txt", "r");
	
	int ancho;
	int alto;
	
	
	fscanf(fp, "%d", &ancho);

	printf("%d \n",ancho);
	

	fscanf(fp, "%d", &alto);
	printf("%d \n",alto);

	int i = 0;
	int j = 0;
	int c;
	ancho = ancho * 2;
	alto = alto * 2;
	char matriz[alto][ancho];
	
	for(i = 0; i < alto; i++) {
		for(int j = 0; j < ancho; j++){
			c = fgetc(fp);
				if(c == '\n' || c ==' '){
			i++;
			j = 0;
			}
			else{
				matriz[i][j] = c;			
			}
			}
			}

			
			
			

			
	for(i = 0; i < alto; i++) {
		for(j = 0; j < ancho; j++){
			printf("%c", matriz[i][j]);
			}
			printf("\n");
			
			}


fclose(fp);
		


		
        
return 0;
}


