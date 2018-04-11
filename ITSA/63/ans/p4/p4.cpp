#include<iostream>

using namespace std;

int main(void){
    int n,arr[20],t,tt,total,ck,ok;
    bool flag=false;
    cin>>n;
    total=0;
    for(int i=0;i<n;i++){
        cin>>t;
        arr[i]=t;total+=t;
    }ok=0;
    for(int i=total;i>0;i--){
        t=i;tt=t/4;
        if(ok==4)break;
        if(t%4==0){
                //one edge
            for(int j=0;j<n;j++){
                if(arr[j]==tt){
                    arr[j]=0;ok++;
                }
                if(ok==4)break;
            }
            for(int j=0;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[j]+arr[k]==tt){
                        arr[j]=arr[k]=0;
                        ok++;
                    }
                    if(ok==4)break;
                }
                if(ok==4)break;
            }
            if(ok==4)break;
            for(int j=0;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    for(int l=k+1;l<n;l++){
                        if(arr[j]+arr[k]+arr[l]==tt){
                            arr[j]=arr[k]=arr[l]=0;
                            ok++;
                        }
                        if(ok==4)break;
                    }
                    if(ok==4)break;
                }
                if(ok==4)break;
            }
        }
        if(ok==4)break;
    }
    if(ok==4)cout<<"yes";
    else cout<<"no";
    return 0;
}


