#include <iostream>

using namespace std;

int f(long int n){
    string numero;
    numero=to_string(n);
    int suma;
    while (n>=10)
    {
        suma=0;
        for (size_t i = 0; i < numero.length(); i++)
        {
            suma+=numero[i]-48;
        }
        numero=to_string(suma);
        n=suma;
    }
    return n;
}


int main()
{
    long int n;
    while (scanf("%ld",&n) && n!=0)
    {
        cout<<f(n)<<endl;
    }
    
    return 0;
}
