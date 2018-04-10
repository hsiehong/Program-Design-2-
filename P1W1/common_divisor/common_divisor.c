#include<stdio.h>

main(){
    int q1,q2,r1,r2,ncase,a,b,k,temp;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d %d %d %d",&q1,&r1,&q2,&r2);
        a=q1-r1;
        b=q2-r2;
        do{
           a%=b;
           if(b>a){
                temp=b;
                b=a;
                a=temp;
           }
        }
        while(b!=0);
        //printf("%d\n",a);
        printf("1");
        for(k=2;k<=a;k++){
            if(a%k==0)printf(" %d",k);
        }
        if(ncase>0)printf("\n");
    }
    return 0;
}
