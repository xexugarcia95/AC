/* Ejemplo de Programa de Prueba */

#include <stdio.h>
#include <math.h>
#include <time.h>

int suma_prod(int a,int b,int n);

int main(){
	/*--------------*/
	int i,j,a,b,n,c;
	/*--------------*/

	clock_t start,stop;

	start=clock();

	/*---------------------------------*/
	n=6000;
	a=1;
	b=2;
	for(j=1;j<=10000;j++){
		printf("a=%d b=%d n=%d\n",a,b,n);
		c=suma_prod(a,b,n);
		printf("resultado= %d\n",c);
	}
	/*---------------------------------*/

	stop=clock();
	printf("\n\n");
	//printf("TIEMPO= %f",difftime(stop,start));
	printf("Tiempo de ejecucion= %f",(stop-start)/(double)CLOCKS_PER_SEC);
	printf("\n\n");
	return 0;
}