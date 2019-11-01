本周中先是了解了子进程和父进程之间的关系。然后编写了一个项目
熟悉了标准I/O的输入输出函数，在fun.c中Creatfile_1函数中使
用fopen（）函数打开文件（如果不存在此文件则创建），然后在
Writefile_1函数中使用fwrite（）函数向文件写入内容；在
Readfile_1函数中使用fread（）函数读出文件输入，在
Alterfileauthority_1函数中使用chmod（）函数修改文
件权限，在Viewfileauthority_1函数中使用execv即相当于
在命令行使用命令ls -l 文件名字来查看文件权限。
