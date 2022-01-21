#include <stdio.h>

int main(void){
    int t;
    scanf("%d",&t);
    int n,k,p;
    int resultado;
    size_t i;
    for ( i = 0; i < t; i++)
    {
        scanf("%d %d %d",&n,&k,&p);
        if(p%n==0){
            resultado=k;
        }else{
            if (k+(p%n)<=n){   
                resultado=k+(p%n);
            }else{
                resultado = (k+(p%n))-n;
            }
        }
        printf("Case %zu: %d\n",i+1,resultado);
    }
    return 0;
}