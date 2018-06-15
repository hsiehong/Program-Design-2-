#include<bits/stdc++.h>
#define N 30
#define oo 99999

using namespace std;

struct Chessboard{
    int row;//which row should be processed
    int cost;//sum of weight
    short board[N][N];//1 for allow
};
int weight[N][N];
int row_up[N];//row upper bound and lower bound
int mymax,n;

void rec(Chessboard b){
    int i,j,k;
    Chessboard t;
    if(b.row==n){//the last row
        mymax=max(mymax,b.cost);
        return;
    }
    if(b.cost+row_up[b.row]<=mymax)return;//pruning
    for(int i=0;i<n;i++){
        if(b.board[b.row][i]){
            t=b;//structure copy
            t.board[t.row][i]=2;
            t.cost+=weight[t.row][i];
            t.row++;
                //mark the row
            for(j=t.row;j<n;j++){
                t.board[j][i]=0;
            }
                //mark the slash line
            j=t.row;
            k=i+1;
            while(j<n&&k<n){
                t.board[j][k]=0;
                j++;k++;
            }
                //mark the backslash line
            j=t.row;
            k=i-1;
            while(j<n&&k>=0){
                t.board[j][k]=0;
                j++;k--;
            }
            rec(t);
        }
    }
}
int main(void){
    //freopen("Branch_8Queen.in","r",stdin);
    int ncase;
    Chessboard init;
    cin>>ncase;
    while(ncase--){
        cin>>n;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>weight[i][j];
        mymax=0;

            //find the upper bound the row_max summed for row>=i

        for(int i=0;i<n;i++){
            row_up[i]=-oo;
            for(int j=0;j<n;j++){
                row_up[i]=max(row_up[i],weight[i][j]);
            }
        }
        for(int i=n-2;i>=0;i--)row_up[i]+=row_up[i+1];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)init.board[i][j]=1;//initialize
        init.row=0;init.cost=0;
        rec(init);
        if(mymax==0)cout<<"-1 ";
        else cout<<mymax<<" ";

            //find mymin

        mymax=-oo;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)weight[i][j]=-weight[i][j];
        for(int i=0;i<n;i++){
            row_up[i]=-oo;
            for(int j=0;j<n;j++){
                row_up[i]=max(row_up[i],weight[i][j]);
            }
        }
        for(int i=n-2;i>=0;i--)row_up[i]+=row_up[i+1];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)init.board[i][j]=1;//initialize
        init.row=0;init.cost=0;
        rec(init);
        if(-mymax==99999)cout<<"-1"<<endl;
        else cout<<-mymax<<endl;
    }
    return 0;
}
