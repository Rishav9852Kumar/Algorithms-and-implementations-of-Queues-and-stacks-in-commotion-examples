#include <bits/stdc++.h>//Bubble-sort using array //

using namespace std;

void display(int arr[],int n)//Display function//
{
int i;
cout<<"\nYour current elements order = ";
for(i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
}
void swap_(int arr[],int j)//Swap function to swap two elements in array//
{
    cout<<"Swapping "<<arr[j]<<" with "<<arr[j+1]<<endl;
    int temp;
    temp=arr[j+1];
    arr[j+1]=arr[j];
    arr[j]=temp;
}
void quick_sort(int arr[],int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {  int swapping =0;
      for(j=0;j<n-1;j++)
      {
          cout<<"\nComparing "<<arr[j]<<" with "<<arr[j+1]<<endl;
          if(arr[j]>arr[j+1])
          {
              swap_(arr,j);
              swapping++;
          }else
          {
              cout<<"No swapping required\n"<<endl;
          }
          display(arr,n);
          cout<<"\n-  -  -  -  -  -  -"<<endl;
      }
      if(swapping==0)//This pointer is used to check if any swaps occurred in a particular cycle //
      {
          break;  //If no swaps occurred means the array is already sorted and we break out of the loop //
      }
  }

}

int main()
{
int n,i;
cout<<"Enter the size of your array :- ";
cin>>n;
int arr[n];
cout<<"\nEnter the elements of your array :- ";
for(i=0;i<n;i++)
{
    cin>>arr[i];
}
quick_sort(arr,n);
cout<<"\nAfter Sorting  ";

display(arr,n);
    return 0;
}
