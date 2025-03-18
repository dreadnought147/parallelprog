#include <stdio.h>
#include <omp.h>

int main()
{
    int counter = 0; // define a counter that should be equal to the number of threads

#pragma omp parallel num_threads(omp_get_num_procs())

    {
        int id = omp_get_thread_num();
        // counter++; /// when we leave it like this we come acroos what we call the race condition where thrieads run simaltanously for a cod
        // piece, each thread is trying to do the same thing at same time *at same place* some may compete
        //  some win and others values are lost,. so thread 1 will read and increment, but before it writes
        //  thread 0 also reads and increments so they bith opdate va;ue to 1;
/////BUT/////
#pragma omp critical
        {
            // will only allow one thread to run this so when we reach this door its one at a time
            counter++;
        }

        printf("thread %d:  here without crictacl count %d amount of times\n", id, counter);
    }

    return 0;
}