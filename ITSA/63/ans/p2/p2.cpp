#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main(void){
    int ncase,l,a,b;
    char line[100];
    cin>>ncase;getchar();
    while(ncase--){
            a=b=0;
        gets(line);
        l=strlen(line);
        for(int i=0;i<l;i++){
            if(line[i]=='(')a++;
            else b++;
        }
        if(a==b)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}


