// Gregory_Leibniz.c

#include <mpi.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  int total_iter;
  int n, rank, length, numprocs;
  double rank_sum, pi, sum, A;
  unsigned long i, k;
  char hostname[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(hostname, &length);

  if (rank == 0)
  {
    printf("\n");
    printf("#######################################");
    printf("\n\n");
    printf("Master node name: %s\n", hostname);
    printf("\n");
    printf("Enter the number of intervals:\n");
    printf("\n");
    scanf("%d", &n);
    printf("\n");
  }

  // split "n" broadcast to all node 
  MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

  // testing loop
  for (total_iter = 1; total_iter < n; total_iter++)
  {
    sum = 0.0;
    for (i = rank + 1; i <= total_iter; i += numprocs)
    {
      k = i - 1;
      A = (double)pow(-1,k) * 4.0 / (double)(2*k + 1);

      sum += A;
    }

    rank_sum = sum; // rank sum
    // all process adder
    MPI_Reduce(&rank_sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  } // end of for loop

  if (rank == 0)
  {
    printf("\n\n");
    printf("*** Number of processes: %d\n", numprocs);
    printf("\n\n");
    printf("     Calculated pi = %.30f\n", pi);
    printf("              M_PI = %.30f\n", M_PI);
    printf("    Relative Error = %.30f\n", fabs(pi-M_PI));
    printf("\n");
  }

  // clean up, fainalize mpi
  MPI_Finalize();

  return 0;
} // end of main