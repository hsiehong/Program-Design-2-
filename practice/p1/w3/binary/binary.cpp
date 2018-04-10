#include<iostream>
#include<cstring>
#include<cstdio>
#define N 30

using namespace std;

int tran(char line[N]){
    int xi=1,k=0;
    for(int i=strlen(line)-1;i>=0;i--){
        if(line[i]=='1'){
            k+=xi;
        }
        xi*=2;
    }
    return k;
}

int main(){
    int ncase,ans,l;
    char line[N];
    while(1){
        cin>>ncase;
        if(ncase==0)break;
        ans=0;
        while(ncase--){
            scanf("%s",line);
            ans+=tran(line);
        }
        cout<<ans<<endl;
    }
    return 0;
}
