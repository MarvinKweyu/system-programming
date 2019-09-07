// reads input from user and displays it

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUFFER_SIZE 20

int main() {
  /* code */
  int fd;
  char* buffer[BUFFER_SIZE];
  // the STDIN_FILENO is the input..a CLI input
  // the input has to be same as the buffer size
  // fd = read(STDIN_FILENO,buffer,BUFFER_SIZE);
  fd = read(1,buffer,BUFFER_SIZE);
  if (fd==-1)
  {
  printf("Failed" );
  }
  else
  {
    printf("I have read:%s\n",buffer );
  }
return 0;
}
