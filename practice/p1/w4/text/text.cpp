#include<iostream>
#include<cstring>
#include<ctype.h>
#include<cstdio>
#define N 1000

using namespace std;

int main(void){
    int ncase,l,bk[26];
    char line[N];
    cin>>ncase;
    getchar();
    while(ncase--){
        gets(line);
        l=strlen(line);
        for(int i=0;i<26;i++)bk[i]=0;
        for(int i=0;i<l;i++){
            if(isalpha(line[i])){
                if(line[i]>='A'&&line[i]<='Z')bk[line[i]-'A']++;
                else bk[line[i]-'a']++;
            }
        }
        int mymax=0;
        for(int i=0;i<26;i++)if(bk[i]>mymax)mymax=bk[i];
        for(int i=0;i<26;i++)if(bk[i]==mymax)cout<<(char)(i+'A');
        if(ncase>0)cout<<endl;
    }
    return 0;
}
