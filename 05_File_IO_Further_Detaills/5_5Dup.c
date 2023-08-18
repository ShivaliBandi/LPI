/*
The dup() call takes oldfd, an open file descriptor, and returns a new descriptor that
refers to the same open file description. The new descriptor is guaranteed to be the
lowest unused file descriptor.
Returns (new) file descriptor on success, or –1 on error
*/
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include <unistd.h>

int main()
{
    int oldfd,newfd;
    oldfd=open("demo.txt",O_RDONLY);
    if(oldfd<0)
    {
        printf("ERROR:Unable to open file->%s\n",strerror(errno));
        exit(-1);
    }
    //for dup(oldfd)
    newfd=dup(oldfd);
     if(newfd==-1)
        printf("ERROR:dup system call failed\n %s\n",strerror(errno));
    //for dup2(oldfd,newfd)
    /*
    The dup2() system call makes a duplicate of the file descriptor given in oldfd using
    the descriptor number supplied in newfd. If the file descriptor specified in newfd is
    already open, dup2() closes it first. (Any error that occurs during this close is
    silently ignored; safer programming practice is to explicitly close() newfd if it is open
    before the call to dup2().)
    */
    
    oldfd=close(oldfd);
    newfd=close(newfd);
    return 0;

}