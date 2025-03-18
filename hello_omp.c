#include <stdio.h>
#include <omp.h>
int main()
{
	// Parallel region with default number of threads/procceses in my sys
	int num;
	num = omp_get_num_procs();
	printf("number of defualt processes %d \n ", num);
	omp_set_num_threads(4);
	double start_time, end_time;
	start_time = omp_get_wtime();
#pragma omp parallel num_threads(num) // for each thread just print the below code for each thread,
									  // threads are parallel but dont finsih exa tly at the same time
									  // non deterministic
	// Start of the parallel region
	{
		//		//Runtime library function to return a thread number
		int ID = omp_get_thread_num(); // get the number of the thread that finsihed this line first?

		if (ID == 7)
		{
			printf("Hello World! (Thread: %d)\n", ID);
		}
	}

	end_time = omp_get_wtime();

	printf("the parallel program with %d amount of processes took %.2f + %.2f amount of time", num, end_time, start_time);
	// End of the parallel region
	return 0;
}
