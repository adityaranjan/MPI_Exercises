#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
    //initialize MPI environment
    MPI_Init(&argc, &argv);
    
    //get number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    //get rank of process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    //----------------------------------------
    
    //calculate sum of ranks
    int result = 0;
    
    //processes that are not rank 0 wait for message from the left
    if (world_rank != 0){
        MPI_Recv(&result, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    
    //all processes add world_rank to the sum and send it to the right (wrapped aroud using modular divison)
    result += world_rank;
    MPI_Send(&result, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);
    
    //rank 0 process receives message from the last process
    if (world_rank == 0){
        MPI_Recv(&result, 1, MPI_INT, world_size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    
    //all processes share the sum using broadcast and print it
    MPI_Bcast(&result, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Rank %d: result is %d\n", world_rank, result);
    
    //----------------------------------------
    
    //finalize MPI environment
    MPI_Finalize();
    return(0);
}
