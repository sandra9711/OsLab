#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  printf("In exec2.c\n");
  printf("PID => exec2.c %d\n",getpid());
  return 0;
}