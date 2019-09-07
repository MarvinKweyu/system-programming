//accepts user input and writes to file

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1000

int main(int argc, char const *argv[]) {

  char str[100];
  // char* str[BUFFER_SIZE];
  mode_t filePerm = O_CREAT|O_WRONLY|O_TRUNC;
  mode_t Modules= S_IWUSR|S_IRWXO|S_IXUSR;
  int fd = open("sample.txt",filePerm,Modules);

  printf("Enter a value: ");
  scanf("%s",str);
  // write(fd,buffer,BUFFER_SIZE);
  write(fd,str,BUFFER_SIZE);
  printf("writing file..");
  close(fd);
  return 0;
}
