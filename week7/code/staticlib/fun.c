#include "stand.h"

void Menu_1()
{
      printf("********************************\n");
      printf("0. 退出\n");
      printf("1. 创建新文件\n");
      printf("2. 写文件\n");
      printf("3. 读文件\n");
      printf("4. 修改文件权限\n");
      printf("5. 查看当前文件的权限\n");
      printf("********************************\n");
      printf("Please input your choice(0-5):");
}
void Creatfile_1(FILE *fp)
{
  char bufname[10] ;
  printf("请输入你创建的文件名:");
  getchar();
  fgets(bufname, 10, stdin);
  strtok(bufname,"\n");
  if ((fp=fopen(bufname, "w+")) == NULL) {
    printf("open error");
      exit(1);
  }
  else
  printf("%s file has creat\n",bufname);
  fclose(fp);
  
}
void Writefile_1(FILE *fp)
{
     char buf[1024];
     char bufname[10] ;
     printf("请输入你要打开的文件:");
     getchar();
     fgets(bufname, 10, stdin);
     strtok(bufname,"\n");
     if((fp = fopen(bufname,"a"))==NULL){
        printf("open error");
        exit(1);
      }
      else{
         printf("Open file:%s\n",bufname);
      }
      printf("请输入你的内容（不能超过1024个字节）:\n");
      getchar();
      fgets(buf, 1024, stdin);
      strtok(buf,"\n");
      fwrite(buf,strlen(buf),1,fp);
      fclose(fp);
}
void Readfile_1(FILE *fp)
{
     char *buf;
     char bufname[10] ;
     printf("请输入你要打开的文件:");
     getchar();
     fgets(bufname, 10, stdin);
     strtok(bufname,"\n");
     if((fp = fopen(bufname,"a")) == NULL){
        perror("open");
      }
      else{
         printf("Open file:%s\n",bufname);
      }  
      fread(buf,1,1024,fp);
      printf("文件内容：");
      puts(buf);
      fclose(fp);
      
}
void Alterfileauthority_1(FILE *fp)
{
        int n;
        char bufname[10] ;
        printf("请输入你要修改的文件:");
        getchar();
        fgets(bufname, 10, stdin);
        strtok(bufname,"\n");
        if((fp = fopen(bufname,"r+")) == NULL){
        perror("open");
        }
        printf("0.读，写，执行 1.读 2.写 3.执行\n"); 
        printf("请选择修改的权限:"); 
        scanf("%d",&n);
        getchar();
        switch(n){
           case 0: chmod(bufname,S_IRWXU); break;
           case 1: chmod(bufname,S_IRUSR); break;
           case 2: chmod(bufname,S_IWUSR); break;
           case 3: chmod(bufname,S_IXUSR); break;
           default: printf("你的选择有误请!\n");
        }          
}
void Viewfileauthority_1(FILE *fp)
{
        char bufname[10] ;
        printf("请输入你要查看的文件:");
        getchar();
        fgets(bufname, 10, stdin);
        strtok(bufname,"\n");
        if((fp = fopen(bufname,"r+")) == NULL){
        perror("open");
        }
        char *path = "/bin/ls";
        char *argv[4] = {"ls","-l",bufname,NULL};
        execv(path,argv);
}
