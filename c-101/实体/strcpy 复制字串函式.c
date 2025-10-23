#include <stdio.h>
#include <string.h>

int main () {
    // char * strcpy (char * 目标, const char * 源);
    char src[] = "kaofish"; // 将隐性转型成 (const char *)
    char dest[8]; // 将隐性转型成 (char *)
    strcpy(dest, src);
    printf("%s\n", dest);
    return 0;
}