#include<stdio.h>
#include<unistd.h>
int main() {
	int a = fork();
	if (a == 0) {
		printf("I am a child process with id: %d",getpid());
		printf("My parent process id is: %d",getppid());
	} else {
		printf("I am the parent process with id: %d",getpid());
		printf("My parent process id is: %d",getppid());
	}
	return 0;
}

		
