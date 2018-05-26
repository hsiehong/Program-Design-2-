#include<iostream>
#include<queue>
#include<vector>
#define N 50000
#define M 100000
#include<cstdio>

using namespace std;

int main(void){
    freopen("t_large.in","r",stdin);
    int n,m,t,start[N],c[N],u,v,k,mymax;
    bool flag[N];
    while(1){
        cin>>n>>m>>t;if(n==0)break;
        vector <int> edge[M];// the neighbor of each city
        queue <int> que;// we need to go through all cities to find the maxtreasure
        for(int i=0;i<t;i++)cin>>start[i];
        for(int i=0;i<n;i++)cin>>c[i];
        for(int i=0;i<m;i++){
            cin>>u>>v;
            edge[u].push_back(v);
        }
        mymax=0;
        for(int i=0;i<n;i++)flag[i]=false;
        for(int i=0;i<t;i++){
            k=start[i];
            if(flag[k])continue; //�Yk�w�Q���X�L�A�h���k�i�쪺�a��]�w�Q���X�L
            flag[k]=true;
            que.push(k); //k is the first city
            while(!que.empty()){
                u=que.front();
                que.pop();
                if(c[u]>mymax)mymax=c[u];
                    //�Yvector�S�����s�ŧi�A���i��|�]��W�@�������(auto�|�ۤv�]��)
                for(auto &v:edge[u]){ // �N�Ҧ�k�i�쪺����[�Jque��
                    if(!flag[v]){
                        que.push(v);
                        flag[v]=true;
                    }
                }
            }
        }
        cout<<mymax<<endl;
    }
    return 0;
}
