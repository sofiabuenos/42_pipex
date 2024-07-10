#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * A process is an instance of a running program. Every single process in linux has a PID
 * Processes can create other processes, called child processes.
 * The fork() function is used to create a new child process.
 * Fork function clones the calling process, creatin an exact copy.
 * It returns -1 for errors, 0 for the child process and the ID of the parent process
 * Everything that is below the fork function is duplicated.
 */

int exercise_1()
{
	int id = fork();
	//printf("Hello World from id: %d\n", id);

	// if (id == 0)
	// 	printf("Hello from child process\n");
	// else
	// 	printf("Hello from the main process\n");

	if (id != 0)
	{
		fork();
	}
	printf("Hello world\n");
	return (0);
}

/**
 * parent and child processes are handled in nearly simultanious order
 * function wait() is a handy resource for waiting processes to finish
 */

int exercise_2()
{

}

int main(void)
{
	exercise_1();
	exercise_2()
	return(0);
}