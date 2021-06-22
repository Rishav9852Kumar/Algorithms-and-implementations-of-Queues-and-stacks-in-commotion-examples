#include <iostream>//Bucket or Radix Sort using array //

using namespace std;
void display(int arr[],int n)
{
    cout<<"-----------------------------------"<<endl;
    int i;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
Count_Sort(int arr[],int n,int d)
{ int Count[10]={0,0,0,0,0,0,0,0,0,0};
  int i;
  int output[n];
  for(i=0;i<n;i++)
  {
     Count[(arr[i]/d)%10]++;
  }
    for(i=1;i<10;i++)
    {
        Count[i]=Count[i-1]+Count[i];
    }
    for(i=n-1;i>=0;i--)
    {
        output[Count[(arr[i]/d)%10]-1]=arr[i];
        Count[(arr[i]/d)%10]--;
    }
    for(i=0;i<n;i++)
    {
        arr[i]=output[i];
    }


}
void raddix_sort(int arr[],int n)
{
    int i,d;
    int Max=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>Max)
        {
            Max=arr[i];//Maximum element in the array //
        }
    }
    cout<<"Max = "<<Max<<endl;





   for(d=1;Max/d>0;d*=10)
   {
     cout<<"d = "<<d<<endl;
     Count_Sort(arr,n,d);
     display(arr,n);

   }

}

int main()
{
    int n,i;
    cout << "Enter the size of your array :- ";
    cin>>n;
    cout<<"\nEnter the elements of your array :- ";
    int arr[n];
     for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    raddix_sort(arr,n);

    return 0;
}
