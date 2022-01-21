#include <stdio.h>

int main(void)
{
    char stream[100];
    while (fgets(stream,99,stdin))
    {
       printf("%s",stream);
    }
    
    return 0;
}
