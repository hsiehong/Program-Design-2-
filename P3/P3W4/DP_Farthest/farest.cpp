#include<bits/stdc++.h>

using namespace std;

int main(void){
    cin.tie(0);
    int n,t,farest,left,right,value;
    const int nsize=2000;
    while(1){
        cin>>n;
        if(n==0)break;
        int last[nsize];
        for(int i=0;i<nsize;i++)last[i]=-1;
        farest=value=0;
        left=right=-1;
        for(int i=0;i<n;i++){
            cin>>t;
            if(last[t]!=-1){
                if(farest<(i-last[t])){
                    farest=i-last[t];
                    left=last[t];
                    right=i;
                    value=t;
                }
            }
            else last[t]=i;
        }
        if(farest!=0)printf("(%d,%d):%d\n",left,right,value);
        else printf("No solution\n");
    }
    return 0;
}
