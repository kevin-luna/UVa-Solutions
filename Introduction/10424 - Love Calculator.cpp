#include <iostream>
#include <iomanip>

using namespace std;

float calcLove(string name){
    int sum=0;
    for(int c=0;c<name.length();c++){
        if(isalpha(name.at(c))){
            sum+=tolower(name.at(c))-96;
        }
    }

    int p1;
    while (to_string(sum).length()>1)
    {
        p1=0;
        for(int c=0;c<to_string(sum).length();c++){
            p1+=to_string(sum).at(c)-48;
        }
        sum=p1;
    }
    
    return (float)sum;
}


int main()
{
    string name1,name2;
    float ratio;
    while(getline(cin,name1)){
        getline(cin,name2);
        ratio = (calcLove(name1)>calcLove(name2)) ? (calcLove(name2)/calcLove(name1))*100 : (calcLove(name1)/calcLove(name2))*100;
        cout<<fixed<<setprecision(2)<<ratio<<" %"<<endl;
    }
    return 0;
}
