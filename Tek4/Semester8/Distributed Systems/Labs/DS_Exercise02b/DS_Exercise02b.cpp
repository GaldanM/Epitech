#include <iostream>
#include <stdlib.h>
#include <mpi.h>

#define TAG_DATA 0
#define TAG_CONTROL 1

int SEND_SUM = 2;
int SHUTDOWN = 3;

int SIZE = 120000;
int TOTAL_PROCESS;
int ACTUAL_PROCESS;
int SIZE_BY_SLAVE_ODD;
int SIZE_BY_SLAVE_EVEN;
int TOTAL_SUM = 0;

void master() {
    int array[SIZE];
    int sum;

    // Master creates a randomly filled array of size SIZE
    srand(ACTUAL_PROCESS);
    for (int i = 0; i < SIZE; ++i)
        array[i] = rand() % 100 + 1;

    // Master send their part of the array to slaves
    for (int slave = 1, posOdd = 0, posEven = 0; slave < TOTAL_PROCESS; ++slave) {
        if (slave % 2 == 1) {
            MPI_Send(array + posOdd, SIZE_BY_SLAVE_ODD, MPI_INT, slave, TAG_DATA, MPI_COMM_WORLD);
            posOdd += SIZE_BY_SLAVE_ODD;
        } else {
            MPI_Send(array + posEven + (SIZE / 2), SIZE_BY_SLAVE_EVEN, MPI_INT, slave, TAG_DATA, MPI_COMM_WORLD);
            posEven += SIZE_BY_SLAVE_EVEN;
        }
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

void slaveEven() {
    int message;
    int array[SIZE_BY_SLAVE_EVEN];
    int sum = 0;

    // Receives array from the Master
    MPI_Recv(&array, SIZE_BY_SLAVE_EVEN, MPI_INT, 0, TAG_DATA, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // Slave sums the array received then print the result
    for (int i = 0; i < SIZE_BY_SLAVE_EVEN; ++i)
        sum += array[i];
    std::cout << "Slave" << ACTUAL_PROCESS << " finished to sum : " << sum << std::endl;

    // Wait for Master to tell him to send his sum
    MPI_Recv(&message, 1, MPI_INT, 0, TAG_CONTROL, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // Slave sends his sum to the Master
    MPI_Send(&sum, 1, MPI_INT, 0, TAG_DATA, MPI_COMM_WORLD);

    // Wait for Master to tell him to shut down
    MPI_Recv(&message, 1, MPI_INT, 0, TAG_CONTROL, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}

void slaveOdd() {
    int message;
    int array[SIZE_BY_SLAVE_ODD];
    int sum = 0;

    // Receives array from the Master
    MPI_Recv(&array, SIZE_BY_SLAVE_ODD, MPI_INT, 0, TAG_DATA, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // Slave sums the array received then print the result
    for (int i = 0; i < SIZE_BY_SLAVE_ODD; ++i)
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

    // Calculates the work done by each even slave and odd slave
    if ((TOTAL_PROCESS - 1) % 2 == 1) {
        if ((TOTAL_PROCESS - 1) == 1) {
            SIZE_BY_SLAVE_EVEN = 0;
            SIZE_BY_SLAVE_ODD = SIZE;
        } else {
            SIZE_BY_SLAVE_EVEN = (SIZE / 2) / (TOTAL_PROCESS / 2 - 1);
            SIZE_BY_SLAVE_ODD = (SIZE / 2) / (TOTAL_PROCESS / 2);
        }
    } else {
        SIZE_BY_SLAVE_EVEN = SIZE / (TOTAL_PROCESS - 1);
        SIZE_BY_SLAVE_ODD = SIZE_BY_SLAVE_EVEN;
    }

    if (ACTUAL_PROCESS == 0)
        master();
    else if (ACTUAL_PROCESS % 2 == 0) {
        if (SIZE_BY_SLAVE_EVEN > 0)
            slaveEven();
    } else
        slaveOdd();

    MPI_Finalize();

    return (0);
}