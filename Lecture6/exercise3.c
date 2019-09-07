#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  int qstark = 111;
  int iheap = 222;

  pid_t example;
  example = fork(); 
  switch(example)
  {

  case -1:
    printf("Not duplicate,failed\n");
  break;

  case 0:
    qstark*=3;
    iheap*=3;
  break;

  default:
    printf("Parent executing \n");
  break;
}
  printf("pid= %ld %s,qstack= %d,iheap= %d\n",
  (long)getpid(),(example==0)?"Child":"Parent",qstark,iheap);

  return 0;
}
