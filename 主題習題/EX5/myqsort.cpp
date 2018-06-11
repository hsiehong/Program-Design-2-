#include<bits/stdc++.h>

using namespace std;

struct Stru{
    int a,b;
};
void myswap(void *p,void *q,size_t nsize){
    if(p==q)return;
    char *t=new char[nsize];
    memcpy(t,p,nsize);
    memcpy(p,q,nsize);
    memcpy(q,t,nsize);
    delete [] t;
    return;
}
//normal case,smaller to bigger
int mycmp1(void *p,void *q){
    return *((int*)p)-*((int*)q);
}

//normal case,bigger to smaller
int mycmp2(void *p,void *q){
    return *((int*)q)-*((int*)p);
}
//structure case,first num smaller to bigger
int mycmp3(void *p,void *q){
    Stru p1=*(Stru*)p,p2=*(Stru*)q;
    return p1.a-p2.a;
}

//structure case,second num smaller to bigger
int mycmp4(void *p,void *q){
    Stru p1=*(Stru*)p,p2=*(Stru*)q;
    return p1.b-p2.b;
}

void mysort(void *start , int n , size_t nsize , int (*cmp)(void*,void*)){
    if(n<=1)return;
    char *i,*piv,*np;
    char *base=(char*)start;
    piv=base+(n-1)*nsize;
    myswap(piv , base+(rand()%n)*nsize , nsize);//move random pivot to the last
    np=base;//record the number of the left side
    for(i=base;i<piv;i+=nsize){
        if(cmp(i,piv)<=0){
            myswap(i,np,nsize);
            np+=nsize;
        }
    }
    myswap(piv,np,nsize);//np is the medium now
    int num=(np-base)/nsize;//num is the number of the left side
    mysort(base,num,nsize,cmp);//sort left part
    mysort(np+nsize,n-num-1,nsize,cmp);//sort right part
    return;
}

int main(void){
    cin.tie(0);
    srand(time(NULL));
    ifstream fin;
    ofstream fout;
    fin.open("t10_in.txt");
    fout.open("t10_out.txt");
    if(!fin){
        cerr<<"No such file"<<endl;
        return 0;
    }
    int n,m;
    while(1){
        fin>>n;
        if(n==0)break;
        int *base=new int[n];
        for(int i=0;i<n;i++)fin>>base[i];
            //sort from smaller to bigger
        mysort(base,n,sizeof(int),mycmp1);
        for(int i=0;i<n;i++)fout<<base[i]<<" ";
            fout<<endl;
            //sort from bigger to smaller
        mysort(base,n,sizeof(int),mycmp2);
        for(int i=0;i<n;i++)fout<<base[i]<<" ";
            fout<<endl<<endl;
        delete [] base;
                        //-------------------deal with struct sort--------------------
//            fin>>n;
//            if(n==0)break;
//            Stru *str=new Stru[n];
//            for(int i=0;i<n;i++)fin>>str[i].a>>str[i].b;
//            mysort(str,n,sizeof(Stru),mycmp3);
//            fout<<"-----------------first number smaller sort-------------------"<<endl;
//            for(int i=0;i<n;i++){fout<<str[i].a<<" "<<str[i].b<<endl;}
//
//            fout<<"-----------------second number smaller sort-------------------"<<endl;
//            mysort(str,n,sizeof(Stru),mycmp4);
//            for(int i=0;i<n;i++){fout<<str[i].a<<" "<<str[i].b<<endl;}
//            fout<<endl;
//            delete [] str;
    }
    fin.close();
    fout.close();
    return 0;
}
