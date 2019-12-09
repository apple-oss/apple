#include "my.h"
#define NUM_THREADS 4
void hello(void * t)
{
     int sum=0;
     pthread_t my_tid;
     my_tid=pthread_self();
     for(int i=1;i<=100;i++)
       {
          sum+=i;
       }
     printf("\tThread %d: my tid is %lx,result = %d\n",t,my_tid,sum);
}

int main()
{
     pthread_t tid;
     int rv,t;
     for(t=0;t<NUM_THREADS;t++)
        {
             rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)t);
             if(rv!=0)
              {
                printf("thread create failed!\n");
                return -1;
              }
             printf("Create thread %lx\n",tid);            
        }     
     pthread_join(tid,NULL);
     printf("Good By\n");
}
