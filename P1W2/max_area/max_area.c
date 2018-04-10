#include<stdio.h>
#define N 50

main(){
    int ncase,tcase,i,j,k,x[N],y[N],temp,mymax;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&tcase);
        for(i=0;i<tcase;i++){
            scanf("%d %d",&x[i],&y[i]);
        }
        mymax=0;
        for(i=0;i<tcase;i++){
            for(j=i+1;j<tcase;j++){
                temp=((x[i])-(x[j]))*((y[i])-(y[j]));
                if(temp<0)temp=-temp;
                if(temp>mymax)mymax=temp;
            }
        }
        printf("%d",mymax);
        if(ncase>0)printf("\n");
    }
    return 0;
}
