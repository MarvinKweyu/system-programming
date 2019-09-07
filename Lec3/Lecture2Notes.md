### `lseek()`

For each open file,the kernel records a file offset,sometimes called the read-write offset
or pointer.
This is the location in the file at which the next read or write will commence.
The file offset is expressed as an ordinal byte position relative to the start of the file.
The first byte of the file is at offset zero
The file offset is set to point to the start of the file when the file is opened and is automatically adjusted by each
subsequent call to read /write so that it points to the next byte of the file after the bytes just read
or written.

Thus,successive read() and write() calls progress sequentially via the file.
#### Syntax as below:
```
offset-t lseek(int fd,off_t offset, int whence);

```
the offset argument specifies a value in bytes.
the whence argument indicates the best point from which offset is to be interpreted,
and is one of the below values:
SEEK_SET
The file offset is set offset bytes from the beginning of the file
SEEK_CUR
The file offset is adjusted by offset bytes relative to the current file offset
SEEK_END
The file offset is set to the size of the file plus offset.
In other words,offset is interpreted with respect to the next byte after the last byte of the file

@marvinus
