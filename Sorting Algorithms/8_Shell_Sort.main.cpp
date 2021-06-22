#include <iostream>

using namespace std;
void display(int arr[],int n)
{
    int i;
    cout<<"\nYour current array elements order = ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap_(int *a,int *b)
{
    cout<<"\nSwapping value "<<*a<<" to the position of "<<*b<<endl;
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void insertion_sort(int arr[],int n)
{
    int i,j,tem;
    for(i=1;i<n;i++)
    { tem=arr[i];
      cout<<"Current key element = "<<tem<<endl;
     for(j=i-1;j>=0;j--)
        {

            cout<<"\nComparing "<<tem<<" with "<<arr[j]<<endl;
            if(arr[j]>tem)
            {
                cout<<"\nMoving value "<<arr[j]<<" to the position of "<<arr[j+1]<<endl;
                arr[j+1]=arr[j];
                display(arr,n);
                cout<<"\n-  -  -  -  -  -  -"<<endl;
            }
            else
            {
                cout<<"No more comparison required\n"<<endl;//To exit out of loop when we reach an element which is smaller than our key //
                break;
            }

        }
        if(arr[j+1]!=tem){
         cout<<"\nReturning the value "<<tem<<" to the position "<<j+1<<" and replacing with "<<arr[j+1]<<endl;
          arr[j+1]=tem;
          display(arr,n);

            cout<<"-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -"<<endl;
        }

     }
}
void shell_short(int arr[],int n)
{ int i;
    int distance =n/2;
    while(distance!=1){
            cout<<"For distance = "<<distance<<endl;
    for(i=0;i+distance<n;i=i+distance)
    {
        if(arr[i]>arr[i+distance])
        {
            swap_(&arr[i],&arr[i+distance]);
        }
    }
    distance=distance/2;
    }
    insertion_sort(arr,n);

}

int main()
{ int n,i;
    cout << "Enter the size of your array :- ";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
    cin>>arr[i];
    }
    shell_short(arr,n);

    return 0;
}
