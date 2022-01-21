#include <stdio.h>
#include <math.h>

int main()
{
    int casos;
    float largo,ancho;
    float radares;
    scanf("%d",&casos);
    size_t i;
    for (i = 0; i < casos; i++)
    {
        scanf("%f %f",&largo,&ancho);
        radares = ceil((largo-2)/3)*ceil((ancho-2)/3);
        printf("%d\n",(int)radares);
    }
 
    return 0;
}
