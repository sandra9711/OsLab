#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  DIR *d;
  int fd;
  struct stat buf;
  struct dirent *de;

  fd = open("sample.txt",O_RDONLY);
  stat("sample.txt",&buf);
  printf("file size %ld \nfile mode %d \n",buf.st_size,buf.st_mode);
  d=opendir(".");
  printf("\n");
  printf("Directory contains\n");
  while(de=readdir(d)){
    printf("%s\t length of the record:%d \t type of the file%d\n",de->d_name,de->d_type,de->d_reclen);
  }
  if(close(fd)==0){
    printf("file descriptor closed\n");
  }else if(close(fd)==-1){
    printf("file descriptor not closed\n");
  }
  return 0;
}