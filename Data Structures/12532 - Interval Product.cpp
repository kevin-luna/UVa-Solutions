#include <iostream>
#include <vector>

using namespace std;

class BIT{
    private:
        vector<int> fenwickTree;

    public:

        BIT(int n){
            this->fenwickTree.assign(n+1,0);
        }

        int getSum(int index)
        {
            int sum = 0; 
            while (index>0)
            {
                sum += this->fenwickTree[index];
                index -= index & (-index);
            }
            return sum;
        }

        int getSum(int a,int b){
            return getSum(b)-getSum(a==1 ? 0:a-1);
        }

        void updateElement(int index, int val)
        {
            while (index < this->fenwickTree.size())
            {
                this->fenwickTree[index] += val;
                index += index & (-index);
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    while (cin>>n>>k)
    {
        vector<int> elements(100005);
        BIT negatives(n),zeros(n);
        for (int i = 1; i <= n; i++)
        {
            cin>>elements[i];
            if(elements[i]==0){
                zeros.updateElement(i,1);
            }else if(elements[i]<0){
                negatives.updateElement(i,1);
            }
        }

        char command;
        int v1,v2;
        for (int q = 0; q < k; q++)
        {
            cin>>command>>v1>>v2;
            if(command=='C'){
                if(elements[v1]>=0 && v2<0) negatives.updateElement(v1,1);
                else if(elements[v1]<0 && v2>=0) negatives.updateElement(v1,1);

                if(elements[v1]!=0 && v2==0) zeros.updateElement(v1,1);
                else if(elements[v1]==0 && v2!=0) zeros.updateElement(v1,-1);

                elements[v1]=v2;
            }
            else if(command=='P'){
                if(zeros.getSum(v1,v2)){
                    cout<<"0";
                }else if(negatives.getSum(v1,v2)%2){
                    cout<<"-";
                }else cout<<"+";
            }
        }
        cout<<"\n";
    }
}