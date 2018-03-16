#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
#endif

#include <iostream>

int main()
{
	#pragma omp parallel
	std::cout << "hello(" << omp_get_thread_num() 
	          << ") world(" << omp_get_thread_num() 
	          << ")" << std::endl;
}
