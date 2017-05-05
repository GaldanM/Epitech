#include <iostream>
#include <mpi.h>

int main(int argc, char **argv) {
    int world_size;
    int world_rank;

    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0) {
        std::cout << "MOULINNEUF Galdan 2927686" << std::endl;
        std::cout << "Number of processors : " << world_size << std::endl;
    }

    std::cout << "Processor rank : " << world_rank << std::endl;

    MPI_Finalize();

    return (0);
}