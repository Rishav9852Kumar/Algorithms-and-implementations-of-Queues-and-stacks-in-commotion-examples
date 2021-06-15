#include <iostream>//Binary search is faster than Linear search but ,
                  //its major drawback is it's requirement of sorted array ,thus it need a sorting function too while implementation //
using namespace std;

int bin_search(int *arr,int low,int high,int x)//Recursive function for binary search //
{ while(low<high){
    int mid =(low+high)/2;
    if(arr[mid]==x)
    {
        return mid;
    }else if(arr[mid]>x)
    {
       return bin_search(arr,low,mid-1,x);
    }else if (arr[mid]<x)
    {
        return bin_search(arr,mid+1,high,x);
    }
                 }
}

int main()
{ int n,i,low,high,x,result,Choice=1;
    cout << "Enter the Size of your array :- ";
    cin>>n;
    if(n<=0)
    {   cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        cout<<"your Array size is invalid press the correct size please which must be greater than 0 ";
        cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        cout<<"\nsize :- ";
        cin>>n;
        cout<<"\n";

    }
    int arr[n];
    cout<<"\nEnter the elements of your array in ascending order :- "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    while(Choice!=0){

    cout<<"\nEnter the element you want to search :- ";
    cin>>x;
    cout<<"\n";
    low=0;
    high=n-1;
    result=bin_search(arr,low,high,x);
    if(result>-1)
    {
        cout<<"\nYour element "<<x<<" fount in the list at position "<<result+1<<endl;
    }else
    {
        cout<<"\nYour element not found in the list "<<endl;
    }
    cout<<"\n---------------------------------------"<<endl;
    cout<<"\nTo exit press 0 else to continue with another search press 1 :- ";
    cin>>Choice;
    }
    cout<<"\n Thanks and Bye :)"<<endl;
    return 0;
}
