#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctype.h>
#define N 200

using namespace std;

int main(void){
    int l;
    char line[N],res[N],s;
    while(gets(line)!=NULL){
        l=strlen(line);
        for(int i=0;i<l;i++){
            if(isalpha(line[i])){
                if(isupper(line[i]))s=25-(line[i]-'A')+'a';
                else s=25-(line[i]-'a')+'A';
                cout<<(char)s;
            }
            else if(isdigit(line[i])){
                if(line[i]-'0'<9)s=line[i]+1;
                else s='0';
                cout<<s;
            }
            else cout<<line[i];
        }
        cout<<endl;
    }
    return 0;
}
