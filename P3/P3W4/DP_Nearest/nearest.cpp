#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n,t,pre;
    const int nsize=2000;
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        int last[nsize];
        for(int i=0;i<nsize;++i)last[i]=-1;
        int interval=nsize,left,right,value;
        for(int i=0;i<n;++i){
            scanf("%d",&t);
                //has appeared before
            if(last[t]!=-1){
                    pre=last[t];
                    last[t]=i;
                if(interval>(i-pre)){
                    interval=(i-pre);
                    left=pre;
                    right=i;
                    value=t;
                }
            }
                //first appeared
            else last[t]=i;
        }
        if(interval!=nsize)printf("(%d,%d):%d\n",left,right,value);
        else printf("No solution\n");
    }
    return 0;
}
