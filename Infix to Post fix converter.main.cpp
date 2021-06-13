#include <iostream>//A program to convert Infix expression to Postfix Expression//
#include<string.h>//With four Accepting operators '+','-','*','/','(',')'//

using namespace std;
int push(char *arr,int top,char e)
{
    if(top==-1)
    {
        top++;
        arr[top]=e;
    }else
    {
        top++;
        arr[top]=e;
    }
    return top;
}

char pop(char *arr,int top)
{
   return arr[top];
}
int peek(char* arr,int top)
{
  if ( arr[top]=='(')
  {
      return 0;
  }else if ( arr[top]=='/')
  {
      return 4;
  }else if (arr[top]=='*')
  {
    return 3;
  }else if(arr[top]=='+')
  {
      return 1;
  }else if(arr[top]=='-')
  {
      return 1;
  }
}
int value(char k)
{
    if ( k==')')
  {
      return 0;
  }if ( k=='/')
  {
      return 4;
  }else if (k=='*')
  {
    return 3;
  }else if(k=='+')
  {
      return 1;
  }else if(k=='-')
  {
      return 1;
  }
}

int main()
{   int i;
    char express[100];
    cin>>express;
    int n=strlen(express);
    cout<<"Size of your string "<<express<<" = "<<n<<endl;
    char res[n];
    int k=0;
    for(i=0;i<n;i++)
    {
        cout<<express[i]<<endl;
    }
     char arr[n];
     int top=-1;
    for(i=0;i<n;i++)
    {
        if(express[i]=='(')
        {
            top=push(arr,top,express[i]);
        }else if(express[i]==')')
        {
            while(peek(arr,top)!=0)
            {
                res[k]=pop(arr,top);
                top--;
                k++;
            }
            pop(arr,top);
            top--;
        }else if((express[i]!='+')&&(express[i]!='-')&&(express[i]!='*')&&(express[i]!='/'))
        {
            res[k]=express[i];
            k++;
        }else if((express[i]=='+')||(express[i]=='-')||(express[i]=='*')||(express[i]=='/'))
        {
            if(top==-1)
            {
               top= push(arr,top,express[i]);
            }else
            {
                if(peek(arr,top)<value(express[i]))
                {

                   top= push(arr,top,express[i]);
                }else
                {
                    while(peek(arr,top)>=value(express[i]))
                    {
                       res[k]=pop(arr,top);
                        top--;
                       k++;
                    }
                    top = push(arr,top,express[i]);
                }
            }
        }


        }
             if(top!=-1)
        {
            while(top!=-1)
            {
                res[k]=pop(arr,top);
                top--;
                k++;
            }

    }
    cout<<"--------------------"<<endl;
        for(i=0;i<k;i++)
    {
        if((res[i]!='(')&&(res[i]!=')')){
        cout<<res[i];

        }
    }
    cout<<"\n";

    return 0;
}
