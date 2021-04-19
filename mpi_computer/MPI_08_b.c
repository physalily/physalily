// MPI_08_b.c:

#include <mpi.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int total_iter;
	int n, rank, length, numprocs, i;
	double pi, width, sum, x, rank_integral;
	char hostname[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(hostname, &length);

	if (rank == 0)
	{
		printf("\n");
		printf("###############################################");
		printf("\n\n");
		printf("Master node name: %s\n", hostname);
		printf("\n");
		printf("Enter number of intervals:\n");
		printf("\n");
		scanf("%d", &n);
		printf("\n");
	}

	// broadcast split "n" to all process.
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

	// following loop testing computer power.
	for (total_iter = 1; total_iter < n; total_iter++)
	{
		sum = 0.0;
		width = 1.0 / (double)total_iter;
		// width = 1.0 / (double)n;

		for (i = rank + 1; i <= total_iter; i += numprocs)
		// for (i = rank + 1; i <= n; i += numprocs)
		{
			x = width * ((double)i - 0.5); // distance to center of splited No. i.
			sum += 4.0 / (1.0 + x * x); // sum of rank height.
		}

		// rank area
		rank_integral = width * sum;

		// sum all process
		MPI_Reduce(&rank_integral, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	} // loop ended.

	if (rank == 0)
	{
		printf("\n");
		printf("*** Numver of processes: %d\n", numprocs);
		printf("\n\n");
		printf("     Calculated pi = %.16f\n", pi);
		printf("              M_PI = %.16f\n", M_PI);
		printf("    Relative Error = %.16f\n", fabs(pi-M_PI));
		// printf("Process %d on %s has the partial result of %.16f\n",
		// 	rank, hostname, rank_integral);
	}

	// clean up. finalize mpi
	MPI_Finalize();
	
	return 0;
} // end of main

