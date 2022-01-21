#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    int max;
    string URL;
    int relevance;
    for (size_t i = 1; i <= t; i++)
    {
        queue<string> possible;
        max=0;
        for (size_t j = 1; j <=10; j++)
        {
            cin>>URL;
            cin>>relevance;
            if(relevance>max){
                //si encuentra un nuevo máximo, vacía la cola
                possible = queue<string>();
                possible.push(URL);
                max = relevance;
            }

            else if(!possible.empty()){
                if(relevance==max){
                    possible.push(URL);
                }
            }
        }
        
        cout<<"Case #"<<i<<":"<<endl;
        while (!possible.empty())
        {
            cout<<possible.front()<<endl;
            possible.pop();
        }
        
    }
    
    return 0;
}
