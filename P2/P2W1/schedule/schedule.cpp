#include<iostream>

using namespace std;

int main(void){
    int ncase,n,m,jobs[3000],mach[10],mymin,mymax;
    cin>>ncase;
    while(ncase--){
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>jobs[i];
        for(int i=0;i<m;i++)mach[i]=0;
        for(int i=0;i<n;i++){
            mymin=mach[0];
            for(int j=1;j<m;j++)mymin=(mach[j]<mymin)?mach[j]:mymin;
            for(int j=0;j<m;j++){
                if(mach[j]==mymin){
                    mach[j]+=jobs[i];
                    break;
                }
            }
        }
        mymax=mach[0];
        for(int i=1;i<m;i++)
            mymax=(mach[i]>mymax)?mach[i]:mymax;
        cout<<mymax<<endl;
    }
    return 0;
}
