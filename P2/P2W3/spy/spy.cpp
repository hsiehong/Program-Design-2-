#include<iostream>
#define N 10000
using namespace std;

int main(void){
    int ncase,num,leader[N];
    bool mark[N];
    cin>>ncase;
    while(ncase--){
        cin>>num;
        for(int i=1;i<num;i++){
            cin>>leader[i];
            mark[i]=false;
        }
        int d=0;
        for(int i=num-1;i>0;i--){
            if(mark[i]){d++;continue;}
            mark[leader[i]]=true;
        }
        if(mark[0])d++;//chief
        cout<<d<<endl;
    }
    return 0;
}
