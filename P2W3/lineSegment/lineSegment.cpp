#include<iostream>
#include<algorithm>
#define N 50000

using namespace std;

struct edge{
    int left;
    int right;
};
bool cmp(edge a,edge b){
    return (a.left<b.left);
}
int main(void){
    cin.tie(0);
    int ncase,m,l,r,s,k,a1,a2;
    unsigned long ans;
    edge line[N];
    cin>>ncase;
    while(ncase--){
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>s>>k;
            if(s<k){
                line[i].left=s;
                line[i].right=k;
            }
            else{
                line[i].left=k;
                line[i].right=s;
            }
        }
        sort(line,line+m,cmp);
        a1=line[0].left;a2=line[0].right;
        ans=0;
        for(int i=1;i<m;i++){
                //��u�q�L�涰�����A�p��M
            if(line[i].left>a2){
                ans+=(a2-a1);
                a1=line[i].left;a2=line[i].right;
            }
            //��u�q����������A�X�ֽu�q
            else{
                //�T�{�u�q2���k���I�j���k�ݡA�S�����ܸ��L���u�q
                if(line[i].right>a2){
                    a2=line[i].right;
                }
            }
        }
        ans+=(a2-a1);
        cout<<ans<<endl;
    }
    return 0;
}
