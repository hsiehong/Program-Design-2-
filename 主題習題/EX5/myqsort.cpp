#include<bits/stdc++.h>

using namespace std;

void mysort(void *start , int n , size_t nsize , int (*cmp)(void*,void*)){
    if(n<=1)return;
    char *i,*piv,*np,*base=(char*)start;
    piv=base+(n-1)*nsize;
}
void myswap(char *p,char *q,size_t nsize){
    if(p==q)return;
    char *t=new char[nsize];
    memcpy(t,p,nsize);
    memcpy(p,q,nsize);
    memcpy(q,t,nsize);
    return;
}
int mycmp(char *p,char *q,size_t nsize){
    if(p==q)return 0;
    char *t=new char[nsize];
    memcpy(t,p,nsize);
    memcpy(p,q,nsize);
    memcpy(q,t,nsize);
    return 0;
}
int main(void){
    int n;

    while(1){
        cin>>n;
        if(n==0)break;
        int *base=new int[n];
        for(int i=0;i<n;i++)cin>>base[i];
        mysort(base,n,sizeof(int),mycmp);

        delete [] base;
    }
    return 0;
}
