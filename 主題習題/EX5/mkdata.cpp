#include<bits/stdc++.h>

using namespace std;

int main(void){
    freopen("test.txt","w",stdout);
    int n;
    while(1){
        cin>>n;
        if(n==0)break;
        srand(time(NULL));
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<rand()%100<<" ";
        }
        cout<<endl;
    }
    return 0;
}
