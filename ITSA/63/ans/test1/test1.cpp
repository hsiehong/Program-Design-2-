#include<iostream>

using namespace std;

int main(void){
    int ncase,n,total;
    cin>>ncase;
    while(ncase--){
        cin>>n;total=0;
        for(int i=1;i<=n;i++)total+=i;
        cout<<total<<endl;
    }
    return 0;
}
