#include <omp.h>
#include <iostream>

void fa()
{
	#pragma omp critical
	std::cout << "fa() ejecutada por " << omp_get_thread_num() << std::endl;
}

void fb()
{
	#pragma omp critical
	std::cout << "fb() ejecutada por " << omp_get_thread_num() << std::endl;
}

int main()
{
	#pragma omp parallel sections
	{
		#pragma omp section
		fa();
		#pragma omp section
		fb();
	}
}
