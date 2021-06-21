#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
    //initialize MPI environment
    MPI_Init(&argc, &argv);
    
    //number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    //rank of process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    //print hello world
    printf("Hello world from %d out of %d processes\n", world_rank, world_size);
    
    //finalize MPI environment
    MPI_Finalize();
    return 0;
}
