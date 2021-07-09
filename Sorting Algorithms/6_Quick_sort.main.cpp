#include <bits/stdc++.h>//Quick sort using array //

using namespace std;
void display(int arr[],int k,int n)//Display Function//
{
    int i;
    for(i=k;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap_(int arr[],int a,int b)//swap function //
{
    int temp;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void quick_sort_using_first_element(int arr[],int low,int high )//Quick sort using first value as pivot//
{                                   //Done //
    display(arr,low,high);

  if(high>low)
    {int l,h;
    l=low;
    h=high;
    int k=l;
    int pivot = arr[l];//keeping constant value of pivot //
    while(l<h)
    {
        while(arr[l]<=pivot)//Incrementing the l value until stuck on an element greater than pivot//
        {
            l++;

        }
        while(arr[h]>pivot)//Decrementing the value of h until stuck on an element smaller than pivot//
        {
            h--;

        }
        if(l<h){
        swap_(arr,l,h);//Swapping one smaller and one greater number at a time as compared to pivot value //
        }
        }
        //This means we have swapped our pivot with an element which is equal to pivot in value //
        swap_(arr,h,low);//so to make the quick sort an stable sorting algorithm we swap that pivot back to maintain its order//

        k=h;//Adjusting mid as mid should be the position of which all left element should be smaller and right element should be greater//




    display(arr,low,high);
    quick_sort_using_first_element(arr,low,k-1);
    cout<<"- - - - "<<endl;
    quick_sort_using_first_element(arr,k+1,high);

}
}
void quick_sort_using_mid_element(int arr[],int low,int high )//Quick sort using middle value as pivot//
{                                              //Done//
    display(arr,low,high);

  if(high>low)
    {int l,h;
    l=low;
    h=high;
    int k;
    int mid=low+(high-low)/2;//Taking mid value as pivot //
    k=mid;
    int pivot = arr[mid];//keeping constant value of pivot //
    while(l<h)
    {
        while(arr[l]<=pivot)//Incrementing the l value until stuck on an element greater than pivot//
        {
            l++;
        }
        while(arr[h]>pivot)//Decrementing the value of h until stuck on an element smaller than pivot//
        {
            h--;

        }
        if(l<h){

       swap_(arr,l,h);//Swapping one smaller and one greater number at a time as compared to pivot value //

        }
        }

       if(l>mid){//This means we have swapped our pivot with an element which is equal to pivot in value //

        swap_(arr,h,k);//so to make the quick sort an stable sorting algorithm we swap that pivot back to maintain its order//
       }
        mid=h;//Adjusting mid as mid should be the position of which all left element should be smaller and right element should be greater//





    display(arr,low,high);
    quick_sort_using_mid_element(arr,low,mid-1);
    cout<<"- - - - "<<endl;
    quick_sort_using_mid_element(arr,mid+1,high);

}
}
void quick_sort_using_last_element(int arr[],int low,int high )//Quick sort using last value as pivot//
{                                     //Done//
    display(arr,low,high);

  if(high>low)
    {int l,h;
    l=low;
    h=high;
    int k=h;//Taking mid value as pivot //
    int pivot = arr[high];//keeping constant value of pivot //
    while(l<h)
    {
        while(arr[l]<pivot)//Incrementing the l value until stuck on an element greater than pivot//
        {
            l++;

        }
        while(arr[h]>=pivot)//Decrementing the value of h until stuck on an element smaller than pivot//
        {
            h--;

        }
        if(l<h){
        swap_(arr,l,h);//Swapping one smaller and one greater number at a time as compared to pivot value //

        }
    }
        //This means we have swapped our pivot with an element which is equal to pivot in value //
        swap_(arr,l,high);//so to make the quick sort an stable sorting algorithm we swap that pivot back to maintain its order//

        k=l;//Adjusting mid as mid should be the position of which all left element should be smaller and right element should be greater//




    display(arr,low,high);
    quick_sort_using_last_element(arr,low,k-1);
    cout<<"- - - - "<<endl;
    quick_sort_using_last_element(arr,k+1,high);

}
}
void quick_sort_using_random_element(int arr[],int low,int high )//Quick sort using random value as pivot//
{
    display(arr,low,high);

  if(high>low)
    {int l,h;
    l=low;
    h=high;
    int k=(low+rand()%(high-low));//Taking mid value as pivot //
    int pivot = arr[k];//keeping constant value of pivot //
    cout<<"pivot = "<<pivot<<" index = "<<k<<endl;
    while(l<h)
    {
        while(arr[l]<=pivot)//Incrementing the l value until stuck on an element greater than pivot//
        {
            l++;

        }
        while(arr[h]>pivot)//Decrementing the value of h until stuck on an element smaller than pivot//
        {
            h--;

        }
        if(l<h){
        swap_(arr,l,h);//Swapping one smaller and one greater number at a time as compared to pivot value //

        }
    }
       if(l>k){
        swap_(arr,h,k);
       }
        k=h;//Adjusting mid as mid should be the position of which all left element should be smaller and right element should be greater//




    display(arr,low,high);
    quick_sort_using_random_element(arr,low,k-1);
    cout<<"- - - - "<<endl;
    quick_sort_using_random_element(arr,k+1,high);

}
}

int main()
{
    int n,i,j,choice;
    cout << "Enter the size of your array :- ";
    cin>>n;
    cout<<endl;
    int arr[n];
    cout<<"Enter the elements of your unsorted array :- ";
    for(i=0;i<n;i++)
    {
    cin>>arr[i];
    }
    cout<<endl;
    cout<<"\n-----------------------------------------------------------------\n"<<endl;
    cout<<"To do quick sort using first element as pivot, press:- 1"<<endl;
    cout<<"To do quick sort using middle element as pivot, press:- 2"<<endl;
    cout<<"To do quick sort using last element as pivot, press:- 3"<<endl;
    cout<<"To do quick sort using random element as pivot, press:- 4"<<endl;
    cout<<"\nEnter your choice :- ";
    cin>>choice;
    int low=0;
    int high=n-1;
    switch (choice){
    case 1:{ cout<<"Doing quick sort using first element as pivot"<<endl;
    quick_sort_using_first_element(arr,low,high);
    }break;
    case 2:{cout<<"Doing quick sort using mid element as pivot "<<endl;
        quick_sort_using_mid_element(arr,low,high);
    }break;
    case 3:{cout<<"Doing quick sort using last element as pivot "<<endl;
        quick_sort_using_last_element(arr,low,high);
    }break;
    case 4:{cout<<"Doing quick sort using random element as pivot "<<endl;
        quick_sort_using_random_element(arr,low,high);
    }break;
    default:{cout<<"Enter the correct choice "<<endl;}
}


    cout<<"Your Final sorted array = ";
    display(arr,0,n-1);
    return 0;
}
