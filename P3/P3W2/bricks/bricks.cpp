#include<iostream>

using namespace std;

int main(void){
    int n,t[60],avg,ans,total,time=1;
    while(1){
        cin>>n;
        if(n==0)break;
        total=0;
        for(int i=0;i<n;i++){
            cin>>t[i];
            total+=t[i];
        }
        avg=total/n;
        ans=0;
        for(int i=0;i<n;i++){
            if(t[i]>avg){
                ans+=t[i]-avg;
            }
        }
        cout<<"Set #"<<time<<endl;
        cout<<"The minimum number of moves is "<<ans<<"."<<endl<<endl;
        time++;
    }
    return 0;
}
