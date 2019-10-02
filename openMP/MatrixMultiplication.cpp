#include <iostream>
#include <omp.h>
#include <stdlib.h>
using namespace std;
#define N 400



// This function multiplies
// mat1[][] and mat2[][], and
// stores the result in res[][]
void multiply(int mat1[][N], int mat2[][N], int res[][N], int threads)
{
    // int k;
    omp_set_dynamic(0);
    #pragma omp parallel num_threads(threads)
    
    #pragma omp for 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                res[i][j] = 0;
                for (int k = 0; k < N; k++)
                    res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    
}

// Driver Code
int main()
{
    
    double dtime;
    int mat1[N][N], mat2[N][N],result[N][N], threads;

    for (int i = 0; i < N; i++)
    {
        for (int j=0; j < N; j++)
        {
            mat1[i][j] = rand() / RAND_MAX;
            mat2[i][j] = rand() / RAND_MAX;
        }
    }

   
        threads = 8;
        dtime = omp_get_wtime();
        multiply(mat1, mat2,result, threads);
        cout<<"Thread "<<threads<<" seconds ";
        dtime = omp_get_wtime()-dtime;
        cout<<dtime<<" time"<<endl;



    return 0;
}
