
//compile: mpic++ <filename>
// exec: mpiexec np3 ./a.out (preferred) OR mpirun

#include<iostream>
#include<stdio.h>
#include <mpi.h>

#define MASTER 0

using namespace std;

int main(int argc, char* argv[]){

    int numtasks, taskid, len;
    char hostname[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &taskid);
    MPI_Get_processor_name(hostname, &len);

    cout<<"hello form the task "<<taskid<<" on "<<hostname<<endl;
    if(taskid == MASTER){
        cout<<"Master: Number of MPI Tasks is: "<<numtasks<<endl;
    }
    MPI_Finalize();

}
