#include <stdio.h>
#include <omp.h>

int main()
{
// parm region with 4 threads
#pragma omp parallel num_threads(omp_get_num_procs())
    {                                  // certain amount of thr will be made avail
        int ID = omp_get_thread_num(); // however number speciacally one will run

        printf("Thread %d is the one running and itlll have to wait at a barrier \n", ID);
#pragma omp barrier // all thr must reach this point before running down
                    //                  when we reach this door its not explicityly one at a time
        //  int ID1 = omp_get_thread_num(); // could be a diff thread now that ndetermins is allowed again

        printf("Thr %d reached this point after they reraced at the barrier\n", ID);
    }
    return 0;
}