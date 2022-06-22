#include <bits/stdc++.h>

using namespace std;

struct Event{
    int km;
    string evt;
    int fc;
};

Event evtList[50];

bool journey(double L,int lastIndex){
    double fuelCons=fuelCons=evtList[0].fc,leaks=0,d=0,tank=L,gasto=0;
    for(size_t i=1;i<=lastIndex;i++){
        d=evtList[i].km-evtList[i-1].km;
        gasto=d*(fuelCons/100.0)+d*leaks;
        if(tank<gasto)return false;
        tank-= gasto;
        if(evtList[i].evt=="Fuel")fuelCons=evtList[i].fc;
        else if(evtList[i].evt=="Leak")leaks++;
        else if(evtList[i].evt=="Mechanic") leaks=0;
        else if(evtList[i].evt=="Gas")tank=L;
    }
    return true;
}

int main(){
    
    int km,fc;
    string evt,garbage;
    evt.reserve(10);
    garbage.reserve(12);
    int t = 1;
    while((cin>>km>>evt>>garbage>>fc) && fc!=0){
        evtList[0]={km,evt,fc};
        int i=1;
        do{
            fc=-1;
            cin>>km>>evt;
            if(evt=="Fuel"){
                cin>>garbage>>fc;
            }else if(evt=="Gas"){
                cin>>garbage;
            }
            evtList[i++]={km,evt,fc};
        }while(evt!="Goal");
    
        double left=0.0,right=pow(2,32-1),mid=0;
        bool result;
        while(right-left>=0.0001){
            mid = (left+right)/2.0;
            result=journey(mid,i-1);
            if(result){
                right=mid;
            }else{
                left=mid;
            }
        }
        printf("%0.3f\n",mid);
    }
}