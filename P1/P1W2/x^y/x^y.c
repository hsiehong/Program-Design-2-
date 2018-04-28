#include<stdio.h>

main()
{
    int ncase;
    unsigned int x,y,p;
    unsigned long long ans,xi;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%u %u %u",&x,&y,&p);
        ans=1,xi=x;
        while(y>0){
            if(y&1)ans=(ans*xi)%p;
            y>>=1;
            xi=(xi*xi)%p;
        }
        printf("%d\n",(int)ans);
    }
    return 0;
}
