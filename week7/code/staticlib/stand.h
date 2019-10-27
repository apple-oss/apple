#include <assert.h>
#include <sys/types.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/stat.h>

void Menu_1();
void Creatfile_1(FILE *fp);
void Readfile_1(FILE *fp);
void Alterfileauthority_1(FILE *fp);
void Viewfileauthority_1();
