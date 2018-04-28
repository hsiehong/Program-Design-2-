#include<iostream>
#include<algorithm>
#define N 10000

using namespace std;

bool cmp(int a,int b){
    return a<b;
}

main(){
    int ncase,item,carry,box[N],man[N];
    cin>>ncase;
    while(ncase--){
        cin>>item>>carry;
        for(int i=0;i<item;i++)cin>>box[i];
        for(int i=0;i<carry;i++)cin>>man[i];
        if(item>carry){cout<<"-1"<<endl;break;}
        sort(box,box+item,cmp);
        sort(man,man+carry,cmp);
        int i,j,sum;//i->box;j->man
        i=j=sum=0;
        while(i<=j){
            while(box[i]>man[j]&&j<carry)j++;
            if(j==carry&&i<item){cout<<"-1"<<endl;break;}
            else if(i==item)break;
            sum+=man[j];i++;j++;
        }
        if(i==item)cout<<sum<<endl;
    }
}
