#include<iostream>
#define N 10000

using namespace std;

main(){
    int n,m,dir,p;
    int cell[N],bk[N][2];
    while(1){
        cin>>n>>m;
        if(n==0)break;
        for(int i=0;i<n;i++)cin>>cell[i];

        while(m--){
            for(int a=0;a<N;a++)for(int b=0;b<2;b++)bk[a][b]=0;
            cin>>p>>dir;
            int i=0;
            while(1){
                i++;
                if(bk[p][0]!=0&&bk[p][1]==dir)break;
                bk[p][0]=i,bk[p][1]=dir;
                if(cell[p]<0)dir=-dir;
                p=p+dir*(cell[p]<0?-cell[p]:cell[p]);
                if(p>=n||p<0)break;
            }
            if(p>=n)cout<<"Forward"<<endl;
            else if(p<0)cout<<"Backward"<<endl;
            else cout<<"Cycle "<<i-(bk[p][0])<<endl;
        }
    }
}
