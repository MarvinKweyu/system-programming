## 1.Maximum virtual address space

Size of a program address is determined by Maximum size of virtual address space.
Number of bits in a virtual address is the log to base 2 of this value.

## 2. Maximum physical address spaces
Amount of free memory the system can support determines the number of bits needed to address the physical memory.
The size of physical address is log to base 2 of this value.
Hence 16MB = 16 000 000 bytes = 4000 bytes of physical memory
Maximum physical space of 8MB,space of address needed

## 3. Size of a page
The size of virtual memory page and a physical memory frame.
It is a power of 2.

`Exercise`

Suppose our pages are 4096bytes long and our machine uses 32 bit addresses.How many pages will we fit in that machine.

bytes = (2**32) //since machine is 32 bit
bytes/4096

A virtual memory address is composed of two parts,that is, page number and an offset into the page.
The page number determines which page contains the information while the offset specifies which byte within the page.
Illustrated as: page number|offset

`Example:`
for a 64 bit machine,following same example of 4096,
the offset will be 2**52 and offset will be 2**12

can be calculated as :
bytes = 2**64
bytes/4096

In order to support this organization i.e virtual memory diagram,the kernel contains a page table for each process.
The page table describes the location of each page in the process virtual address space(the set of all virtual memory
pages available to the process)
Each entry in the page table either indicates the location of a virtual page in RAM or indicates it currently resides on disk.
Not all address ranges in the process virtual address space require page table entries.
Typically,large ranges of the potential virtual address space are unused so that it is not necessary
to maintain Corresponding page table entry.
If a process tries to access an address for which there are no corresponding page table entry,it receives SIGSEGV (a type of signal)

A process range of valid virtual addresses can change over its lifetime as the kernel allocates and de-allocates pages for the process.
This can happen in the following cases:
a).As the stack grows downwards beyond limits previously reached.
b) When memory is allocated or de-allocated on the heap by raising the program break using brk() or sbrk()

#### Reasons for separating physical from virtual MEMORY
Virtual memory management separates the virtual address space of a process from physical address space of RAM.
This provides many advantages:

i) Processes are isolated from each other and the kernel hence one process can't read or modify memory of another process or kernel.
ii)


## COMMAND LINE ARGUMENTS(argc(argument count),argv(command line vector))

Every C program has a function main() which is the point where execution of the program starts.
when executed,the command line arguments(the separate words passed by the shell) are made available via two arguments to function
main.
The first argument ,int argc,indicates how many command line arguments there are.
The second argument char*argv[]
Nota:
`int k; implies a normal variable
int *p ; is a pointer variable i.e stores address of another variable`

k = &p

`The second argument (char *argv[] )` is an array of pointers to the command line arguments each of which is a non-terminated
character string.
The first of these strings,argv[0] is conventionally the name of the program itself.
The list of pointers in argv[] is terminated by a null pointer
```
@marvinus
```
