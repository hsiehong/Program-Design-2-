#include<iostream>
#include<string.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<math.h>
#define N 15

using namespace std;

double integrate(double (*fun)(double),double left,double right,double inter){
    double sum=0.0;
    for(double i=left;i<=right;i+=inter){
        sum+=fun(i);
    }
    return sum*inter;
}
double getcoe(){
    double t;static bool fg=true;
    if(fg){printf("input three coefficients of the function \"x^3-x^2+x+3\" for x^3,x^2 and x , if not , input one \"1 1 1\":\n");fg=false;}
    scanf("%lf",&t);
    return t;
}
double mypoly(double a){
    static bool flag=true;
    static double coe[3];
    if(flag){
        for(int i=0;i<3;i++)coe[i]=getcoe();
    }
    flag=false;
    return a*a*a*coe[0]-a*a*coe[1]+a*coe[2]+6;
}
int main(void){
    char fun[N];
    bool ck;
    double inter,left,right,ans,a,b;
    while(scanf("%s %lf %lf %lf",fun,&a,&b,&inter)!=EOF){
        left=(a<b)?a:b;right=(a>b)?a:b;
        ck=true;
        if(strcmp(fun,"sin")==0)ans=integrate(sin,left,right,inter);
        else if(strcmp(fun,"cos")==0)ans=integrate(cos,left,right,inter);
        else if(strcmp(fun,"tan")==0)ans=integrate(tan,left,right,inter);
        else if(strcmp(fun,"asin")==0)ans=integrate(asin,left,right,inter);
        else if(strcmp(fun,"acos")==0)ans=integrate(acos,left,right,inter);
        else if(strcmp(fun,"atan")==0)ans=integrate(atan,left,right,inter);
        else if(strcmp(fun,"sinh")==0)ans=integrate(sinh,left,right,inter);
        else if(strcmp(fun,"cosh")==0)ans=integrate(cosh,left,right,inter);
        else if(strcmp(fun,"tanh")==0)ans=integrate(tanh,left,right,inter);
        else if(strcmp(fun,"x^3-x^2+x+3")==0)ans=integrate(mypoly,left,right,inter);
        else {cerr<<"no such function"<<endl;ck=false;}
        if(ck)printf("%f\n",ans);
    }
    return 0;
}
