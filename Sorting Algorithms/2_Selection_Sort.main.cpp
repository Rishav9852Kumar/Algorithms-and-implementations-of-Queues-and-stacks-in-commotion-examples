#include <iostream>//Insertion sort on array//

using namespace std;
void display(int arr[],int n)
{
    int i;
    cout<<"\norder of the elements of your array = ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap_(int arr[],int i,int j)
{  cout<<"Swapping "<<arr[i]<<" with "<<arr[j]<<endl;
    int temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;

}
void insert_sort(int arr[],int n)
{
    int i,j,min_;
    for(i=0;i<n;i++)
    {  min_=i;
        for(j=i;j<n;j++)
        {
            if(arr[min_]>arr[j])
            {
                min_=j;
            }
        }
        if(min_!=i){//This condition ensures that we do not perform unnecessary swaps of same element;//
        display(arr,n);
        swap_(arr,i,min_);

        cout<<"\n-  -  -  -  -  -"<<endl;
        }

    }
}
int main()
{
    int i,n;
    cout << "Enter the size of your array :- ";
   cin>>n;
   int arr[n];
   cout<<"\nEnter the elements of your array :- ";
   for(i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   insert_sort(arr,n);
   cout<<"\nAfter insertion sort ";
   display(arr,n);
    return 0;
}
