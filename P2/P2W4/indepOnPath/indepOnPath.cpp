#include<iostream>
#include<cstdio>
#define N 500

using namespace std;

int main(void){
    int ncase,t,max1,max2,temp1,temp2;
    while(1){
        scanf("%d",&ncase);
        if(ncase==0)break;
        max1=max2=0;//max1:��i���諸�̤j�Amax2:�����i�����̤j
        for(int i=0;i<ncase;i++){
            scanf("%d",&t);
            temp1=max2+t;
            temp2=(max1>max2)?max1:max2;
            max1=temp1;
            max2=temp2;
        }
        cout<<max(max1,max2)<<endl;
    }
    return 0;
}
