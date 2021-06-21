#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
    //initialize MPI environment
    MPI_Init(&argc, &argv);
    
    //get rank of process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    //get number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    //----------------------------------------
    
    //calculate sum of ranks
    int ranks[world_size];
    
    //initialize array with ranks if process is rank 0
    if (world_rank == 0){
        for (int i = 0; i < world_size; i++){
            ranks[i] = i;
        }
    }
    
    //scatter the array between all the processes
    int scatteredRank = 0;
    MPI_Scatter(&ranks, 1, MPI_INT, &scatteredRank, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    //reduce the array to a sum of the ranks sent to process 0
    int result = 0;
    MPI_Reduce(&scatteredRank, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
    //process 0 prints the sum
    if (world_rank == 0){
        printf("Reduction result from Rank %d: %d\n", world_rank, result);
    }
    
    //----------------------------------------
    
    //finalize MPI environment
    MPI_Finalize();
    return(0);
}
