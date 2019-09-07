//showing working of the handler
#include <signal.h>
#include <stdio.h>
// #include <sys/stat.h>
#include <unistd.h>

static void SigHandler(int sig)
{
  printf("The signal has been typed");
}

int main(int argc, char *argv[]) {

  if (signal(SIGINT,SigHandler)==SIG_ERR)
  printf("Error when executing handler " );
  for (int i=0;;i++)
  {
    printf("%d\n",i);
    sleep(3);
  }
  return 0;
}
