#include <iostream>
#include <omp.h>

int main(void)
{
	#pragma omp parallel
	std::cout << omp_get_thread_num() << ": hello world!" << std::endl;
}
