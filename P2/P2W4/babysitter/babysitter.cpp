#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10
#define M 50

using namespace std;

struct Inter{
    int left,right;
};
bool mysort(Inter a,Inter b){
    return (a.left<b.left);
}
int main(void){
    cin.tie(0);
    Inter inter[M];
    int ncase,i,a,b;
    char temp[N];
    cin>>ncase;
    getchar();
    gets(temp);
    while(ncase--){
            i=0;
            gets(temp);
        while(temp[0]!=0){//下行為空的表這筆測資輸入結束
            sscanf(temp,"%d %d",&a,&b);
            inter[i].left=((a<b)?a:b);
            inter[i].right=((a>b)?a:b);
            i++;
            if(gets(temp)==NULL)break;//end of line
        }
        sort(inter,inter+i,mysort);
        int ok=0,lbound=0,mright=-1,k=0;
        while(lbound<200){
            for(;inter[k].left<=lbound;k++){
                if(inter[k].right>mright)mright=inter[k].right;//找左端點在範圍內中，且又端點最大者
            }
            lbound=mright+1;
            ok++;
        }
        cout<<ok<<endl;
    }
    return 0;
}
