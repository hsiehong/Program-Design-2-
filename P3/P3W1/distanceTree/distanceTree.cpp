#include<iostream>
#include<vector>
#define N 5000
using namespace std;



typedef pair<int,int>myPair;
vector <myPair> E[N];
int parent[N];
int s[N],tcase;
long long Ans;


void dfs(int u){
    vector<myPair>::iterator it;
    s[u]=1;
    for(it=E[u].begin();it!=E[u].end();++it){
        dfs(it->first);
        s[u]+=s[it->first];
    }
    for(it=E[u].begin();it!=E[u].end();++it){
        Ans+=s[it->first]*(tcase-s[it->first])*(long long)it->second;
    }
}

long long solve(){
    Ans=0;
    dfs(0);
    for(int i=0;i<tcase;i++){
        vector<myPair>().swap(E[i]);
    }
    return Ans;
}
int main(void){
    int ncase,t;
    cin>>ncase;
    while(--ncase>=0){
        cin>>tcase;
        for(int i=1;i<tcase;i++)cin>>parent[i];
        for(int i=1;i<tcase;i++){
            cin>>t;
            E[parent[i]].push_back(myPair(i,t));
        }
        Ans=2*solve();
        cout<<Ans<<endl;
    }
    return 0;
}
