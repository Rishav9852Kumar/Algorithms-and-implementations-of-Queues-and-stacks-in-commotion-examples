#include <iostream>

using namespace std;
void display(int arr[],int low,int high)
{
    int i;
    for(i=low;i<=high;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void conquering(int arr[],int low,int mid,int high )
{
    int i,j;
    int x1=mid-low+1;
    int x2=high-mid;
    int temp_arr1[x1];
    int temp_arr2[x2];

    for(i=0;i<x1;i++)
    {
        temp_arr1[i]=arr[low+i];
    }
    for(j=0;j<x2;j++)
    {
        temp_arr2[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    int index=low;
    while((j!=x2)&&(i!=x1))
    {
        if(temp_arr1[i]<=temp_arr2[j])
        {
            arr[index]=temp_arr1[i];
            i++;
        }else
        {
            arr[index]=temp_arr2[j];
            j++;
        }
        index++;
    }

     while(i<x1)
     {
         arr[index]=temp_arr1[i];
         index++;
         i++;
     }
     while(j<x2)
     {
         arr[index]=temp_arr2[j];
         index++;
         j++;
     }

}
void merge_sort(int arr[],int l,int h)
{
    int low=l,high=h,mid;

    if(low>=high)
    {
        cout<<"Return "<<arr[low]<<endl;
        return;
    }

    mid=low+(high-low)/2;
    cout<<"Before sorting "<<"from "<<arr[low]<<" to "<<arr[high]<<endl;
    display(arr,low,high);
    merge_sort(arr,low,mid);

    merge_sort(arr,mid+1,high);

    conquering(arr,low,mid,high);
    cout<<"After sorting "<<"from "<<arr[low]<<" to "<<arr[high]<<endl;
    display(arr,low,high);
}
int main()
{
    int n,i;
    cout << "Enter the size of your array :- ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements of your array :- ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    cout<<endl;
    merge_sort(arr,0,n-1);

    return 0;
}
