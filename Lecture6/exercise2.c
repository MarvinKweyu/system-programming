//showing working of the handler
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void SigHandler(int sig)
{
  printf("The signal has been typed");
  for(int j=1;j<6;j++)
  {
    printf("\n%d\t%d\n",j,j*j);
  }
}

int main(int argc, char *argv[]) {
  //when the error is met,run the SigHandler
  if (signal(SIGINT,SigHandler)==SIG_ERR) //SIGINT is ctrl+C.The SIG_ERR is equivalent to the -1 part in (open(path)==-1)
  //syntax is signal(TypeofSignal,SignalHandler)
  printf("Error when executing handler " );
  for (int i=0;;i++)
  {
    printf("%d\n",i);
    sleep(3);
  }
  return 0;
}
