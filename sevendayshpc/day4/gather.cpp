#include <cstdio>
#include <mpi.h>
#include <vector>

const int L = 8;

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  int rank, procs;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &procs);
  const int mysize = L / procs;
  // local data initalize in my rank No.
  std::vector<int> local(mysize, rank);
  // varibale for catch up from global data.
  std::vector<int> global(L);
  // communicate to rank zero.
  MPI_Gather(local.data(), mysize, MPI_INT, global.data(), mysize, MPI_INT, 0, MPI_COMM_WORLD);

  // rank zero display as a representative.
  if (rank == 0) {
    for (int i = 0; i < L; i++) {
      printf("%d", global[i]);
    }
    printf("\n");
  }
  MPI_Finalize();
  return 0;
}