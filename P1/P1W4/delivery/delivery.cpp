#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

bool cmp(int a,int b){
    return a<b;
}
int main(void){
    int ncase,delnum,sum,*arr,t;
    cin>>ncase;
    while(ncase--){
        cin>>delnum;
        arr=(int*)malloc(delnum*sizeof(int));
        for(int i=0;i<delnum;i++)cin>>arr[i];
        sort(arr,arr+delnum,cmp);
        sum=t=arr[0];
        for(int i=1;i<delnum;i++){
            t+=arr[i-1]+arr[i];
            sum+=t;
        }
        cout<<sum<<endl;
    }
    return 0;
}
