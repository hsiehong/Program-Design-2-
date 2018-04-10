#include<iostream>
#define N 10000

using namespace std;

int main(void){
    int n,m,cell[N],bk[N][2],p,dir;
    while(1){
        cin>>n>>m;
        if(n==0)break;
        for(int i=0;i<n;i++)cin>>cell[i];
        while(m--){
            cin>>p>>dir;
            for(int i=0;i<n;i++)for(int j=0;j<2;j++)bk[i][j]=0;
            int k=0;
            while(1){
                k++;
                if(bk[p][0]!=0&&bk[p][1]==dir)break;
                bk[p][0]=k;bk[p][1]=dir;
                if(cell[p]<0)dir=-dir;
                p=p+dir*(cell[p]<0?-cell[p]:cell[p]);
                if(p>=n||p<0)break;
            }
            if(p>=n)cout<<"Forward"<<endl;
            else if(p<0)cout<<"Backward"<<endl;
            else cout<<"Cycle "<<k-bk[p][0]<<endl;
        }
    }
    return 0;
}
