#include "stand.h"

int main()
{
     char choice;
     FILE *fp;
     while(1){
     Menu_1();
     choice = getchar();
     switch(choice){
      case '0' : 
         printf("退出系统\n");
         exit(0);
        break;
      case '1' : 
         Creatfile_1(fp);
        break;
      case '2' : 
         Writefile_1(fp);
        break;
      case '3' : 
         Readfile_1(fp);
        break;
      case '4' : 
         Alterfileauthority_1(fp);
        break;
      case '5' : 
         Viewfileauthority_1();
        break;
      default:
         printf("你的输入有误，退出系统！\n");
         exit(0);
        break; 
     }
   }
     

}

