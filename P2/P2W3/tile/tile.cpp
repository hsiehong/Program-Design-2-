#include<iostream>
#include<algorithm>

using namespace std;

struct squ{
    int h,w;
};
//寬 大到小排 寬度相同時照高度排 大到小
bool cmpr(squ a,squ b){
    if(a.w==b.w)return a.h>b.h;
    return a.w>b.w;
}
int main(void){
    int ncase,cate,s;
    squ t[12010];
    cin>>ncase;
    while(ncase--){
        cin>>cate;
        for(int i=0;i<cate;i++)cin>>t[i].h>>t[i].w;
        for(int i=0;i<cate;i++){
            t[cate+i].w=t[i].h;
            t[cate+i].h=t[i].w;
        }
        sort(t,t+2*cate,cmpr);
        int height=t[0].h,s=t[0].w;
        for(int i=1;i<cate*2;i++){
            if(t[i].w==s)continue;
            height+=t[i].h;
            s=t[i].w;
        }
        cout<<height<<endl;
    }
    return 0;
}
