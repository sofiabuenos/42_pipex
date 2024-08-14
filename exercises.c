/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:41:01 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/13 18:49:00 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <sys/types.h> 
// #include <fcntl.h>
// #include <errno.h>

// // UNIX PROCESSES IN C - CodeVault
// // FORK () //
// /**
//  * A process is an instance of a running program. 
//  * Every single process in linux has a PID
//  * Processes can create other processes, called child processes.
//  * 
//  * The fork() function is used to create a new child process 
//  * from the main process.
//  * Fork function clones the calling process, creating an exact copy.
//  * This means that the parent's process memory is being copied value 
//  * by value but in different
//  * memory adresses (like a dup)
//  * 
//  * Fork function returns -1 for errors.
//  * The fork() function returns 0 in the child process. 
//  * This 0 is not the process ID (PID); 
//  * rather, it is just an indication from fork() that the process is 
//  * the child.
//  * In the parent process, fork() returns the PID of the newly created child 
//  * process.
//  * 
//  * Everything that is below the fork function is duplicated.
//  */

// int exercise_1()
// {
// 	int id = fork();
// 	//printf("Hello World from id: %d\n", id);

// 	// if (id == 0)
// 	// 	printf("Hello from child process\n");
// 	// else
// 	// 	printf("Hello from the main process\n");

// 	if (id != 0)
// 	{
// 		fork();
// 	}
// 	printf("Hello world\n");
// 	return (0);
// }

// /**
//  * parent and child processes are handled in nearly simultanious order
//  * function wait() is a handy resource for waiting processes to finish
//  * 
//  * pid_t wait(int *status);

//  * function wait waits for the return (0) of the other function to proceed
//  * with the other remaining process.
//  * 
//  * function wait returns the child process pid or -1 if 
//  * there's an error or no child to wait for.

//  * we call fflush because we want to print the numbers at the exact time
//  * as they are called, since printf has a buffer it wouldn't allow it.
//  */

// int exercise_2()
// {
// 	int id = fork();
// 	int n;
// 	int i;

// 	if (id == 0)
// 		n = 1;
// 	else
// 		n = 6;
// 	if (id != 0)
// 		wait(&id);
// 	for (i = n; i < n + 5; i++)
// 	{
// 		printf("%d ", i);
// 		fflush(stdout);
// 	}
// 	return (0);
// }
// // GETPID  GETPPID//
// /**
//  * #include <sys/wait.h> 
//  * pid_t getpid(void); -> return the current id
//  * pid_t getppid(void); -> returns the parent id
//  * 
//  *  ! if the parent terminates before the child does, 
//  * we will have memory leak.
//  * This happens because the child is assigned another parent id because the
//  * (first) parent had already terminated while the child was still running.
//  *  So, when we try to kill the process, it is not going to actually 
//  * free the memory.
//  * -> so, ALWAYS WAIT FOR THE CHILD PROCESSES TO FINISH <-
//  * Therefore, it is good practice to call wait() in the end of each function 
//  * that uses fork().
//  * 
//  * function wait returns -1 if there is nothing to wait for or the 
//  * id of the process you actually waited for.

//  * Example of what I got when running the code:
//  * Current ID: 23047, Parent ID: 5214 |-> parent
//  * Current ID: 23049, Parent ID: 23047|-> child
//  * No children to wait for.           |-> msg when the child was running
//  * 23049 finished execution.          |-> we waited for the child to finish.
//  */

// int	exercise_3()
// {
// 	int id = fork();
// 	if (id == 0)
// 		sleep(1); // faz com que o child tenha um delay de 1 segundo
// 	printf("Current ID: %d, Parent ID: %d\n",
// 		 getpid(), getppid());
// 	int res = wait(NULL);
// 	if (res == -1)
// 		printf("No children to wait for.\n");
// 	else
// 		printf("%d finished execution.\n", res);
// 	return (0);
// }
// /**
//  * Multiple forks
//  * 
//  * while (wait(NULL) != -1 || errno != ECHILD)
//  * wait(NULL) != -1 -> keeps waiting while `wait`returns a valid pid
//  * ECHILD -> informs whether the parent process still has child processes 
//  * to wait for.
//  * Quando você usa a função wait ou waitpid, estas funções retornam -1 se 
//  * ocorre um erro. 
//  * Se o erro for devido à ausência de processos filhos 
//  * (todos os filhos já terminaram), errno é definido como ECHILD.
//  */
// int	exercise_4()
// {
// 	int id1 = fork();
// 	int id2 = fork();
// 	if (id1 == 0)
// 	{
// 		if (id2 == 0)
// 			printf("we are process y\n");
// 		else
// 			printf("we are process x\n");
// 	}
// 	else
// 	{
// 		if (id2 == 0)
// 			printf("we are process z\n");
// 		else
// 			printf("we are the parent process\n");
// 	}
// 	while (wait(NULL) != -1 || errno != ECHILD)
// 		printf("Waited for a child to finish.\n");
// 	return (0);
// }
// /** PIPE FUNCTION
//  * A pipe is like an in-memory file. it is like a buffer from
//  *  which we can write and read.
//  * it takes an array of two integers that will be used to save 
//  * the file descriptors used to comunicate between one end and the other.
//  * returns 0 if sucessful and -1 if there's a mistake
//  */

// int	exercise_5(int ac, char **av)
// {
// 	int fd[2];
// 	// fd[0] -> read
// 	// fd[1] -> write
// 	if (pipe(fd) == -1)
// 	{
// 		printf("an error ocurred with opening the pipe\n");
// 		return (1);
// 	}
// 	int id = fork();
// 	if (id == -1)
// 	{
// 		printf("an error ocurred with opening the fork\n");
// 		return (4);
// 	}
// 	if (id == 0)
// 	{
// 		close(fd[0]); // closes reading fd because the child process only writes
// 		int x;
// 		printf("Input a number: \n");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x, sizeof(int)) == -1)
// 		{
// 			printf("an error ocurred with writing to the pipe\n");
// 			return (2);
// 		}
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		int y;
// 		if (read(fd[0], &y, sizeof(int)) == -1)
// 		{
// 			printf("an error ocurred with reading from the pipe\n");
// 			return (3);
// 		}
// 		close(fd[0]);
// 		printf("Got from child process: %d\n", y);
// 	}
// 	return (0);
// }

// int exercise_6()
// {
// 	int fd_output = open("output.txt", O_WRONLY | O_CREAT |
//        O_TRUNC, S_IRUSR | S_IWUSR);
//     if (fd_output == -1) {
//         perror("Erro ao abrir o arquivo");
//         return 1;
//     }

//     // Redireciona stdout para o arquivo output.txt
//     if (dup2(fd_output, STDOUT_FILENO) == -1) {
//         perror("Erro ao redirecionar stdout");
//         close(fd_output); // Fecha o descritor de arquivo se dup2 falhar
//         return 1;
//     }

//     // Agora, qualquer saída do programa será escrita em output.txt
//     printf("Hello, World!\n");

//     close(fd_output); // Fecha o descritor de arquivo após terminar
//     return 0;
// }
// int main(int ac, char **av)
// {
// 	//exercise_1();
// 	//exercise_2();
// 	//exercise_3();
// 	//exercise_4();
// 	//exercise_5(ac, av);
// 	exercise_6();
// 	return (0);
// }
