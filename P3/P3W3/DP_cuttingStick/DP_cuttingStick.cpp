#include<bits/stdc++.h>

using namespace std;

const int N=1000;
int point[N];
int table[N][N];

int cost(int i,int j){
    int t;
    if(j<=i+1)return 0;//相鄰兩點
    if(table[i][j]>=0)return table[i][j];//已記錄果此點，lazy DP
    int mincost=99999;
    for(int k=i+1;k<j;k++){
        t=cost(i,k)+cost(k,j);
        mincost=(mincost<t)?mincost:t;
    }
    mincost+=(point[j]-point[i]);//此段的長度
    table[i][j]=mincost;
    return mincost;
}
void sol(int length){
    int cuts,ans;
    cin>>cuts;
    for(int i=1;i<=cuts;i++){
        cin>>point[i];
    }
    point[0]=0;point[cuts+1]=length;
    //sort(point+1,point+cuts+1);
    for(int i=0;i<cuts+2;i++)for(int k=0;k<cuts+2;k++)table[i][k]=-1;
    ans=cost(0,cuts+1);
    cout<<"The minimum cutting is "<<ans<<"."<<endl;
}

int main(void){
    cin.tie(0);
    int length;
    while(1){
        cin>>length;
        if(length==0)break;
        sol(length);
    }
    return 0;
}
