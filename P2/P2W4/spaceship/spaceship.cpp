#include<iostream>
#include<math.h>
#include<cstdlib>
#define N 1000
#define mybegin 1000
using namespace std;

int main(){
    int ncase,status_a,status_b,a[N],b[N],x1,x2,y1,y2;
    while(1){
        cin>>ncase;
        if(ncase==0)break;
        for(int i=0;i<ncase;i++)cin>>a[i]>>b[i];
        status_a=abs(a[0]-mybegin);//�O����a�һݪ��̤p��q
        status_b=abs(b[0]-mybegin);//�O����b�һݪ��̤p��q
            //�O����i-1��i�һݪ���q�t�A���^����C���I���̤p��q
        for(int i=1;i<ncase;i++){
            x1=status_a+abs(a[i]-a[i-1]);
            x2=status_b+abs(a[i]-b[i-1]);
            y1=status_b+abs(b[i]-b[i-1]);
            y2=status_a+abs(b[i]-a[i-1]);
            status_a=min(x1,x2);
            status_b=min(y1,y2);
        }
        cout<<min(status_a,status_b)<<endl;
    }
    return 0;
}
