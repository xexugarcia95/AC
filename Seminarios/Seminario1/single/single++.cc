#include <omp.h>
#include <iostream>
#include <iterator>

int main()
{
	int n = 9, a, b[n];

	std::fill(b, b + n, -1);

	std::cout << "antes de la región paralela: b = < ";
	std::copy(b, b + n, std::ostream_iterator<int>(std::cout, " "));
	std::cout << ">" << std::endl;

	#pragma omp parallel 
	{
		#pragma omp single
		{
			std::cout << "introduce el valor de inicialización de a: ";
			std::cin >> a;
			std::cout << "cláusula single ejecutada por " 
			          << omp_get_thread_num() << std::endl;
		}

		#pragma omp for
		for (int i = 0; i < n; ++i)
			b[i] = a;
	}

	std::cout << "después de la región paralela: b = < ";
	std::copy(b, b + n, std::ostream_iterator<int>(std::cout, " "));
	std::cout << ">" << std::endl;
}
