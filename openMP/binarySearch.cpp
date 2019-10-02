
#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
#define N 400

int binarySearch(int arr[], int l, int r, int x){
    int nthreads, th_id;
    // #pragma omp parallel private(th_id)

    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }


return -1;
}

int main(void)
{
    srand(time(0));
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + size); //sort the array in ascending order

    for (int j = 0; j < N; j++)
    {
        cout << arr[j] << " ";
    }

    cout << endl;
    int x = arr[8];
    int n = sizeof(arr) / sizeof(arr[0]);
    int r = n-1;
    int result = binarySearch(arr, 0, n - 1, x);

    int l=0;

    int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);

    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
    return 0;
}