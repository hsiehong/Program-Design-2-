#include<iostream>
#include<string.h>
#include<cstdio>
#define N 1000

using namespace std;

main(){
    int ncase,l,bk[26];
    char line[N];
    scanf("%d\n",&ncase);
    while(ncase--){
        for(int i=0;i<26;i++)bk[i]=0;
        fgets(line,N,stdin);
        l=strlen(line);
        for(int i=0;i<l;i++){
            if(isalpha(line[i])){
                if(line[i]>='A'&&line[i]<='Z')bk[line[i]-'A']++;
                else bk[line[i]-'a']++;
            }
        }
        int mymax=0;
        for(int i=0;i<26;i++)mymax=(bk[i]>mymax)?bk[i]:mymax;
        for(int i=0;i<26;i++)if(bk[i]==mymax)cout<<(char)(i+'A')<<endl;
    }
}
