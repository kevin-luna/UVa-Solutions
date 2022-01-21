#include <stdio.h>
#include <string.h>

int main(void){
    int t;
    scanf("%d",&t);
    char cadena[11];
    int n=0;
    size_t i;
    for ( i = 0; i < t; i++)
    {
        scanf("%d",&n);
        n=(((((n*567)/9)+7492)*235)/47)-498;
        sprintf(cadena,"%d",n);
        printf("%c\n",cadena[strlen(cadena)-2]);
    }
    return 0;
}