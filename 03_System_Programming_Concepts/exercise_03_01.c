#include <linux/reboot.h> /*we include this library for this->LINUX_REBOOT_MAGIC1 flag*/
#include <unistd.h>
#include<stdio.h>
int main(int argc,char **argv)
{
    printf("LINUX_REBOOT_MAGIC1:%x\n",LINUX_REBOOT_MAGIC1);
    printf("LINUX_REBOOT_MAGIC2:%x\n",LINUX_REBOOT_MAGIC2);
    printf("LINUX_REBOOT_MAGIC2A:%x\n",LINUX_REBOOT_MAGIC2A);
    printf("LINUX_REBOOT_MAGIC2B:%x\n",LINUX_REBOOT_MAGIC2B);
    printf("LINUX_REBOOT_MAGIC2C:%x\n",LINUX_REBOOT_MAGIC2C);
    /*
    OUTPUT:
    LINUX_REBOOT_MAGIC1:fee1dead
    LINUX_REBOOT_MAGIC2:28121969
    LINUX_REBOOT_MAGIC2A:5121996
    LINUX_REBOOT_MAGIC2B:16041998
    LINUX_REBOOT_MAGIC2C:20112000

    The meaning of these numbers is more prosaic.
    When represented in hexadecimal numeral system, they equal 28121969, 05121996, 16041998 and 20112000 respectively;
    the first of which is the date of birth of Linus Torvalds himself, 
    and the latter three are the dates of birth of his daughters Patricia, Daniela and Celeste respectively. 
    
    */
    return 0;
}