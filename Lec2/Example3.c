// program prints the content of an existing file

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFER_SIZE 1000


int main(int argc, char const *argv[]) {

  ssize_t read_Items;
  char*buffer[BUFFER_SIZE];
  int fd = open("text3.txt",O_RDWR); //open in read and write mode
  if (fd==-1)
  {
    printf("Failed to open.File non-existent");
  }
  else
  {
    read_Items = read(fd,buffer,BUFFER_SIZE); //from file fd read buffer of size BUFFER_SIZE
    printf("Successful\n");
    printf("%s", buffer);
  }
  return 0;
}
