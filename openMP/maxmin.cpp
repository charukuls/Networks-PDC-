#include <iostream>
#include <stdio.h>
#include <time.h>
#include <omp.h>

using namespace std;
#define N 4000

void max(int arr[], int threads)
{
    omp_set_dynamic(0);
    int max = arr[0];
#pragma omp num_threads(threads) reduction(max : max)
#pragma omp for
    for (int i = 0; i < N; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

cout << "maximum = "<<max<<endl;

}

void min(int arr[], int threads)
{
    omp_set_dynamic(0);

    int min = arr[0];
#pragma omp num_threads(threads)  reduction(min : min)
#pragma omp for
    for (int i = 0; i < N; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }

cout<<"minimum = " << min<<endl;
}

int main()
{
    int threads = 1;
    int arr[N];
    double dtime, dtime2;
    srand(time(0));

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }
    dtime = omp_get_wtime();
    max(arr, threads);
    dtime=omp_get_wtime()-dtime;
    cout<<"Time taken to find by "<<threads<<" threads: "<<dtime<<endl;
     dtime2 = omp_get_wtime();
    min(arr, threads);
    dtime2=omp_get_wtime()-dtime2;
    cout<<"Time taken to find by "<<threads<<" threads: "<<dtime<<endl;
    return 0;
}