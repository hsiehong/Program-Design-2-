#include<bits/stdc++.h>
using namespace std;


void sol(){
    const int N=500000;
    bool ok[N]={false};
    int weight,tested,weightNO,testedNO;
    cin>>weightNO>>testedNO;
    for(int wi=0;wi<weightNO;wi++){
        cin>>weight;
        for(int ci=N;ci>0;ci--){
            if(ok[ci])ok[ci+weight]=true;
        }
        ok[weight]=true;
    }
    int ans=0;
    for(int ti=0;ti<testedNO;ti++){
        cin>>tested;
        if(ok[tested])ans++;
    }
    cout<<ans<<endl;
}
int main(void){
    int ncase;
    cin>>ncase;
    while(ncase--){
        sol();
    }
    return 0;
}
