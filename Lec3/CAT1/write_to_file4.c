#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int filedesc = open("testfile.txt", O_CREAT|O_WRONLY | O_APPEND);

    if (filedesc < 0) //meaning file is not present i.e should be created
    {
        return -1;
    }

    write(filedesc,argv[1],100);


  return 0;
}
