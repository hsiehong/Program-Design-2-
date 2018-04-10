#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    int ncase,item,box[1000],tt,temp;
    cin>>ncase;
    while(ncase--){
        cin>>item;
        for(int i=0;i<item;i++)cin>>box[i];
        sort(box,box+item);
        temp=tt=box[0];
        for(int i=1;i<item;i++){
            temp+=box[i]+box[i-1];
            tt+=temp;
        }
        cout<<tt<<endl;
    }
}
