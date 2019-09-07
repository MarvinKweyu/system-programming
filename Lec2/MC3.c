#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  /* code */
  int fd;
  fd = open("Text.txt",O_RDONLY);
  if (fd==0)
    printf("%s\n",Error );
  else
    printf("%s\n",success );
  return 0;
}
//open(filepath,flags,mode-t mo)
