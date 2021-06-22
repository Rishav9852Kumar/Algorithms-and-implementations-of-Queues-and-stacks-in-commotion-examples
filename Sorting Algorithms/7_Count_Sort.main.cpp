#include <iostream>//Counting sort using array with k(range of output )=10//

using namespace std;

int main()
{ int n,i;
    int Count[10]={0,0,0,0,0,0,0,0,0,0};
    cout << "enter the size of your array :- ";
    cin>>n;
    int arr[n];
    cout<<endl;
    cout<<"Enter your elements in range of 0 to 9 :- ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        Count[arr[i]]=Count[arr[i]]+1;
    }
    for(i=1;i<10;i++)
    {
        Count[i]=Count[i-1]+Count[i];
    }
    for(i=0;i<10;i++)
    {
        cout<<Count[i]<<" ";
    }
    int j=0;
    i=0;
    int k = Count[j];
    while(i<n)
    {
        while(k!=0)
      {
          arr[i]=j;
          i++;
          k--;
      }
      if(k==0)
      {
          j++;
          k=Count[j]-Count[j-1];
      }


    }
    cout<<"\n"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
