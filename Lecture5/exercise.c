#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#define BUFFER_SIZE 1000

int main(int argc,char*argv[]){
  // printf(argv[-1] );
  for (int i=0;i<5;i++)
  {
  printf("argv[%d]=%s\n",i,argv[i] );
  }

  // printf("(%s)\n",argv[] );
  return 0;
}
