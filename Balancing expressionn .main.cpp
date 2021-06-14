#include <iostream>//Application of a stack //Balancing symbol//Symbol stack//
#include<string.h>
using namespace std;
int push(char*arr,int top,char ch)
{
    top++;
    arr[top]=ch;
    return top;
}
char peek(char*arr,int top)
{
    char c;
    c=arr[top];
    return c;
}
int main()
{
    int i,n,top=-1,balanced=1;
    char str[100];
    char ch;
    cout << "Enter the expression :- ";
    cin>>str;
    n=strlen(str);
    cout<<"\n";
    for(i=0;i<n;i++)
    {
       cout<<str[i]<<" ";
    }
    cout<<"\n";
    char arr[n];
    for(i=0;i<n;i++)
    {
        if((str[i]=='(')||(str[i]=='[')||(str[i]=='{'))
            {
                top=push(arr,top,str[i]);
            }else if((str[i]==')')||(str[i]==']')||(str[i]=='}'))
            {
                ch=peek(arr,top);

                if((ch=='(')&&(str[i]==')'))
                {
                    top--;
                }else if((ch=='[')&&(str[i]==']'))
                {
                    top--;
                }else  if((ch=='{')&&(str[i]=='}'))
                {
                    top--;
                }else
                {
                    balanced=0;
                }
            }
    }
    if(top!=-1)
    {
        balanced=0;
    }
    if(balanced==0)
    {
        cout<<"\nYour expression is Unbalanced Because of unpaired  :- "<<endl;
        while(top!=-1)
        {
            cout<<arr[top]<<endl;
            top--;
        }

    }else
    {
        cout<<"\nYour expression is Balanced"<<endl;
    }
    return 0;
}
