#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main(int argc, char *argv[]) {
  pid_t pid = fork();
 
  if(pid == 0) {
    printf("Child -> ppid: %d PID: %d\n", getppid(), getpid());
    exit(EXIT_SUCCESS);
  }
  else if(pid > 0) {
    printf("Parent -> pid: %d\n", getpid());
    printf("Waiting for child process to finish.\n");
    wait(NULL);
    printf("Child process finished.\n");
  }
  else {
    printf("Unable to create child process.\n");
  }
  char *args[] = {"Hello", "C", "Programming", NULL};
  execv("./exec2", args);
  
  return EXIT_SUCCESS;
}

//https://linuxhint.com/fork_linux_system_call_c/