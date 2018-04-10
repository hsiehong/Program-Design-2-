#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#define N 10000

using namespace std;

int main(void){
    int ncase,x[N],y[N],t;
    char line[N],*token;
    cin>>ncase;
    getchar();
    while(ncase--){
        //x-cordinate
        gets(line);
        token=strtok(line," ");
        int i=0;
        while(token!=NULL){
            t=atoi(token);
            t=(t>0)?t:-t;
            x[i++]=t;
            token=strtok(NULL," ");
        }
        //y-cordinate
        gets(line);
        token=strtok(line," ");
        i=0;
        while(token!=NULL){
            t=atoi(token);
            t=(t>0)?t:-t;
            y[i++]=t;
            token=strtok(NULL," ");
        }
        sort(x,x+i);
        sort(y,y+i);
        double total=0;
        for(int j=0,k=i-1;j<i;j++,k--){
            total+=sqrt(x[j]*x[j]+y[k]*y[k]);
        }
        cout<<(int)total<<endl;
    }
    return 0;
}
