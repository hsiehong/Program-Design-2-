#include<iostream>

using namespace std;

int main(void){
    int ncase,n;
    cin>>ncase;
    while(--ncase>=0){
        cin>>n;
        int ans=0,t,temp=0;
        cin>>temp;
        for(int i=1;i<n;i++){
            cin>>t;
            if(temp>0){
                ans=(temp+t>ans)?temp+t:ans;
                temp+=t;
            }
            else temp=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
