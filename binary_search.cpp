#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;
# define N 5

int main()
{
	int count, i, arr[N], num, first, last, middle;
    double dtime;

    srand(time(0)); 
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + size); //sort the array in ascending order

    // for (int j = 0; j < N; j++)          for displaying array contents
    // {
    //     cout << arr[j] << " ";
    // }

    num = arr[1];
	first = 0;
	last = N-1;
	middle = (first+last)/2;
    int threads = 4;

    
    omp_set_dynamic(0);
    // for(; threads<=4;threads++){


    #pragma omp parallel num_threads(threads)
    dtime = omp_get_wtime();
	while (first <= last)
	{
	   if(arr[middle] < num)
	   {
		first = middle + 1;

	   }
	   else if(arr[middle] == num)
	   {
		cout<<num<<" found in the array at the location "<<middle<<"\n"; 
                break;

           } 
           else { 
                last = middle - 1; 
           } 
           middle = (first + last)/2; 
        } 
        if(first > last)
	{
	   cout<<num<<" not found in the array";
	}
    dtime = omp_get_wtime()-dtime;
    cout<<"time taken for "<<threads<<" threads is "<<dtime<<endl;
    // }

	return 0;
}