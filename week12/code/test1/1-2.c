#include "my.h"
int main()
{ 
    pid_t r;
    int r_num;
    int pipefd[2];
    char buf1[4097];
    memset(buf1,0,sizeof(buf1));
    if(pipe(pipefd))
      {
           perror("pipe failed!");
           return -1;
       }
    r=fork();
    if(r<0)
      {
           perror("pipe failed!");
           return -1;
      }
    else if(r==0)
      {
           sleep(5);
           close(pipefd[1]);
           if(r_num=read(pipefd[0],buf1,4097)>0)
               printf("child read from pipe: %s,total=%d\n",buf1,r_num);
           close(pipefd[0]);
           exit(0);
      }
    else
      {
           close(pipefd[0]);
           for(int i=0;i<4096;i++)
              {
                 buf1[i]="s";
                 write(pipefd[1],"s",1);
              }
           printf("parent write ok.\n");
           close(pipefd[1]);
           exit(0);
      }
}

