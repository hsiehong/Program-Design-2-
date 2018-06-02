#include<bits/stdc++.h>
#define N 1000005

using namespace std;

int cost[N];
int weight[N];

int dp(int goal,int n){
    if(cost[goal]>=0)return cost[goal];
    int t=0,k;
    for(int i=0;i<n;i++){
        if(goal&(1<<i)){
            k=dp(goal^(1<<i),n);
            if(k>t)t=k;
        }
    }
    cost[goal]=t+weight[goal];
    return cost[goal];
}
int main(void){
    cin.tie(0);
    //freopen("DP_hypercube.in","r",stdin);
    int n;
    while(1){
        cin>>n;
        if(n==0)break;
        int m=1<<n;
        for(int i=0;i<m;i++)cin>>weight[i];
        for(int i=0;i<m;i++)cost[i]=-1;
        cost[0]=weight[0];
        int ans=dp(m-1,n);
        cout<<ans<<endl;
    }
    return 0;
}
