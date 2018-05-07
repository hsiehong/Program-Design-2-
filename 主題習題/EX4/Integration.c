//#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//using namespace std;

double integrate(double (*fun)(double),double left,double right,double inter){
    double sum=0.0,i;
    for(i=left;i<=right;i+=inter){

        sum+=fun(i);
    }
    return sum*inter;
}

int main(void){
    char fun[15];
    double inter,left,right,ans,a,b;
    double (*ptr)(double);
    while(1){
        scanf("%s %lf %lf %lf",fun,&a,&b,&inter);
        left=(a<b)?a:b;
        right=(a>b)?a:b;
//        printf("func : %s\n",fun);
//        if(fun=="sin")ptr=sin;
//        if(fun=="cos")ptr=cos;
        //ptr=&fun;

//        printf("ptr : %lf\n",*ptr);
        ans=integrate(sin,left,right,inter);
        printf("%d\n",ans);
    }
    return 0;
}
