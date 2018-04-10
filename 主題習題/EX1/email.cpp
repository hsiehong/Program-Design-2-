#include <bits/stdc++.h>
#define N 200
using namespace std;

struct Email {
    char name[N];
    char domain[N];
};

// sort by username
bool cmpn(Email &p,Email &q){
    return (strcmp(p.name,q.name)<0 ) ;// return true if p before q
}
// sort by domain
bool cmpd(Email p,Email q){
    return (strcmp(p.domain,q.domain)<0);// return true if p before q
}

void sol(int n) {
  Email addr[N];// declare a Email type named addr
  char line[N];// temp for the input
  char alpha[10]=".@_ "; // valid characters
  int j=0;
  for (int i=0;i<n;i++) {
    fgets(line,N,stdin);
    line[strlen(line)-1]='\0'; // overwrite the end of line
    char *s;
        // check invalid character
    for (s=line;*s;s++) {
        if (!isalpha(*s) && !isdigit(*s) && strchr(alpha,*s)==NULL)
            break;
    }
    if (*s) {
        cout<<"\t"<<" -> invalid character in address , not a valid address"<<*s<<endl;
        continue;
    }
    char *p=strchr(line,'@'); // find the first @
    if (p==NULL) {
        cout<<"\t"<<" -> lacking of @ , not a valid address"<<endl;
        continue;
    }
        // break line into two string separated by first @
    strncpy(addr[j].name,line,p-line);// p is the position of first @ , line is the first position of the input
    addr[j].name[p-line]='\0';// overwrite the end of the line
    strcpy(addr[j].domain,p+1);
        //check unvalid @ in domain part
    if (strchr(addr[j].domain,'@')!=NULL ) {
        cout<<"\t"<<" ->"<<" too many @ , not a valid address"<<endl;
        continue;
    }
        //check unvalid space in name and domain
    if(strchr(addr[j].name,' ')!=NULL||strchr(addr[j].domain,' ')!=NULL){
        cout<<"\t"<<" -> address with space , not a valid address"<<endl;
        continue;
    }
        //check if the username or domain is NULL
    if(strlen(addr[j].name)==0||strlen(addr[j].domain)==0){
        cout<<"\t"<<" -> have no username or domain , not a valid address"<<endl;
        continue;
    }
        //check invalid dot in username
    bool test=false;
    for(int a=0;a<strlen(addr[j].name)-2;a++){
        if(addr[j].name[a]=='.'&&addr[j].name[a+1]=='.'||addr[j].name[strlen(addr[j].name)-1]=='.'){
            cout<<"\t"<<" ->"<<" continuous dot in username or username end with dot"<<endl;
            test=true;break;
        }
    }
    if(test)continue;
        //check invalid dot in domain
    test=false;
    for(int a=0;a<strlen(addr[j].domain)-2;a++){
        if(addr[j].domain[a]=='.'&&addr[j].domain[a+1]=='.'||addr[j].domain[strlen(addr[j].domain)-1]=='.'){
            cout<<"\t"<<" -> continuous dot in domain or domain end with dot"<<endl;
            test=true;break;
        }
    }
    if(test)continue;

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

int main ()
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
