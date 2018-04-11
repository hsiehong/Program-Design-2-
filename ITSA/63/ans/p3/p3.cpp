#include<iostream>
#include<cstdio>

using namespace std;

int main(void)
{
    int y,act;
    double a,b,c,height,tall;
    while(1)
    {
        cin>>tall>>height>>y;
        a=height*41.2/tall;
        b=height*tall/634.4;
        c=height*0.4;
        if(y>28)
        {
            if(y>30)
            {
                b+=(0.15*((y-30)/5));
                c+=(0.25*((y-28)/2));
            }

            else
            {
                c+=(0.25*(y-28)/2);
            }
        }
        cin>>act;
        if(act==0)printf("%.2lf %.2lf %.2lf\n",a,b,c);
        if(act==-1)
        {
            printf("%.2lf %.2lf %.2lf\n",a,b,c);
            break;
        }
    }
    return 0;
}


