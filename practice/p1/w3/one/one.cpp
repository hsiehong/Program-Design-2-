#include<iostream>
#include<algorithm>
#define N 10000

using namespace std;

bool cmp(int i,int j){
    return i<j;
}

main(){
    int ncase,e[N],s[N];
    while(1){
        cin>>ncase;
        if(ncase==0)break;
        for(int i=0;i<ncase;i++)cin>>e[i];
        for(int i=0;i<ncase;i++)cin>>s[i];
        sort(e,e+ncase,cmp);
        sort(s,s+ncase,cmp);
        int i=0,j=0,win=0;
        while(j<ncase){
            while(e[i]>=s[j]&&j<ncase)j++;
            if(j==ncase)break;
            i++;
            j++;
            win++;
        }
        cout<<win<<endl;
    }
    return 0;
}
