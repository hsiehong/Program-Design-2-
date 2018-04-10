#include<stdio.h>

long long m[3][3]={0};
long long n,p;

void xyp(){
    long long t[3][3]={0},xi[3][3],t2[3][3],y=n-3,s,ans;
    int i,j,k;
    for(i=0;i<3;i++)t[i][i]=1;
    for(i=0;i<3;i++)for(j=0;j<3;j++)xi[i][j]=m[i][j];
    while(y>0){
        if(y&1){
            for(i=0;i<3;i++)for(j=0;j<3;j++){
                    s=0;
                for(k=0;k<3;k++){
                    s=(s+(t[i][k]*xi[k][j])%p)%p;
                }
                t2[i][j]=s;
            }
            for(i=0;i<3;i++)for(j=0;j<3;j++)t[i][j]=t2[i][j];
        }
            y>>=1;
            for(i=0;i<3;i++)for(j=0;j<3;j++){
                    s=0;
                for(k=0;k<3;k++){
                    s=(s+(xi[i][k]*xi[k][j])%p)%p;
                }
                t2[i][j]=s;
            }
            for(i=0;i<3;i++)for(j=0;j<3;j++)xi[i][j]=t2[i][j];
        }
        ans=0;
        for(i=0;i<3;i++)ans=(ans+t[0][i])%p;
        //ans=(t[0][0]+t[0][1]+t[0][2])%p;
        printf("%lld\n",ans);
    }

main(){
    m[1][0]=1,m[2][1]=1;
    while(scanf("%lld %lld %lld %lld %lld",&n,&p,&m[0][0],&m[0][1],&m[0][2])!=EOF){
        xyp();
    }
    return 0;
}
