#include<iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--)cout<<" ";
        for(int k=i+1;k>0;k--)cout<<"*";
        cout<<endl;
    }
    return 0;
}
