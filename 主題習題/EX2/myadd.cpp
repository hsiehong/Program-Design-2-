#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc,char *argv[]){
    float ans=0;
    for(int i=0;i<argc;i++){
        ans+=strtof(argv[i],NULL);//convert the content of argv into float
    }
    cout<<ans<<endl;
    return 0;
}
