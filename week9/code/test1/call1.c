#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
   char *argv[2];
   argv[0]="/home/rlk/2/week8/code/test";
   argv[1]=NULL;
   printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
   execv("/home/rlk/2/week8/code/test",argv);
   printf("after calling");

}
