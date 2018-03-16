#include <omp.h>

#include <iostream>
#include <string>

int main(void)
{
	#pragma omp parallel
	{
		std::string s = std::to_string(omp_get_thread_num()) + ": hello world!\n";
		std::cout << s;
	}
}
