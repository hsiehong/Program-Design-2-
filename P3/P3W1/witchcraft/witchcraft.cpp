#include<iostream>
#define N 100

using namespace std;

int main(void){
    int ncase,D,a,b,c,A,B,C;
    bool flag;
    cin>>ncase;
    while(ncase--){
        cin>>D>>a>>b>>c>>A>>B>>C;
        flag=false;
        for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)for(int k=0;k<=c;k++){
            if(D==0){
                flag=true;
                break;
            }
            if(A*i+B*j+C*k==D){
                flag=true;
                break;
            }
        }
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
