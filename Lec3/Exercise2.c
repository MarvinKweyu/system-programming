// program that reads file1 content and writes it in file2

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUFFER_SIZE 1000

int main(int argc, char* argv[]) {

  int fd1;
  int fd2;
  char* buffer[BUFFER_SIZE];
  ssize_t nmread;
  fd1 = open(argv[1],O_RDONLY);
  mode_t filePerm = O_CREAT|O_WRONLY|O_TRUNC;
  mode_t Modules= S_IWUSR|S_IRWXO|S_IXUSR;
  fd2 = open(argv[2],filePerm,Modules);
  if (fd2==-1)
  {
    printf("Failed");
  }
  while (nmread=read(fd1,buffer,BUFFER_SIZE)>0) { //while there is still content to be read

    if (write(fd2,buffer,BUFFER_SIZE)!=nmread) //what is written should be equal to what's been read
    {
      printf("NOT EQUAL");
      close(fd1);
      close(fd2);
    }
  }
  return 0;
}
