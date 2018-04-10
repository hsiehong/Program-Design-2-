#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 10000

using namespace std;

bool cmp(int a,int b){
    return a<b;
}
main(){
    int n,nn,ii;
    int xx[N],yy[N];
    char line[N],*token;
    scanf("%d\n",&n);
    double t;
    while(n--){
        fgets(line,N,stdin);
        ii=0;
        token=strtok(line," ");
        while(token!=NULL){
            xx[ii++]=((atoi(token)<0)?-atoi(token):atoi(token));
            token=strtok(NULL," ");
        }
        fgets(line,N,stdin);
        ii=0;
        token=strtok(line," ");
        while(token!=NULL){
            yy[ii++]=((atoi(token)<0)?-atoi(token):atoi(token));
            token=strtok(NULL," ");
        }
        sort(xx,xx+ii,cmp);
        sort(yy,yy+ii,cmp);
        t=0;
        for(int i=0,j=ii-1;i<ii;i++,j--){
            t+=sqrt(xx[i]*xx[i]+yy[j]*yy[j]);
        }
        cout<<(int)t<<endl;
    }
}
