#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100000

using namespace std;

struct Inter{
    int left,right,weight;
};

bool mycmp(Inter a,Inter b){
    return a.right<b.right;
}

sol(){
    int n,dp[N];//dp:記錄前i項的最佳解
    Inter interval[N];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&interval[i].left,&interval[i].right,&interval[i].weight);
    }
    sort(interval+1,interval+n+1,mycmp);//sort by right end
    for(int i=1;i<=n;i++)dp[i]=0;
    interval[0].left=interval[0].right=0;
    for(int i=1;i<=n;i++){
        int head=0,tail=i-1,t;
        while(head+1<tail){//若剩兩個就不用搜了，直接處理剩下的那兩個就可以了
            t=(head+tail)/2;
            if(interval[t].right<=interval[i].left)head=t;
            else tail=t-1;
        }
        if(interval[tail].right<=interval[i].left)t=tail;//判斷最後剩餘的兩個
        else t=head;
        dp[i]=max(dp[i-1],dp[t]+interval[i].weight);
    }
    printf("%d\n",dp[n]);
}

int main(void){
    int ncase;
    scanf("%d",&ncase);
    while(ncase--){
        sol();
    }
    return 0;
}
