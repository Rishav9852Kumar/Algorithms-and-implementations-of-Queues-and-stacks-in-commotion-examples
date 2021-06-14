#include <iostream>//Linear search using array//

using namespace std;

int main()
{
    int i,n,exit=0,k,result;
    cout<<"Enter size of your list :- ";
    cin>>n;
    int arr[n];
    cout << "\nenter the elements in your list :- " << endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    while(exit==0){
            result=0;
    cout<<"\nEnter the element you want to search :- ";
    cin>>k;
    for(i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            cout<<"\nYour element ' "<<k<<" 'found at position "<<i+1<<endl;
            result=1;
        }

    }
    if(result==0)
    {

            cout<<"\nYour element"<< k <<"not found in the list "<<endl;
            result=0;

    }
    cout<<"\nTo exit press 1 ,else press 0 "<<endl;
    cin>>exit;
    }
    return 0;
}
