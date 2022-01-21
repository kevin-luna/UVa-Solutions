#include <stdio.h>
#include <math.h>

int main()
{
    int cases;
    scanf("%d",&cases);
    size_t i;
    for (i = 0; i < cases; i++)
    {   
    long long n=0,rows;
        scanf("%lld",&n);
        rows = (long long)floor((-1)+sqrt(1+(8*n)))/2;
        printf("%lld\n",rows);
    }
    
    return 0;
}