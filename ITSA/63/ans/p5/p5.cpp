#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(void){
    char line[15];
    int total,t;
    while(gets(line)!=NULL){
        t=2;total=0;
        total+=(line[0]-'0')*1;
        for(int i=2;i<=4;i++){
            total+=(line[i]-'0')*t;
            t++;
        }
        for(int i=6;i<=10;i++){
            total+=(line[i]-'0')*t;
            t++;
        }
        //cout<<total<<endl;
        if(total%11==line[12]-'0')cout<<"Pass"<<endl;
        else cout<<"Fail"<<endl;
    }
    return 0;
}
