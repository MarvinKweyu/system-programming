// program that reads file1 content and writes it in file2
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1000

int main(int argc, char const *argv[]) {
  /* code */
  ssize_t read_items;
  char * buffer[BUFFER_SIZE];
  int fd;
  fd = open("file1.txt",O_RDWR);
  if (fd == -1)
  {
    printf("Failed to open\n");
  }
  else
  {
  read_items = read(fd,buffer,BUFFER_SIZE);
  printf("%s\n",buffer);
  file2 = open("file2.txt",O_RDWR);
  write-items = write()
}
return 0;
}
