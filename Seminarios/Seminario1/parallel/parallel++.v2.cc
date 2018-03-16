#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>

int main(int argc, char *argv[])
{
	if (argc != 2)
		throw std::invalid_argument("necesito el tamaño del vector");

	int thread;
	std::istringstream iss(argv[1]);
	iss >> thread;
	if(!iss) 
		throw std::invalid_argument("tamaño de vector no válido");

	#pragma omp parallel 
	{
		if (omp_get_thread_num() < thread)
			#pragma omp critical
			std::cout << omp_get_thread_num() << " realiza la tarea 1" << std::endl;
		else
			#pragma omp critical
			std::cout << omp_get_thread_num() << " realiza la tarea 2" << std::endl;
	}
}
