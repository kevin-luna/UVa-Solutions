#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    string answers; 
    int score,linescore;
    for (size_t i = 0; i < t; i++)
    {   
        score=0;
        linescore=0;
        cin>>answers;
        for (size_t j = 0; j < answers.length(); j++)
        {
            if(answers[j]=='O'){
                ++score;
                linescore+=score;
            }else{
                score=0;
            }
        }
        cout<<linescore<<endl;

    }
    
    return 0;
}
