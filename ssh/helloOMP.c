#include <stdio.h>
#include <omp.h>

int main(void){
	#pragma omp parallel
		printf("(!!!Hello World!!!)"),omp_get_thread_num();
	return (0);
}
