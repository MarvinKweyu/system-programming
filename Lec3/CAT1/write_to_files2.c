#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    char str[100];
    int filedesc = open("testfile.txt", O_CREAT|O_WRONLY | O_APPEND);
    // printf("Enter content for your file: ");
    // scanf("%s",str);

    if (filedesc < 0) //meaning file is not present i.e should be created
    {
        return -1;
    }

    if (write(filedesc, "This will be output to testfile.txt\n", 36) != 36)
    //nota in py len('This will be output to testfile.txt') = 35
    // if (write(filedesc,"%s",36,str) !=36)
     {
        write(2, "There was an error writing to testfile.txt\n", 43);
        return -1;
    }

    return 0;
}
