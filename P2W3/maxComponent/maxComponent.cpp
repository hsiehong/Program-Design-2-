#include<iostream>
#include<vector>
#include<queue>
#define N 50000

using namespace std;

vector <int> edge[N];

//sum of any component
int bfs(int i,int wei[],bool vis[]){
    queue <int> que;
    int sum,u,v;
    que.push(i);
    vis[i]=true;sum=wei[i];
    while(!que.empty()){
        v=que.front();que.pop();
        for(auto &u:edge[v]){
            if(!vis[u]){
               que.push(u);
                vis[u]=true;
                sum+=wei[u];
            }
        }
    }
    return sum;
}

int main(void){
    int ncase,n,m,u,v,ans,t;
    int weight[N];
    bool visit[N];
    cin>>ncase;
    while(ncase--){
        cin>>n>>m;//node and edge
        //ios_base::sync_with_stdio(false);
        cin.tie(0);
        for(int i=0;i<n;i++){
            cin>>weight[i];
            edge[i].clear();
        }
        while(m--){
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for(int i=0;i<n;i++)visit[i]=false;
        ans=0;
        for(int i=0;i<n;i++){
            if(visit[i])continue;
            t=bfs(i,weight,visit);
            if(t>ans)ans=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
