#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    int ncase,edge[40],ck[3];
    while(1){
        cin>>ncase;
        if(ncase==0)break;
        for(int i=0;i<3;i++)ck[i]=0;
        for(int i=0;i<ncase;i++)cin>>edge[i];
        sort(edge,edge+ncase);
        int ok=0;
        for(int i=0;i<ncase-2;i++){
            for(int j=i+1;j<ncase-1;j++){
                for(int k=j+1;k<ncase;k++){
                    if(edge[i]+edge[j]>edge[k]){
                        if(edge[i]!=ck[0]||edge[j]!=ck[1]||edge[k]!=ck[2]){
                            ok++;
                            ck[0]=edge[i];ck[1]=edge[j];ck[2]=edge[k];
                        }
                    }
                }
            }
        }
        cout<<ok<<endl;
    }
    return 0;
}
