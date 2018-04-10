#include <bits/stdc++.h>
#define N 100
using namespace std;
//five string function:strlen , strchr , strcpy , ctrncpy , strcmp

struct Email {
    char name[N];
    char domain[N];
};
// sort by username
bool cmpn(Email p,Email q){
    //cout<<p.name<<endl<<q.name<<endl;
    char a[100],b[100];
    for(int i=0;i<strlen(p.name);i++)a[i]=tolower(p.name[i]);
    for(int i=0;i<strlen(q.name);i++)b[i]=tolower(q.name[i]);
    //for(int i=0;i<strlen(p.name);i++)cout<<p.name[i];
    //return strcmp(p.name,q.name)<0;

    return strcmp(a,b)<=0;
}
// sort by domain
bool cmpd(Email p,Email q){
    char a[100],b[100];
    for(int i=0;i<strlen(p.domain);i++)a[i]=tolower(p.domain[i]);
    for(int i=0;i<strlen(q.domain);i++)b[i]=tolower(q.domain[i]);
    return strcmp(a,b)<=0;
    //return (strcmp(p.domain,q.domain))<0;// return true if p before q
}
// check function , judge the input is valid or not
int check(char line[N],Email addr[N],int j){
  char alpha[10]=".@_ "; // valid characters
    char *s;
        // check invalid character
    for (s=line;*s;s++) {
        if (!isalpha(*s) && !isdigit(*s) && strchr(alpha,*s)==NULL)
            return 1;
    }
    char *p=strchr(line,'@'); // find the first @
    if (p==NULL) {
        return 2;
    }
        // break line into two part separated by first @
    strncpy(addr[j].name,line,p-line);// p is the position of first @ , line is the head of the input
    addr[j].name[p-line]='\0';// overwrite the end of the line
    strcpy(addr[j].domain,p+1);
        //check unvalid @ in domain part
    if (strchr(addr[j].domain,'@')!=NULL ) {
        return 3;
    }
        //check unvalid space in name and domain
    if(strchr(addr[j].name,' ')!=NULL||strchr(addr[j].domain,' ')!=NULL){
        return 4;
    }
        //check if the username or domain is NULL
    if(strlen(addr[j].name)==0||strlen(addr[j].domain)==0){
        return 5;
    }
        //check if there are continuous dot or end with dot in username
    for(int a=0;a<strlen(addr[j].name)-2;a++){
        if(addr[j].name[a]=='.'&&addr[j].name[a+1]=='.'||addr[j].name[strlen(addr[j].name)-1]=='.'){
            return 6;
        }
    }
        //check if there are continuous dot or end with dot in domain
    for(int a=0;a<strlen(addr[j].domain)-2;a++){
        if(addr[j].domain[a]=='.'&&addr[j].domain[a+1]=='.'||addr[j].domain[strlen(addr[j].domain)-1]=='.'){
            return 7;
        }
    }
    return 0;
}

void sol(int n) {
  Email addr[N];// declare a Email type named addr
  char line[N];// temp for the input
  int j=0,t;
  for (int i=0;i<n;i++) {
    fgets(line,N,stdin);
    line[strlen(line)-1]='\0'; // overwrite the end of line
    t=check(line,addr,j);
    if(t==1){cout<<"\t"<<" -> invalid character in address , not a valid address"<<endl;continue;}
    else if(t==2){cout<<"\t"<<" -> lacking of @ , not a valid address"<<endl;continue;}
    else if(t==3){cout<<"\t"<<" ->"<<" too many @ , not a valid address"<<endl;continue;}
    else if(t==4){cout<<"\t"<<" -> address with space , not a valid address"<<endl;continue;}
    else if(t==5){cout<<"\t"<<" -> have no username or domain , not a valid address"<<endl;continue;}
    else if(t==6){cout<<"\t"<<" ->"<<" continuous dot in username or username end with dot"<<endl;continue;}
    else if(t==7){cout<<"\t"<<" -> continuous dot in domain or domain end with dot"<<endl;continue;}
    j++;
  }
    //sort by username
  sort(addr,addr+j,cmpn);
  cout<<endl<<"sort by username:"<<endl<<endl;;
  for(int a=0;a<j;a++){
    cout<<addr[a].name<<"@"<<addr[a].domain<<endl;
  }
    //sort by username+doamin
  sort(addr,addr+j,cmpd);
  cout<<endl<<"sort by username + domain:"<<endl<<endl;
  for(int a=0;a<j;a++){
    cout<<addr[a].name<<"@"<<addr[a].domain<<endl;
  }
}

int main (void)
{
    int n;
    while (1) {
        cin>>n;
        getchar();
        if (n==0) break;
        sol(n);
    }
    return 0;
}
