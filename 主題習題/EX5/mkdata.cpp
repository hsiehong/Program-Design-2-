#include<bits/stdc++.h>

using namespace std;

struct Stru{
    int a,b;
};
int main(void){
    srand(time(NULL));
    freopen("t10_in.txt","w",stdout);
    //freopen("t13_in.txt","w",stdout);
    int n,m;
    while(1){
        cin>>n;
        cout<<n<<endl;
        if(n==0)break;
//        Stru *a=new Stru[n];
//        for(int i=0;i<n;i++){
//            cin>>a[i].a>>a[i].b;
//        }
//        sort(a,a+n,cmp);
//        for(int i=0;i<n;i++)cout<<a[i].a<<" "<<a[i].b<<endl;
//        cout<<endl;
//        delete [] a;



        for(int i=0;i<n;i++){
            cout<<rand()%100<<" ";
        }
        cout<<endl;
    }
    return 0;
}
