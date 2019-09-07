// program opens file for writing and creates if abscent
//it prints the process number of the file being opened

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h> //enables use of system calls

int main(int argc, char const *argv[]) {
  int fd;
  // create file if non-existent
  // O_RDONLY means read file if present
  // S_IWUSR means give write permissions to owner
  fd = open("text5.txt",O_RDONLY|O_CREAT,S_IWUSR); //file,mode,permissions
  if (fd==-1)//would mean file is abscent hence created
    printf("%d",(fd*40));
    // printf("%d",fd );
  else
    printf("%d",(fd*90));
  return 0;
}

// printf("%s\n", );
