#include<iostream>

using namespace std;

int mult(int m[3],int temp[50],int a,int nt,int res[50]){
    for(int i=0;i<=nt+2;i++)res[i]=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<=nt;j++){
            res[i+j]+=m[i]*temp[j];
        }
    }
    return nt+a;
}
main(void){
    int ncase,m[3],res[50],temp[50];
    cin>>ncase;
    while(ncase--){
        int d,nt;
        cin>>m[2]>>m[1]>>m[0]>>d;
        nt=2;
        for(int i=0;i<3;i++)temp[i]=m[i];
        for(int i=1;i<d;i++){
            nt=mult(m,temp,2,nt,res);
            for(int i=0;i<=nt;i++)temp[i]=res[i];
        }
        for(int i=nt;i>0;i--)cout<<temp[i]<<" ";
        cout<<temp[0];
        if(ncase>0)cout<<endl;
    }
    return 0;
}
