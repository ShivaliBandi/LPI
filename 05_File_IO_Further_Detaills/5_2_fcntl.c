/*
The fcntl() system call performs a range of control operations on an open file
descriptor.
int fcntl(int fd, int cmd, ...);
Return on success depends on cmd, or –1 on error
*/
#include<fcntl.h>//header file
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include <unistd.h>

int main()
{
    int fd,flags,accessMode;
    fd=open("demo.txt",O_RDONLY);
    if(fd<0)
    {
        printf("ERROR:Unable to open file->%s\n",strerror(errno));
        exit(-1);
    }
    flags=fcntl(fd,F_GETFL);//F_GETFL flag is to retrieve or modify the access mode and open file status flags of an open file
    if (flags == -1)
        exit(-1);
    if(flags& O_SYNC)
        printf("Write are synchronous\n");
    /*
    the O_RDONLY (0),O_WRONLY (1), and O_RDWR (2) constants don’t correspond to single bits in the open file
    status flags. Therefore, to make this check, we mask the 
    flags value with the constant O_ACCMODE, and then test for equality with one of the constants.
    as O_ACCMODE is 3 so we can work on bits with the help of these can perform operations on bits to find in which 
    we have opened our file
    
    */
    accessMode=flags &O_ACCMODE;
    if(accessMode==O_RDONLY)
    printf("File is opened in read only mode\n");
    
    /*
    With the help of F_SETFL flag we can modify some  of the flags.
    The Flags that can be modified are O_APPEND, O_NONBLOCK, O_NOATIME, O_ASYNC, and
    O_DIRECT. Attempts to modify other flags are ignored. 
    (Some other UNIX implementations allow fcntl() to modify other flags, such as O_SYNC.)
    To modify the open file status flags, we use fcntl() to retrieve a copy of the existing
    flags, then modify the bits we wish to change, and finally make a further call to fcntl()
    to update the flags. Thus, to enable the O_APPEND flag, we would write the following
    */
    flags|=O_APPEND;
    if(fcntl(fd,F_SETFL,flags)==-1)
        printf("ERROR:Unable to update flags\n");
   printf("%d\n", flags &O_APPEND);
    fd=close(fd);
    return 0;

}