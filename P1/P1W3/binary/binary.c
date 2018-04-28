#include<stdio.h>
#include<string.h>
#define N 20

int trans(char line[N],int l){
    //cout<<line<<endl;
    int i,xi=1,k=0;
    for(i=l-1;i>=0;i--){
        if(line[i]=='1'){
            k+=xi;
        }
        xi*=2;
    }
    return k;
}
main(){
    int ncase,ans,k,l;
    char line[N];
    while(scanf("%d",&ncase)!=0){
        if(ncase==0)break;
        ans=0;
        while(ncase--){
            //fgets(line,N,stdin);
            scanf("%s",line);
            l=strlen(line);
            k=trans(line,l);
            ans+=k;
        }
        printf("%d\n",ans);
    }
    return 0;
}
