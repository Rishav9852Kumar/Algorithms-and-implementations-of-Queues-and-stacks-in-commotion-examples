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
void conquering(int arr[],int low,int mid,int high )//This merging operatio starts only whenn we would have divided arrays into multiple arrays of size one each//
{
    int i,j;              //{ Here low=4,mid=4,high=5 } //
    int x1=mid-low+1;     //{ x1=4-4+1=1}//
    int x2=high-mid;      //{ x2=5-4=1}
    int temp_arr1[x1];   //Creating an array of 1 element//
    int temp_arr2[x2];   //Creating an array of 1 element//

    for(i=0;i<x1;i++)
    {
        temp_arr1[i]=arr[low+i];   // Now transfering the array items from {index low to mid in first arr1 created}
    }
    for(j=0;j<x2;j++)
    {
        temp_arr2[j]=arr[mid+1+j]; // Now transfering the array items from {index mid+1 to high in second arr2 created}
    }
    i=0;
    j=0;
    int index=low;
    while((j!=x2)&&(i!=x1))  // NOW THIS LOOP WILL COMPARRE THE SORTED ELEMENTS OF TWO ARRAYS INTO A COMBINED ARRAY AND RETURNING THAT SORTED COMBINED ARRAY AS RESULT //
    {
        if(temp_arr1[i]<=temp_arr2[j])  // if element of arr1 is less than elemts of arr2 //
        {
            arr[index]=temp_arr1[i];    //index of combined array will have arr1 as its element at { index position =index }
            i++;
        }else                          // if element of arr2 is less than elemts of arr1 //  
        {
            arr[index]=temp_arr2[j];     //index of combined array will have arr2 as its element at { index position =index }
            j++;
        }
        index++;
    }

     while(i<x1)                       //if all the elements of one sub array is consumed then fill the remaining positions 
     {                                //with the left elements in the subarray//
         arr[index]=temp_arr1[i];
         index++;
         i++;
     }
     while(j<x2)
     {
         arr[index]=temp_arr2[j];
         index++;
         j++;
     }                                     // NOW THE ARRAY WHICH WAS TAKES AS INPUT FROM INDEX  low=4, high=5 HAVE BEEN SORTED //

}
void merge_sort(int arr[],int l,int h)  // Merge sort function (Basically here we are dividing the given array elements into arrays of half sizes //
{                                       // until the size of each dived array is not one )//
    int low=l,high=h,mid;  //Fuction takes array base address ,lower index(l) ,Higher index(h) and declaring a variable mid//

    if(low>=high)  //If our function is called with lower index (low)> highest index(high) {That means either }
    {
        cout<<"Return "<<arr[low]<<endl;
        return;
    }

    mid=low+(high-low)/2;//Mid index is mid of the input index given to the fuction (eg, if low=4 and high =9, then the mid index will be =4+(9-4)/2=6)//
    cout<<"Before sorting "<<"from "<<arr[low]<<" to "<<arr[high]<<endl;
    display(arr,low,high);   //{Let the INitial array array be { 9,7,67,3,5,32,12,45,65,76,1,0 }{Here low=0,high=11,mid=0+(11-0)/2 =5 }
    merge_sort(arr,low,mid);  //Now we again are again dividing the first half part into another set of two halfes { here we are merge_sorting for(low=0,high=mid=5)}

    merge_sort(arr,mid+1,high);  //Now we again are again dividing the Second half part into another set of two halfes { here we are merge_sorting for(low=mid=6,high=11)} //

                                                // ABOVE LOOP CONTINUES UNTIL THE SIZE OF EACH DIVIDED ITEM IS 1 //
                            // THE CONQUIRING THE THE FUNCTION WHICH STARTS COMBINES FROM SINGLE UNITS BACK TO THE ARRAY OF INITIAL SIZE//
    conquering(arr,low,mid,high);  //  {WHEN WE REACH HERE our low=0,high=11}
    cout<<"After sorting "<<"from "<<arr[low]<<" to "<<arr[high]<<endl;
    display(arr,low,high);
}
int main()
{
    int n,i;
    cout << "Enter the size of your array :- ";
    cin>>n;  //Taking the no of elements in the array to be sorted from user//
    int arr[n];
    cout<<"\nEnter the elements of your array :- ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i]; //Taking each element one by one //

    }
    cout<<endl;
    merge_sort(arr,0,n-1);  //Calling Merge sort function//

    return 0;
}
