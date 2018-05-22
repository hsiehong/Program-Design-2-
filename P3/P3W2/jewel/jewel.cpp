#include<iostream>
typedef long long LL;

using namespace std;

int main(void){
    LL n,r,l;
    const int N=200;
    while(1){
        cin>>n;
        LL mymap[200][200];
        LL dp[200][200];
        if(n==0)break;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>mymap[i][j];
        r=l=0;
        for(int i=0;i<n;i++){
            l+=mymap[i][0];
            dp[i][0]=l;
            r+=mymap[0][i];
            dp[0][i]=r;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+mymap[i][j];
            }
        }
        cout<<dp[n-1][n-1]<<endl;
    }
    return 0;
}
