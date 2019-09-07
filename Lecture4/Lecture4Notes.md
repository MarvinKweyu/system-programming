# PROCESSES
A process is an instance of an executing program.
A program is a file containing a range of information describing how to construct a process at run-time

This information Includes:

#### 1.Binary format identification
Each program file includes meta-information describing format of executable file.
This enables the kernel to interpret the remaining information in the file.
In Unix,the executable file is in the format a.out

#### 2.Machine language instruction
this encodes the algorithm of the program

#### 3.Program entry point address
This identifies the location of the instruction at which execution should start.

#### 4.Data
The program file contains values used to initialize variables and literal constants used by the program.

#### 5.Symbol and relocation symbols
These describe the location and names of functions and variables within the program.
These tables are used for a variety of purposes including debugging and run-time Symbol resolution(dynamic linking)
Note on dynamic and static.

#### 6.Shared library and dynamic linking information
The program file includes field listings,the shared libraries the program needs to use at runtime and pathname of dynamic linker
it should use to load these libraries.

#### 7.Other information
the program file has various other information describing how to construct a process.

## PROCESS ID AND PARENT PROCESS ID
open(pathname,flags,modes)

Obtaining process id sample

`#include<unistd.h>
Pid_t getPid(void)//note that it returns a Pid_t return data type
`

The Pid_t data type used for the return type of the above function is an integer type specified by the Unix system for the purpose of
storing process ids.
The linux kernel limits ids to being less than/equal to 32,767
When a new process is created,it is assigned the next sequentially available process id.
Each time the limit of 32,767 is reached,the kernel resets the process id counter so that the process id are assigned starting from
the low integer value.
Each process has a parent i.e the process that created it.
A process can find the process id of its parent using:getppid() system call.

Syntax is as below:
```
#include<unistd.h>
 Pid_t getppid()

```
In effect,the process id attribute of each process represents a tree like relationship of all processes in the system.
The parent of each process has its own parent and so on till process 1 i.e init(the ancestor of all processes)
- If a child process becomes orphaned,the child is adopted by init process and subsequent calls to getppid() in the child return 1

## MEMORY LAYOUT OF A PROCESS
The memory allocated to each process is composed of a number of parts named segments.

#### 1.Text segment
Contains machine language instruction of the program run by the process.
Has converted machine instruction of  the program
Nota:Compiling converts to machine language.
The text segment is made read only so that a process doesn't accidentally modify it's own instruction by a bad pointer value.
Since many process may be running the same program,the text segment is shareable so that a single copy of the program code
can be mapped to virtual address space of all processes.

#### 2.Initialized data segments
Has global and static variables `explicitly Initialized.`
Values of these variables are read from executable file when the program is loaded to memory.

Global variable:variable visible throughout the  program.
Static variable:Any variable inside the main function.

Explicit initialization is as below:
int y = 5;
In case of declaration outside the main,explicitly state static variable_name.

#### 3.Uninitialized data segment.
Contains global and static variables `not explicitly Initialized`.
For instance:
int y;
int x;

implicit initialization involves the y = z in Exercise1.c

Before starting the program,the system initializes all memory in this segment to zero.
The main reason for placing global and static variables that are Initialized into a separate segment from those that are uninitialized
is that when a program is stored on disk,it is not necessary to allocate space for uninitialized data.
Instead the executable records the location and size needed for the uninitialized data segment.This space is allocated by program
loader at runtime.

#### 4. Stack
The stack is a dynamically growing and shrinking segment stack frames.
One stack frame is allocated for each currently called function.
A frame stores the functions local variables,arguments and return values.

#### 5.Heap
An area from which memory can be dynamically allocated at runtime.
The top end of the heap is called the program break.

Example:
```
#include <stdio.h>

// global variable..keeps memory sector locked
int  x;    //Uninitialized data segment
int y = 5; //initialized data segment

void setNumbers(int k,int z) {   //k and z are stack

  x = k //text segment
  y = z
  int getNumber1()
  {
    return z; //stack
  }
  int getNumber2()
  {
    return y;//stack
  }
}

```

# VIRTUAL MEMORY MANAGEMENT
Like most modern kernels,linux employs virtual memory management to make efficient use of  both processor and RAM,
via exploiting a property typical of most program locality of reference.
Most programs demonstrate two kinds of locality:

#### 1. Spartial Locality
The tendency of a program to reference memory addresses near those that were recently accessed.(Because
of sequential processing of instructions and sequential processing of data structures)
Example of sequential is array int x[]={1,2,3,4,5}

#### 2.Temporal locality
Tendency of a program to access same memory addresses in the near future that it accessed in the recent past.
demonstrated in a loop within a loop
0 0
0 1
0 2
1 0
1 2

The upshot of locality of reference is that it is possible to execute a program while maintaining only part of it's address space in RAM.
A virtual memory scheme splits memory used by each program to small fixed size units called pages.
Correspondingly,RAM is divided to a series of page frames of the same size.
At any one time,only some of the pages of a program need to be resident in a physical memory page frame.

**Nota** : Creating virtual memory,where it is ....

The pages form the resident set.
Copies of the unused pages of the program are maintained in the swap area(a reserved area of the disk space to
supplement the RAM and loaded to physical memory only as needed)
When a process references a page currently not resident in the physical memory,a page fault occurs at which point
the kernel suspends execution of the process while the page is loaded from disk to memory.

```
@marvinus
```
