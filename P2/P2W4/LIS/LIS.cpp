#include<iostream>
#include<vector>


using namespace std;

void solve(int tcase){
    int t,left,right,mid;
    vector <int> last;
    for(int i=0;i<tcase;i++){
        cin>>t;
        if(last.empty()||last[last.size()-1]<t){
            last.push_back(t);
            continue;
        }
        //binary search,find the first>=t,range:[left,right]
        left=0,right=last.size()-1;
        while(left<right){
            mid=(left+right)/2;
            if(last[mid]<t)left=mid+1;
            else right=mid;
        }
        last[left]=t;
    }
    cout<<last.size()<<endl;
}
int main(void){
    int ncase,tcase;
    cin>>ncase;
    while(ncase--){
        cin>>tcase;
        solve(tcase);
    }
    return 0;
}
