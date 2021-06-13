#include <iostream>//Program that can evaluate upto to strings of operators and operand//
#include<string.h>//for eg :- 123+-,562*+,4325*-+,546+*493/+*,
using namespace std;
char pop(char *arr,int top)
{

        return arr[top];

}
void push(char *arr,int top,char ch)
{
    top++;
    arr[top]=ch;
}
int main()
{
    cout<<"\nEnter Your postfix Expression :- ";
    int i,n;
    char c[100];
    int top =-1;
    cin>>c;
    cout<<"\n";
    n=strlen(c);
    for(i=0;i<n;i++)
    {
        cout<<c[i]<<endl;
    }
    int res;
    int  result=0;
    int  result2=0;
    char arr[n];
    int m=0;
    for(i=0;i<n;i++)
    {  cout<<"case : "<<i <<endl;
       cout<<"-----------------------------------------------------------"<<endl;
        int a,b;
        if((c[i]=='+')||(c[i]=='-')||(c[i]=='/')||(c[i]=='*'))
        { if(m==0){
             a=(int)(pop(arr,top))-48;
             top--;
            }else{
            a=result;
            }
            cout<<"\na = "<<a<<endl;
             if(top==-1){
             b=result2;

             }else{
              b=(int)(pop(arr,top))-48;
               top--;
             }
              cout<<"\nb = "<<b<<endl;
            char k=c[i];

                res=0;
            if(k=='+')
            {   cout<<"\ncharacter = "<<c[i]<<endl;
                res=a+b;
                cout<<"\n("<<b<<"+("<<a<<")) = "<<res<<endl;
            }else if(k=='-')
            {   cout<<"\ncharacter = "<<c[i]<<endl;
                res=b-a;
                cout<<"\n("<<b<<"-("<<a<<")) = "<<res<<endl;
            }else if (k=='/')
            {   cout<<"\ncharacter = "<<c[i]<<endl;
                res=(b/a);
                cout<<"("<<b<<"/("<<a<<")) = "<<res<<endl;
            }else
            {   cout<<"\ncharacter = "<<c[i]<<endl;
                res=(a*b);
                cout<<"\n("<<b<<"*("<<a<<")) = "<<res<<endl;
            }
           result=res;
           m=1;

        }else
        {

            push(arr,top,c[i]);
            top++;
            m=0;
            result2=result;


        }
    }
        cout<<"---------------------------\n"<<endl;
        cout<<" Your result = "<<result<<endl;
        cout<<"---------------------------\n"<<endl;

    return 0;
}
