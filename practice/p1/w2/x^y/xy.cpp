#include<iostream>
#include<fstream>
using namespace std;
typedef unsigned long long LL;

int main(void){
    int ncase,p;
    LL x,y,ans;
    cin>>ncase;
    while(ncase--){
        cin>>x>>y>>p;
        ans=1;
        while(y>0){
            if(y&1){
                ans=(ans*x)%p;
            }
            y>>=1;
            x=(x*x)%p;
        }
        cout<<(int)ans<<endl;
    }
    return 0;
}
