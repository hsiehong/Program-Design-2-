#include<bits/stdc++.h>
#define N 20

using namespace std;

int n,wa,wb,l,ans;
int weight[N],value[N];

void dfs(int dep,int c,int sv,int sw){
    if(sw>wb)return;
    int t;
    if(dep==n){
        if(c>=l&&sw>=wa){
            t=sv/sw;
            if(t*sw!=sv)t++;
            if(t>ans)ans=t;
        }
        return;
    }
    dfs(dep+1,c+1,sv+value[dep],sw+weight[dep]);
    dfs(dep+1,c,sv,sw);
}
int main(void){
    int opt=0;
    while(!opt){
        scanf("%d%d%d%d",&n,&l,&wa,&wb);
        for(int i=0;i<n;i++) scanf("%d%d",&value[i],&weight[i]);
        ans=-1;
        dfs(0,0,0,0);
        printf("%d\n",ans);
        scanf("%d",&opt);
    }
    return 0;
}
