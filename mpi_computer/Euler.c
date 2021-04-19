// Euler.c:

#include <mpi.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  int total_iter;
  int n, rank, length, numprocs, i;
  double sum, sum0, rank_integral, A;
  char hostname[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);                     // initialize MPI.
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);   // get processes number.
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);       // get currnet process ID.
  MPI_Get_processor_name(hostname, &length);  // get hostname.

  if (rank == 0) 
  {
    printf("\n");
    printf("####################################################");
    printf("\n\n");
    printf("Master node name: %s\n", hostname);
    printf("\n");
    printf("Enter the number of intervals:\n");
    printf("\n");
    scanf("%d", &n);
    printf("\n");
  }

  // broadcast split number "N" to all processes.
  MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

  // test loop.
  for (total_iter = 1; total_iter < n; total_iter++)
  {
    sum0 = 0.0;
    for (i = rank + 1; i < total_iter; i += numprocs)
    {
      A = 1.0 / (double)pow(i,2);
      sum0 += A;
    }

    rank_integral = sum0; // part sum in same rank.

    MPI_Reduce(&rank_integral, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } // end of for loop.

  if (rank == 0)
  {
    printf("\n\n");
    printf("*** Number of processes: %d\n", numprocs);
    printf("\n\n");
    printf("     Calculated pi = %.30f\n", sqrt(6*sum));
    printf("              M_PI = %.30f\n", M_PI);
    printf("    Relative Error = %.30f\n", fabs(sqrt(6*sum)-M_PI));
    printf("\n");
  }

  // clean up, MPI Finalize.
  MPI_Finalize();

  return 0;
} // end of main