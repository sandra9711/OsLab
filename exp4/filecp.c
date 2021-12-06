// C program to illustrate
//open, write ,read and close system Call
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>
int main()
{
int sz,szf,szi,sz1;
char *c = (char *) calloc(100, sizeof(char));
char *buf = (char *) calloc(100, sizeof(char));
int fd = open("foo.txt", O_RDWR , 0);
int fd1 = open("sample.txt", O_RDONLY, 0); 
if (fd < 0)
{
	perror("r1");
	exit(1);
}
sz1 = read(fd, c , 56);
printf("File before writing contains \n%s \n",c);
printf("\n");
szi = read(fd1, c, 56);
printf("File to be red contains \n%s \n",c);
sz = write(fd, c, 56);

int fd2 = open("foo.txt", O_RDWR , 0);
szf = read(fd2, buf, 58);

if(szf>1){
  printf("File after writing contains \n%s \n",buf);
}
//printf("File after writing contains \n%s \n",buf);

if(close(fd)==0){
  printf("File descriptor closed\n");
}
else if(close(fd)==-1){
  printf("File descriptor not closed\n");
}

return 0;
}
