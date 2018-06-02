#include<bits/stdc++.h>

using namespace std;

int main(void){
    cin.tie(0);
    int ncase,node;
    cin>>ncase;
    while(--ncase>=0){
        cin>>node;
        int *parent=new int[node];//parent of node
        int *deg=new int[node];//degree of node
        int *long1=new int[node];//1st long path to leaves
        int *long2=new int[node];//2nd long path to leaves
        for(int i=0;i<node;i++)deg[i]=long1[i]=long2[i]=parent[i]=0;
        int ta,tb;
        parent[0]=-1;//root condition
        for(int i=1;i<node;i++){
            cin>>ta>>tb;
            parent[tb]=ta;
            deg[ta]++;
        }
        queue <int> que;
        for(int i=0;i<node;i++){
            if(deg[i]==0)que.push(i);
        }
        int ans=0;
        while(!que.empty()){
            int t=que.front();
            que.pop();
            ans=max(ans,long1[t]+long2[t]);
            int p=parent[t];
            if(p==-1)break;//root
            int longest=long1[t]+1;//longest path to parent
            if(longest>long1[p]){
                long2[p]=long1[p];
                long1[p]=longest;
            }
            else if(longest>long2[p]){
                long2[p]=longest;
            }
            deg[p]--;
            if(deg[p]==0)que.push(p);
        }
        cout<<ans<<endl;
        delete [] parent,node,long1,long2;
    }
    return 0;
}
