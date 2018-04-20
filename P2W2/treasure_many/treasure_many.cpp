#include<iostream>
#include<vector>
#include<queue>
#define N 5000
#define M 100000

using namespace std;

int main(void){
    int n,m,t,u,v,k;
    int visit[N],start[N],c[N];
    vector <int> edge[M];
    queue <int> que;
    while(1){
       cin>>n>>m>>t;if(n==0)break;
        for(int i=0;i<t;i++)cin>>start[i];
        for(int i=0;i<n;i++)cin>>c[i];
        for(int i=0;i<m;i++){
            cin>>u>>v;
            edge[u].push_back(v);
        }
        for(int i=0;i<n;i++)visit[i]=0;
        int mymax=0;
            //breadth first search
        for(int i=0;i<t;i++){
            k=start[i];
            //if(visit[k])continue;
            visit[k]=1;
            que.push(k);
            while(!que.empty()){
                u=que.front();
                que.pop();
                mymax=(c[u]>mymax)?c[u]:mymax;
                for(auto &v:edge[u]){   //for each neighbor of u
                    if(visit[v]==0){
                        que.push(v);
                        visit[v]=1;
                    }
                }
            }
        }
        cout<<mymax<<endl;
    }
    return 0;
}
