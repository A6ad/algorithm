#include <stdio.h>
#include<string.h>
int main() {
    char ch[10];
    scanf("%[^\n]s",ch);
    printf("%s",ch);
    return 0;
}