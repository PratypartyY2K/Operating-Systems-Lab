#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	// fork() Create a child process

	int pid = fork();
	if (pid == 0)
	{
		//getpid() returns process id
		// while getppid() will return parent process id
		printf("Child process\n");
		printf("ID : %d\n\n",getpid());
		printf("Parent's Process ID: %d\n", getppid());
	}
	else if (pid > 0)
	{
		sleep(30);

		printf("\nParent process \n");
		printf("ID: %d\n", getpid());
		printf("Parent -ID: %d\n",getppid());
	}
	else
	{
		printf("Failed to create child process");
	}
	
	return 0;
}
