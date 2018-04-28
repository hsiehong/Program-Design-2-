#include<iostream>
#include<queue>

using namespace std;

int main(void){
    int ncase,c,m,t,r;//c:case,m:machine
    priority_queue<int> pq;
    cin>>ncase;
    while(ncase--){
        cin>>c>>m;
        for(int i=0;i<m;i++)pq.push(0);
        for(int i=0;i<c;i++){
            cin>>t;
            r=pq.top(); // r is the fewest work among machines
            pq.pop();// remove the work of fewest machine to add new load
            pq.push(r-t);
        }
        for(int i=0;i<m-1;i++)pq.pop();
        cout<<-pq.top()<<endl;
        pq.pop();//clear the queue
    }
    return 0;
}
