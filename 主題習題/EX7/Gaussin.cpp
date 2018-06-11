#include<bits/stdc++.h>
#define N 100
#define ERR 0.0001

using namespace std;

int n;
double coe[N][N];//original matrix
double t[N][N];//back up of original matrix
double res[N];//result matrix

//show matrix
show(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%10f ",coe[i][j]);
        printf("%10f\n",res[i]);
    }
}
    //列交換
myswap(int i){
    bool ck=false;
    for(;i<n;i++){
        if(i==n-1)//最後一行則不用處理
            continue;
        else{
            for(int j=i+1;j<n;j++){
                if(coe[j][j]!=0&&coe[j][i]!=0){
                    for(int a=0;a<n;a++)for(int b=0;b<n;b++)swap(coe[i][a],coe[j][a]);
                    swap(res[i],res[j]);break;ck=true;
                }
            }
            if(ck)break;
        }
    }
}
    //判斷是否整列為0
bool isAllZero(int i){
    bool ck=true;
    for(int j=0;j<n;j++){
        if(abs(coe[i][j]-0)>ERR){//可以容忍的誤差
            ck=false;break;
        }
    }
    if(ck){return true;}
    else {return false;}
}
    //驗算
void computing(){
    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<n;j++){
            //cout<<"res:"<<res[i]<<"  "<<"coe:"<<t[i][j]<<endl;
            sum+=res[j]*t[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
    return;
}
    //compute determinant with dimension 3
void computeD(){
    double ans,slh,bkslh;
    slh=(t[0][0]*t[1][1]*t[2][2]+t[1][0]*t[2][1]*t[0][2]+t[2][0]*t[0][1]*t[1][2]);
    bkslh=(t[0][2]*t[1][1]*t[2][0]+t[0][0]*t[1][2]*t[2][1]+t[2][2]*t[0][1]*t[2][1]);
    cout<<slh-bkslh<<endl<<endl;
}
int main(int argc,char *argv[]){
    ifstream fin;
    fin.open(argv[1]);
    if(!fin)cerr<<"no such file !"<<endl;
    int i,j;
    double temp;
    while(1){
        fin>>n;
        if(n==0)break;
        bool D=false;//determinant 是否為0，是為true
        for(i=0;i<n;i++)for(j=0;j<n;j++){
            fin>>coe[i][j];
            t[i][j]=coe[i][j];
        }
        for(i=0;i<n;i++)fin>>res[i];
            //某行或列全為0
        for(int i=0;i<n;i++){
            if(isAllZero(i)){
                D=true;break;
            }
                //斜對角線上為0，則列互換
            if(coe[i][i]==0){
                myswap(i);
            }
            temp=1/coe[i][i];
            for(int j=0;j<n;j++)coe[i][j]*=temp;
            res[i]*=temp;
            for(int j=0;j<n;j++){
                if(j==i)continue;//同一行列不用運算
                if(coe[j][i]==0)continue;
                temp=coe[j][i]/coe[i][i];
                for(int k=0;k<n;k++){
                    coe[j][k]-=temp*coe[i][k];
                }
                res[j]-=temp*res[i];
            }
        }
        show();
        if(!D){
            computing();
            cout<<"determinant:";
            computeD();
        }
        else {cout<<"determinant is 0"<<endl<<endl;}
    }
    fin.close();
    return 0;
}
