#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>


#include <assert.h>
#define true 1
#define false 0
#define  bool unsigned int
bool CreateFileWithHole(const char *filename);
bool Copy(const char *src,const char *dest);
int main()
{
    CreateFileWithHole("srcFileWithHole.txt");
    Copy("./srcFileWithHole.txt","./destFileWithHole.txt");
    return 0;
}
bool CreateFileWithHole(const char *filename)
{
    char buf[400];
    int fd = open(filename, O_WRONLY|O_TRUNC|O_CREAT, 0777);
    memset(buf, 'a', 400);
    write(fd, buf, 400);
    lseek(fd, 1200, SEEK_CUR); // Make a hole
    write(fd, buf, 400);
    lseek(fd, 1200, SEEK_CUR); // Make a hole
    write(fd, buf, 400);
    close(fd);
    return true;
}
bool Copy(const char *src,const char *dest)
{
    int fdSrc,fdDest,readByte,holeSize=0;
    char buffer[1024]={'\0'};
    fdSrc=open(src,O_RDONLY);
    if(fdSrc<0)
    {
        printf("ERROR:Unable to open source file %s\n",strerror(errno));
        return false;
    }    
    fdDest=open(dest,O_CREAT | O_WRONLY  | O_TRUNC);
    if(fdDest<0)
    {
        printf("ERROR:Unable to open source file %s\n",strerror(errno));
        return false;
    }

    while((readByte=read(fdSrc,buffer,1024))>0)
    {
        for(int icnt=0;icnt<readByte;icnt++)
        {
            
            if(buffer[icnt]=='\0')
                holeSize++;
            else if(holeSize>0)
            {
                lseek(fdDest,holeSize,SEEK_CUR);
                write(fdDest, &buffer[icnt], 1);
                holeSize=0;
            }
            else
            write(fdDest,&buffer[icnt],1);

        }
    }
    close(fdDest);
    close(fdSrc);
    return true;
}