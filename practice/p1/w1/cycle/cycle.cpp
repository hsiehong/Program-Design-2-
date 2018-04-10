#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000100

using namespace std;

int main(void){
    int p,q,*book;
    while(scanf("%d %d",&p,&q)!=EOF){
        if(q==0)break;
        book=(int*)malloc(sizeof(int)*N);
        for(int i=0;i<N;i++)book[i]=0;
        for(int i=1;i<N;i++){
            if(book[p]){
                int ans=i-book[p];
                cout<<ans<<endl;
                break;
            }
            book[p]=i;
            p=(p*10)%q;
        }
        free(book);
    }
    return 0;
}
