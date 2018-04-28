#include<bits/stdc++.h>
#include<iostream>
#define N 20

using namespace std;

int trans(char line[N],int l){
    cout<<line<<endl;
    int i,xi=1,k=0;
    for(i=l-1;i>=0;i--){
        if(line[i]=='1'){
            k+=xi;
        }
        xi*=2;
    }
    return k;
}
main(){
    int ncase,ans,k,l;
    char line[N];
    while(cin>>ncase){
        if(ncase==0)break;
        ans=0;
        while(ncase>0){
            cout<<"ncase:"<<ncase<<endl;
            //for(int a=0;a<N;a++)line[a]='0';
            fgets(line,N,stdin);
            cout<<line<<endl;
            //l=strlen(line)-1;
            //k=trans(line,l);
            //ans+=k;
            ncase--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
