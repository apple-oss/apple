#include "my.h"
#include <string.h>
static void men_leak1(void)
{
    char *p=malloc(1);
}
static void men_leak2(void)
{
    FILE *fp=fopen("test.txt","w");
}
static void men_overrun1(void)
{
    char *p=malloc(1);
    *(short *)p=2;
    free(p);
}
static void men_overrun2(void)
{
    char array[5];
    strcpy(array,"hello");
}
static void men_double_free(void)
{
    char *p=malloc(1);
    free(p);
    free(p);
}
static void men_free_wild_pointer(void)
{
    char *p;
    free(p);
}
int main()
{
    men_leak1();
    men_leak2();
    men_overrun1();
    men_overrun2();
    men_double_free();
    men_free_wild_pointer();
    return 0;
}

