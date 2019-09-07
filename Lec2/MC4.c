//program shows error if file it's trying to open is abscent
//note that the brackets are my own adding in the if statement

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  /* code */
  int fd;
  fd = open("text.txt",O_RDONLY/O_CREAT);

  if (fd ==-1)
  {
    printf("Error\nYour file does not exist");
  }
  else
  {
    printf("Success.\nYour file is present" );
  }

    return 0;
}
