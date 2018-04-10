#include<iostream>
#include<cstring>
#include<cstdio>
#define N 200

using namespace std;

typedef long long LL;

LL xyp(LL a,LL b,LL p){
    LL ans=1;
    while(b>0){
        if(b&1)ans=(ans*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return (int)ans;
}
int main(void){
    char x[N],y[N];
    LL a,b,p;
    while(scanf("%s %s %lld",x,y,&p)!=EOF){
            a=b=0;
        for(int i=0;x[i];i++)a=(x[i]-'0'+a*10)%p;
        for(int i=0;y[i];i++)b=(y[i]-'0'+b*10)%(p-1);
        cout<<xyp(a,b,p)<<endl;
    }
    return 0;
}
