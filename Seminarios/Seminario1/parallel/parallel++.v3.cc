#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <string>

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
		int yo = omp_get_thread_num();
		std::string s = std::to_string(yo);
		
		if (yo < thread)
			s += " realiza la tarea 1\n";
		else
			s += " realiza la tarea 2\n";
		
		std::cout << s;
	}
}
