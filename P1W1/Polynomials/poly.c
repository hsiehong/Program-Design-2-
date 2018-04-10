#include<stdio.h>
#define N 100

int mult(int res[N],int na,int mul[N],int temp[N],int nb){
    int m,n;
    for(m=0;m<=na+nb;m++)temp[m]=0;
    for(m=0;m<=na;m++){
        for(n=0;n<=nb;n++){
            temp[m+n]+=res[m]*mul[n];
        }
    }
    return na+nb;
}
main(){
    int ncase,j,d,res[N],mul[N],temp[N],i,nb,nc;//nc:被乘式次數 nb:乘式次數
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d %d %d %d",&mul[2],&mul[1],&mul[0],&d);//低次存到高次
        nb=nc=2;
        for(i=0;i<=2;i++)res[i]=mul[i];//初始是兩個一樣的相乘
        for(i=1;i<d;i++){
            nc=mult(res,nc,mul,temp,nb);
            for(j=0;j<=nc;j++){
                res[j]=temp[j];
            }
        }
        for(i=nc;i>0;i--)printf("%d ",res[i]);
        printf("%d",res[0]);
        if(ncase>0)printf("\n");
    }
    return 0;
}
