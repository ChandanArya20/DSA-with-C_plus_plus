#include <iostream>
using namespace std;
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swapAlternate(int arr[],int size)
{
    int i;
    for(i=0;i<size-1;i+=2)
    {
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);
        }
    }
}
int main()
{
    int arr[8]={2,8,9,4,3,6,1};
    swapAlternate(arr,7);
    print(arr,7);
    return 0;
}