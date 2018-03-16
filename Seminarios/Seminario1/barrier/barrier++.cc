#include <omp.h>
#include <chrono>
#include <iostream>
#include <thread>

int main()
{
	#pragma omp parallel
	{
		using namespace std::chrono;

		if (omp_get_thread_num() < omp_get_num_threads() / 2)
			std::this_thread::sleep_for(seconds(3));

		auto before = high_resolution_clock::now();

		#pragma omp barrier

		auto after = high_resolution_clock::now();

		#pragma omp critical
		std::cout << "thread " << omp_get_thread_num() 
		          << ": wait sleeping threads for " 
		          << duration_cast<seconds>(after - before).count() << "s"
		          << std::endl;
	}
}
