#include<stdio.h>
#define N 200

typedef long long LL;

LL xyp(LL a,LL b,LL p){
    LL ai,ans;
    ai=a,ans=1;
    while(b>0){
        if(b&1)ans=(ans*ai)%p;
        b>>=1;
        ai=(ai*ai)%p;
    }
    return (int)ans;
}

main(){
    char x[N],n[N];
    long long a,b,p;
    int i;
    while(scanf("%s %s %lld",x,n,&p)==3){
        for(a=0,i=0;x[i];i++){
            a=(x[i]-'0'+a*10)%p;
        }
        for(b=0,i=0;n[i];i++){
            b=(b*10+n[i]-'0')%(p-1);
        }
        printf("%d\n",xyp(a,b,p));
    }
    return 0;
}
