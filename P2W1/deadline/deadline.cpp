#include<iostream>
#include<algorithm>
#define N 100

using namespace std;

struct data{
    int time,dline;
};

bool cmp(data a,data b){
    return a.dline<b.dline;
}

int main(void){
    int ncase,tcase,t;
    data work[N];
    cin>>ncase;
    while(ncase--){
        cin>>tcase;
        for(int i=0;i<tcase;i++)cin>>work[i].time;
        for(int i=0;i<tcase;i++)cin>>work[i].dline;

        sort(work,work+tcase,cmp);
        int k=0,i;
        for(i=0;i<tcase;i++){
            k+=work[i].time;
            if(k>work[i].dline)break;
        }
        if(i!=tcase)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
