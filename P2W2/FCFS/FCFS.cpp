#include<iostream>
#include<queue>
#define N 100000

using namespace std;

    //minimal complete time, n jobs with m machines
int counttime(int n,int m,int t[N]){
    priority_queue <int> pq;
    int tt;
    for(int i=0;i<m;i++)pq.push(0);
    for(int i=0;i<n;i++){
        tt=pq.top()-t[i];
        pq.pop();
        pq.push(tt);
    }
    for(int i=0;i<m-1;i++)pq.pop();
    tt=-pq.top();
    pq.pop();
    return tt;
}

int main(void){
    int ncase,n,d,t[N],sum,maxx;
    cin>>ncase;
    while(ncase--){
        cin>>n>>d;//number of jobs,d for deadline
        for(int i=0,sum=maxx=0;i<n;i++){
            cin>>t[i];cin.tie(0);
            sum+=t[i];
            maxx=(t[i]>maxx)?t[i]:maxx;
        }
        if(maxx>d){cout<<"-1"<<endl;continue;}
        int down=1,up=n,k,s;//假設最少一台，最多n台
            //binary search
        while(down<up){
            k=(up+down)/2;
            s=counttime(n,k,t);
            if(s<=d)up=k;
            else down=k+1;
        }
        cout<<up<<endl;
    }
    return 0;
}
