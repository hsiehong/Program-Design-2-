#include<iostream>
#include<queue>
#define N 1010
#include<cstdio>

using namespace std;

void solve(){
    int parent[N],weight[N],deg[N],n,t,mymax,up;
    int f1[N],f2[N];//f1�����]�A�������̨θ�,f2���]�A����
    queue <int> que;
    cin>>n>>weight[1];
    for(int i=2;i<=n;i++){
        cin>>parent[i]>>weight[i];
    }

    for(int i=1;i<=n;i++)f1[i]=f2[i]=deg[i]=0;
    parent[1]=0;
    for(int i=1;i<=n;i++)deg[parent[i]]++;
    for(int i=1;i<=n;i++)f2[i]=weight[i];
    for(int i=1;i<=n;i++){
        if(deg[i]==0){//it means leaf
            que.push(i);
        }
    }
    int total=0;
    while(!que.empty()){
        t=que.front();
        que.pop();
        mymax=max(f1[t],f2[t]);
        up=parent[t];
        if(up==0){//�u��root��parent���s�A��ܤw�g�S���F��i�H�]�F�A�W�@��pop�w��root�ᱼ�F
            if(mymax>0)total=mymax;
            continue;
        }
        f1[up]+=mymax;
        f2[up]+=f1[t];
        deg[up]--;
        if(deg[up]==0){
            que.push(up);
        }
    }
    cout<<total<<endl;
//    cout<<max(f1[1],f2[1])<<endl;
}

int main(void){
    freopen("indepTree.in","r",stdin);
    int ncase;
    cin>>ncase;
    while(ncase--){
        solve();
    }
    return 0;
}
