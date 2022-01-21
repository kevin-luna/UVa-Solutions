#include <stdio.h>

int main(){
    long long hashmat,opponent;
    long long diff;
    
    while (scanf("%lld %lld",&hashmat,&opponent)!=EOF)
    {
        diff=opponent-hashmat;
        printf("%lld\n",(diff<0)?diff*(-1):diff);
    }
    
    return 0;
}