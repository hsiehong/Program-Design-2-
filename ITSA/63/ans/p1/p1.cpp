#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main(void){
    int ncase,m,d;
    cin>>ncase;
    while(ncase--){
        cin>>m>>d;
        switch(m){
            case 1:
                if(d>=1&&d<=20)cout<<"Capricorn"<<endl;
                else cout<<"Aquarius"<<endl;
                continue;
            case 2:
                if(d>=1&&d<=18)cout<<"Aquarius"<<endl;
                else cout<<"Pisces"<<endl;
                continue;
            case 3:
                if(d>=1&&d<=20)cout<<"Pisces"<<endl;
                else cout<<"Aries"<<endl;
                continue;
            case 4:
                if(d>=1&&d<=20)cout<<"Aries"<<endl;
                else cout<<"Taurus"<<endl;
                continue;
            case 5:
                if(d>=1&&d<=21)cout<<"Taurus"<<endl;
                else cout<<"Gemini"<<endl;
                continue;
            case 6:
                if(d>=1&&d<=21)cout<<"Gemini"<<endl;
                else cout<<"Cancer"<<endl;
                continue;
            case 7:
                if(d>=1&&d<=22)cout<<"Cancer"<<endl;
                else cout<<"Leo"<<endl;
                continue;
            case 8:
                if(d>=1&&d<=23)cout<<"Leo"<<endl;
                else cout<<"Virgo"<<endl;
                continue;
            case 9:
                if(d>=1&&d<=23)cout<<"Virgo"<<endl;
                else cout<<"Libra"<<endl;
                continue;
            case 10:
                if(d>=1&&d<=23)cout<<"Libra"<<endl;
                else cout<<"Scorpio"<<endl;
                continue;
            case 11:
                if(d>=1&&d<=22)cout<<"Scorpio"<<endl;
                else cout<<"Sagittarius"<<endl;
                continue;
            case 12:
                if(d>=1&&d<=22)cout<<"Sagittarius"<<endl;
                else cout<<"Capricorn"<<endl;
                continue;
            default:continue;
        }
    }
    return 0;
}


