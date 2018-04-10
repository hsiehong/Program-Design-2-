#include<iostream>

using namespace std;

int sol(int t){
    int arr[10];
    for(int j=0;j<10;j++)arr[j]=0;
    while(t){
        arr[t%10]++;
        t/=10;
    }
    for(int j=0;j<10;j++){
        if(arr[j]>1)return 1;
    }
    return 0;
}

int main(void){
    int ncase,x,t;
    cin>>ncase;
    while(ncase--){
        cin>>x;
        int ok=0;
        for(int i=x;i>0;i--){
            t=i;
            if(sol(t))continue;
            else ok++;
        }
        cout<<ok<<endl;
    }
    return 0;
}
