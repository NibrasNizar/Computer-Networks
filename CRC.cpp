#include<iostream>
#include<string.h>
#define N strlen(g)
using namespace std;
char t[28],cs[28],g[]="10001000000100001";
int a,e,c;
void xo(){
    for(c = 1;c < N; c++)
    cs[c] = (( cs[c] == g[c])?'0':'1');
}
void crc(){
    for(e=0;e<N;e++)
        cs[e]=t[e];
    do{
        if(cs[0]=='1')
            xo();
        for(c=0;c<N-1;c++)
            cs[c]=cs[c+1];
        cs[c]=t[e++];
    }while(e<=a+N-1);
}
int main()
{
    cout<<"\nEnter data : ";
    cin>>t;
    cout<<".............................................";
    cout<<"\nGeneratng polynomial :";
    cout<<g;
    a=strlen(t);
    for(e=a;e<a+N-1;e++)
        t[e]='0';
    cout<<"\n----------------------------------------";
    cout<<"\nModified data is : ";
    cout<<t;
    cout<<"\n----------------------------------------";
    crc();
    cout<<"\nChecksum is :";
    cout<<cs;
    for(e=a;e<a+N-1;e++)
        t[e]=cs[e-a];
    cout<<"\n----------------------------------------";
    cout<<"\nFinal codeword is :"<<t;
    cout<<"\n----------------------------------------";
    cout<<"\nTest error detection 0(yes) 1(no)? : ";
    cin>>e;
    if(e==0)
    {
        do{
            cout<<"\nEnter the position where error is to be inserted : ";
            cin>>e;
        }while(e==0 || e>a+N-1);
        t[e-1]=(t[e-1]=='0')?'1':'0';
        cout<<"\n----------------------------------------";
        cout<<"\nErroneous data :"<<t;
    }
    crc();
    for(e=0;(e<N-1) && (cs[e]!='1');e++);
        if(e<N-1)
            cout<<"\nError detected\n\n";
        else
            cout<<"\nNo error detected\n\n";
            cout<<"\n----------------------------------------\n";
        return 0;
}
