#include<bits/stdc++.h>
#define N 10000

using namespace std;

bool cmpr(int e1,int e2){
    return e1<e2;
}

main(){
    int n,e[N],s[N],i,j,win;
    while(cin>>n){
        if(n==0)break;
        for(int i=0;i<n;i++)cin>>e[i];
        for(int i=0;i<n;i++)cin>>s[i];

        sort(e,e+n,cmpr);
        sort(s,s+n,cmpr);
        i=j=win=0;
        while(i<n){
            while((s[i]<=e[j])&&(i<n))i++;
            if(i==n)break;
            win++;
            i++;
            j++;
        }
        cout<<win<<endl;
        }
}
