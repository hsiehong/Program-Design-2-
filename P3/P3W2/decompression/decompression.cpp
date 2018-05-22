#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstdlib>

using namespace std;

int main(void){
    int ncase;
    const int N=1030;
    char in[N],num[5],text[20];
    while(fgets(in,N,stdin)!=NULL){
        int l=strlen(in);
        int a=0,b=0;
        for(int i=0;i<l-1;i++){
            if(isdigit(in[i])){
                num[a++]=in[i];
                num[a]='\0';
            }
            else{
                text[b++]=in[i];
                text[b]='\0';
                if(isdigit(in[i+1])||i==l-2){
                    int t=atoi(num);
                    while(--t>=0){
                        cout<<text;
                    }
                    a=b=0;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
