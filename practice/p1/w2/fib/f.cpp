#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;
typedef long long LL;

int main(void){
    LL t[3][3],n,p,res[3][3],s,temp[3][3],tt[3][3]={0};
    while(scanf("%lld %lld %lld %lld %lld",&n,&p,&tt[0][0],&tt[0][1],&tt[0][2])!=EOF){
        for(int i=1;i<3;i++)for(int j=0;j<3;j++)tt[i][j]=0;
        tt[1][0]=tt[2][1]=1;
        for(int i=1;i<3;i++)for(int j=0;j<3;j++)t[i][j]=tt[i][j];
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)res[i][j]=0;
        for(int i=0;i<3;i++)res[i][i]=1;
        int y=n-3;
        while(y>0){
            if(y&1){
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                            s=0;
                        for(int k=0;k<3;k++){
                            s=(s+(t[i][k]*res[k][j])%p)%p;
                        }
                        temp[i][j]=s;
                    }
                }
                for(int i=0;i<3;i++)for(int j=0;j<3;j++)res[i][j]=temp[i][j];
            }
                y>>=1;
                for(int i=0;i<3;i++)for(int j=0;j<3;j++){
                    s=0;
                    for(int k=0;k<3;k++){
                        s=(s+(t[i][k]*t[k][j])%p)%p;
                    }
                    temp[i][j]=s;
                }
                for(int i=0;i<3;i++)for(int j=0;j<3;j++)t[i][j]=temp[i][j];
            }
            LL ans=0;
            for(int i=0;i<3;i++)ans=(ans+res[0][i])%p;
            //printf("%lld\n",ans);
            cout<<(int)ans<<endl;
        }
    return 0;
}
