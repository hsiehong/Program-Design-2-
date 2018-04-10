#include<iostream>
#include<algorithm>

using namespace std;

bool cmpr(int a,int b){
    return a<b;
}

int main(void){
    int ncase,icase,snum,item[10000],stu[10000];
    cin>>ncase;
    while(ncase--){
        cin>>icase>>snum;
        //if(icase>ncase)break;
        for(int i=0;i<icase;i++)cin>>item[i];
        for(int i=0;i<snum;i++)cin>>stu[i];
        sort(item,item+icase,cmpr);sort(stu,stu+snum,cmpr);
        int i=0,j=0,total=0;
        while(i<=j){
            while(item[i]>stu[j]&&j<snum)j++;
            if(j==snum&&i<icase){cout<<"-1"<<endl;break;}
            if(i==icase)break;
            total+=stu[j];i++;j++;
        }
        if(i==icase)cout<<total<<endl;
    }
    return 0;
}
