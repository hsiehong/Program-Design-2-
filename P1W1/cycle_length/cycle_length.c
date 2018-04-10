#include<stdio.h>
#define N 1000100

main(){
    int p,q,i,*book,ans;
    while(scanf("%d %d",&p,&q)!=EOF){
        if(q==0)break;
        book=malloc(N*sizeof(int));
        for(i=0;i<N;i++)book[i]=0;
        //for(i=0;i<50;i++)printf("%d\n",book[i]+i);

        for(i=1;i<N;i++){
            if(book[p]){
                ans=i-book[p];
                break;
            }
            book[p]=i;
            //printf("p=%d book[p]=%d\n",p,book[p]);
            p=(p*10)%q;

        }
        printf("%d\n",ans);
        free(book);
    }
    return 0;
}
