#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <mpi.h>

#define TAG_DATA 0
#define TAG_CONTROL 1

int SEND_SUM = 2;
int SHUTDOWN = 3;

int TOTAL_PROCESS;
int ACTUAL_PROCESS;
double SIZE = 1000000000;
double SIZE_BY_SLAVE;
double TOTAL_SUM = 0;

void master() {
    double pi;
    double sum;

    // Master sums all the sums received from slaves
    for (int slave = 1; slave < TOTAL_PROCESS; ++slave) {
        MPI_Send(&SEND_SUM, 1, MPI_INT, slave, TAG_CONTROL, MPI_COMM_WORLD);
        MPI_Recv(&sum, 1, MPI_DOUBLE, slave, TAG_DATA, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        TOTAL_SUM += sum;
    }

    // Master shut down all slaves
    for (int slave = 1; slave < TOTAL_PROCESS; ++slave) {
        MPI_Send(&SHUTDOWN, 1, MPI_INT, slave, TAG_CONTROL, MPI_COMM_WORLD);
    }

    // Master calculates PI and prints it
    pi = TOTAL_SUM / SIZE;
    std::cout << "PI is approximately : "
              << std::setprecision(std::numeric_limits<double>::digits10 + 1)
              << pi
              << std::endl;
}

void slave() {
    int message;
    double sum = 0;

    // Slave calculating his part of PI
    double h, x;
    h = 1.0 / (double) SIZE_BY_SLAVE;
    for (int i = 1; i <= SIZE_BY_SLAVE; i++) {
        x = h * ((double) i - 0.5);
        sum += 4.0 / (1.0 + x * x);
    }
    std::cout << "Slave" << ACTUAL_PROCESS << " finished to sum : " << sum << std::endl;

    // Wait for Master to tell him to send his sum
    MPI_Recv(&message, 1, MPI_INT, 0, TAG_CONTROL, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // Slave sends his sum to the Master
    MPI_Send(&sum, 1, MPI_DOUBLE, 0, TAG_DATA, MPI_COMM_WORLD);

    // Wait for Master to tell him to shut down
    MPI_Recv(&message, 1, MPI_INT, 0, TAG_CONTROL, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}

int main(int argc, char **argv) {
    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &TOTAL_PROCESS);
    MPI_Comm_rank(MPI_COMM_WORLD, &ACTUAL_PROCESS);

    // Check if number of node is at least of 10
    if ((TOTAL_PROCESS - 1) < 10) {
        if (ACTUAL_PROCESS == 0)
            std::cout << "Needs to be at least 10 nodes to evaluate PI" << std::endl;
        return (-1);
    }

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