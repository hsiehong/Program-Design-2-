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
    int n,dp[N];//dp:�O���ei�����̨θ�
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
        while(head+1<tail){//�Y�Ѩ�ӴN���ηj�F�A�����B�z�ѤU������ӴN�i�H�F
            t=(head+tail)/2;
            if(interval[t].right<=interval[i].left)head=t;
            else tail=t-1;
        }
        if(interval[tail].right<=interval[i].left)t=tail;//�P�_�̫�Ѿl�����
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