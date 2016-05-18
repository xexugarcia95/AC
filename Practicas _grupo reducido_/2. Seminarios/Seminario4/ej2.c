/*Ejercicio 2*/

#include <stdio.h>
#include <time.h>

void suma_vector(int v[],int v_2[],const int n,const int N);

int main(){
	clock_t ini,fin;
	const int n=10;
	const int N=30; 
	int v[N],v_2[N];
	int i;
	srand(time(NULL));
	for(i=0;i<N;i++)
		v[i]=rand()%11;

	for(i=0;i<N;i++)
		v_2[i]=rand()%11;

	printf("Vector Previo\n");
	for(i=0;i<N;i++)
		printf("v[%d]= %d\n",i,v[i]);

	ini=clock();

	suma_vector(v,v_2,n,N);

	fin=clock();

	printf("Salida del Vector despues de la ejecucion:\n");
	for(i=0;i<N;i++)
		printf("v[%d]= %d\n",i,v[i]);


	printf("Tiempo de ejecucion: %f",(fin-ini)/(double)CLOCKS_PER_SEC);
	printf("\n\n");
	return 0;	
}

