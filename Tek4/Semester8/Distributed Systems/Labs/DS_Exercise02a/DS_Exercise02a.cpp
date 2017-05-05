#include <iostream>
#include <stdlib.h>
#include <mpi.h>

#define TAG_DATA 0
#define TAG_CONTROL 1

int SEND_SUM = 2;
int SHUTDOWN = 3;

int SIZE = 100000;
int TOTAL_PROCESS;
int ACTUAL_PROCESS;
int SIZE_BY_SLAVE;
int TOTAL_SUM = 0;

void master() {
    int array[SIZE];
    int sum;

    // Master creates a randomly filled array of size SIZE
    srand(ACTUAL_PROCESS);
    for (int i = 0; i < SIZE; ++i)
        array[i] = rand() % 100 + 1;

    // Master send their part of the array to slaves
    for (int slave = 1, pos = 0; slave < TOTAL_PROCESS; ++slave) {
        MPI_Send(array + pos, SIZE_BY_SLAVE, MPI_INT, slave, TAG_DATA, MPI_COMM_WORLD);
        pos += SIZE_BY_SLAVE;
    }

    // Master sums all the sums received from slaves
    for (int slave = 1; slave < TOTAL_PROCESS; ++slave) {
        MPI_Send(&SEND_SUM, 1, MPI_INT, slave, TAG_CONTROL, MPI_COMM_WORLD);
        MPI_Recv(&sum, 1, MPI_INT, slave, TAG_DATA, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        TOTAL_SUM += sum;
    }
    std::cout << "Master summed result from all slaves as : " << TOTAL_SUM << std::endl;

    // Master shut down all slaves
    for (int slave = 1; slave < TOTAL_PROCESS; ++slave) {
        MPI_Send(&SHUTDOWN, 1, MPI_INT, slave, TAG_CONTROL, MPI_COMM_WORLD);
    }
}

void slave() {
    int message;
    int array[SIZE_BY_SLAVE];
    int sum = 0;

    // Receives array from the Master
    MPI_Recv(&array, SIZE_BY_SLAVE, MPI_INT, 0, TAG_DATA, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // Slave sums the array received then print the result
    for (int i = 0; i < SIZE_BY_SLAVE; ++i)
        sum += array[i];
    std::cout << "Slave" << ACTUAL_PROCESS << " finished to sum : " << sum << std::endl;

    // Wait for Master to tell him to send his sum
    MPI_Recv(&message, 1, MPI_INT, 0, TAG_CONTROL, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // Slave sends his sum to the Master
    MPI_Send(&sum, 1, MPI_INT, 0, TAG_DATA, MPI_COMM_WORLD);

    // Wait for Master to tell him to shut down
    MPI_Recv(&message, 1, MPI_INT, 0, TAG_CONTROL, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}

int main(int argc, char **argv) {
    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &TOTAL_PROCESS);
    MPI_Comm_rank(MPI_COMM_WORLD, &ACTUAL_PROCESS);

    // Calculates the work done by each slave
    SIZE_BY_SLAVE = SIZE / (TOTAL_PROCESS - 1);

    if (ACTUAL_PROCESS == 0) {
        master();
    } else {
        slave();
    }

    MPI_Finalize();

    return (0);
}