#include <stdio.h>

void getstr( char *text ) { 
    printf("Enter the text : ");
    gets(text);
}

int main(){
    char str[20];
    getstr(str);
    printf("text is : %s", str);
    return 0;
}
