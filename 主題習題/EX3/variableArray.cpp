#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define N 50

using namespace std;

struct Data{
    char name[16];
    short int age;
    char sex[8];
};
enum Sex{female,male};
int main(void){
    int num=0,memo=1,l,i,j,age;
    char input[N],*tok;
    bool ck;
//    printf("%d\n",sizeof(Data));
    Data *arr=(Data*)malloc(memo*sizeof(Data));//initialize
    while(gets(input)!=NULL){
        num++;ck=false;
            //先檢查這筆資料進來時會不會滿，會的話先realloc，若滿了在realloc可能會造成crash
        if(num==memo){
            memo*=2;
            arr=(Data*)realloc(arr,sizeof(Data)*memo);
            ck=true;//for output
        }
        l=strlen(input);
        char h=input[0];
        char t[N],tsex[N];
        //copy name
        for(i=1,j=0;i<l;i++){
            if(input[i]==h)break;
            t[j++]=input[i];
        }
        t[j]='\0';
        //analyze age
        for(i=j;i<l;i++){
            if(isdigit(input[i])){
                if(isdigit(input[i+1])&&isdigit(input[i+2])){
                    age=(input[i]-'0')*100+(input[i+1]-'0')*10+(input[i+1]-'0');
                }
                else if(isdigit(input[i+1])){
                    age=(input[i]-'0')*10+(input[i+1]-'0');
                }
                else age=(input[i]-'0');
                j=i;
                break;
            }
        }
        //analyze sex
        for(i=j;i<l;i++){
            if(isalpha(input[i])){
                if(input[i]=='F'||input[i]=='f'){
                    strcpy(tsex,"female");
                }
                else strcpy(tsex,"male");
                break;
            }
        }
        //copy into struct
        strcpy(arr[num].name,t);
        arr[num].age=age;
        strcpy(arr[num].sex,tsex);
        //show the result of analyze
        printf("Name:%s , Age:%d , Sex:%s\n",arr[num].name,arr[num].age,arr[num].sex);
        if(ck){
            printf("====================================================================================\n");
            printf("queue/stack full, allocate double size %d\n",memo*sizeof(Data));
            printf("====================================================================================\n");
        }
    }
    free(arr);//return memory to system
    return 0;
}
