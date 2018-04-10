#include<iostream>

using namespace std;

main(void){
    int ncase,q1,r1,q2,r2,a,b,temp;
    cin>>ncase;
    while(ncase--){
        cin>>q1>>r1>>q2>>r2;
        a=q1-r1;b=q2-r2;
        while(b!=0){
            a%=b;
            temp=a;
            a=b;
            b=temp;
        }
        for(int i=1;i<=a/2;i++)
            if(a%i==0)cout<<i<<" ";
        cout<<a<<endl;
    }
    return 0;
}
