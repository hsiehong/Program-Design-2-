#include<iostream>
#define N 5010
using namespace std;

int main(void){
    int ncase,tcase,head,tail,que[N],s;
    int n_node[N],parent[N],edge[N],deg[N];
    long long total,sol;
    cin>>ncase;
    while(ncase--){
        cin>>tcase;
        for(int i=2;i<=tcase;i++)cin>>parent[i];
        for(int i=2;i<=tcase;i++)cin>>edge[i];
        for(int i=1;i<=tcase;i++)deg[i]=0;
        for(int i=2;i<=tcase;i++)deg[parent[i]]++;
        head=tail=0;
        for(int i=1;i<=tcase;i++){
            if(deg[i]==0)que[tail++]=i;
        }
        for(int i=1;i<=tcase;i++)n_node[i]=1;
        while(head<tail){
            s=que[head++];
            n_node[parent[s]]+=n_node[s];//計算每個點的子節點數
            deg[parent[s]]--;
            if(deg[parent[s]]==0)que[tail++]=parent[s];//若某節點變成leaf，加入que中
        }
        total=0;
        for(int i=tcase;i>1;i--){
            sol=2*n_node[i]*(tcase-n_node[i])*edge[i];
            total+=sol;
        }
        cout<<total<<endl;
    }
    return 0;
}
