#include <iostream>
#include <stdlib.h>
#include <mpi.h>

#define TAG_DATA 0
#define TAG_CONTROL 1

int CREATE_ARRAY = 1;
int END_ARRAY = 2;
int SHUTDOWN = 3;

int SIZE = 200;
int TOTAL_PROCESS;
int ACTUAL_PROCESS;
int SIZE_BY_SLAVE;

// Display an array
void displayArray(int *array) {
    std::cout << "[";
    for (int i = 0; array[i] >= 0; ++i) {
        std::cout << array[i];
        if (array[i + 1] >= 0)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void master() {
    int message_type;
    int array[TOTAL_PROCESS - 1][SIZE_BY_SLAVE + 1];
    int assembledArray[((TOTAL_PROCESS - 1) * SIZE_BY_SLAVE) + 1];

    // Master tell slaves to create their array
    for (int slave = 1; slave < TOTAL_PROCESS; ++slave) {
        MPI_Send(&CREATE_ARRAY, 1, MPI_INT, slave, TAG_CONTROL, MPI_COMM_WORLD);
    }

    // Master receives arrays from slaves
    for (int slave = 1; slave < TOTAL_PROCESS; ++slave) {
        MPI_Recv(&array[slave - 1], SIZE_BY_SLAVE + 1, MPI_INT, slave, TAG_DATA, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Master shut down all slaves
    for (int slave = 1; slave < TOTAL_PROCESS; ++slave) {
        MPI_Send(&SHUTDOWN, 1, MPI_INT, slave, TAG_CONTROL, MPI_COMM_WORLD);
    }

    // Master assembles the arrays in one
    for (int i = 0, k = 0; i < (TOTAL_PROCESS - 1); ++i) {
        for (int j = 0; j < SIZE_BY_SLAVE; ++j) {
            assembledArray[k] = array[i][j];
            ++k;
        }
    }
    assembledArray[((TOTAL_PROCESS - 1) * SIZE_BY_SLAVE)] = -1;
    std::cout << "Master assembled the arrays : " << std::endl;
    displayArray(assembledArray);
}

void slave() {
    int message;
    int array[SIZE_BY_SLAVE + 1];

    // Slave create an array of size SIZE_BY_SLAVE randomly filled then print it on the screen
    srand(ACTUAL_PROCESS);
    for (int i = 0; i < SIZE_BY_SLAVE; ++i)
        array[i] = rand() % SIZE + 1;
    array[SIZE_BY_SLAVE] = -1;
    std::cout << "Slave" << ACTUAL_PROCESS << " finished to create array : ";
    displayArray(array);

    // Slave sends the array to Master
    MPI_Send(array, SIZE_BY_SLAVE + 1, MPI_INT, 0, TAG_DATA, MPI_COMM_WORLD);

    // Wait for Master to tell him to shut down
    MPI_Recv(&message, 1, MPI_INT, 0, TAG_CONTROL, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}

int main(int argc, char **argv) {
    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &TOTAL_PROCESS);
    MPI_Comm_rank(MPI_COMM_WORLD, &ACTUAL_PROCESS);

    // Check if number of nodes divides evenly the work
    if (SIZE % (TOTAL_PROCESS - 1) != 0) {
        if (ACTUAL_PROCESS == 0)
            std::cout << "Number of nodes (" << TOTAL_PROCESS - 1 << ") divides not evenly into " << SIZE << std::endl;
        return (-1);
    }

    // Calculates the work done by each slave
    SIZE_BY_SLAVE = SIZE / (TOTAL_PROCESS - 1);

    if (ACTUAL_PROCESS == 0)
        master();
    else
        slave();

    MPI_Finalize();

    return (0);
}