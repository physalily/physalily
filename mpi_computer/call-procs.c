// call-procs.c:

#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	// mpi variables.
	int num_processes;
	int curr_rank;
	int proc_name_len;
	char proc_name[MPI_MAX_PROCESSOR_NAME];

	// mpi initialize.
	MPI_Init(&argc, &argv);

	// get processor number.
	MPI_Comm_size(MPI_COMM_WORLD, &num_processes);

	// get current proces rank.
	MPI_Comm_rank(MPI_COMM_WORLD, &curr_rank);

	// get currnet thread processor name.
	MPI_Get_processor_name(proc_name, &proc_name_len);

	// print out rank, process number, process name.
	printf("Calling process %d out of %d on %s\n", curr_rank, num_processes, proc_name);

	MPI_Finalize();

	return 0;
}

