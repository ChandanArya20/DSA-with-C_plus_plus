#include "header.h"
int main()
{
    Array arr;
    int i;
    cin>>i;
    arr.append(23);
    arr.append(45);
    arr.append(90);
    arr.append(20);
    arr.append(12);

    arr.insert(1,24);
    arr.insert(4,44);
    
    
    // arr.minMax();
    
    arr.display();


    return 0;
}

void Array::display()
{
    cout<<"Length is "<<length<<endl;
    if (length != 0)
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
    }
}
bool Array::isFull()
{
    if (length == size)
        return true;
    else
        return false;
}
void Array::swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
void Array::append(int data)
{
    if (!isFull())
    {
        arr[length] = data;
        length++;
    }
}
void Array::insert(int index, int data)
{
    int i;
    if (index >= 0 && index <= length && !isFull())
    {
        for (i = length; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[i] = data;
        length++;
    }
}
void Array::insertAtLoc(int loc, int data)
{
    int i;
    if (loc >= 1 && loc <= length && !isFull())
    {
        for (i = length; i > loc - 1; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[i] = data;
        length++;
    }
}
void Array::insertAtBig(int data)
{
    int i;
    if (!isFull())
    {
        for (i = length; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[i] = data;
        length++;
    }
}
void Array::insertSort(int data) // First array should be sorted
{
    int i;
    if (!isFull())
    {
        for (i = length - 1; arr[i] > data; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = data;
        length++;
    }
}
int Array::deleteData(int index)
{
    int i;
    int x = arr[index];
    if (index >= 0 && index < length)
    {
        for (i = index; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        length--;
        return x;
    }
}
void Array::rotate()
{
    int i;
    int temp = arr[0];
    for (i = 1; i < length; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[i - 1] = temp;
}
bool Array::isSorted()
{
    int i;
    for (i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
Array *Array::merge(Array &arr1)
{
    int i, j, k;
    i = j = k = 0;
    Array *arrFinal = new Array;
    while (i < length && j < arr1.length)
    {
        if (arr[i] < arr1.arr[j])
            arrFinal->arr[k++] = arr[i++];
        else
            arrFinal->arr[k++] = arr1.arr[j++];
    }
    while (i < length)
        arrFinal->arr[k++] = arr[i++];

    while (j < arr1.length)
        arrFinal->arr[k++] = arr1.arr[j++];

    arrFinal->length =length + arr1.length;
    
    return arrFinal;
}
// void Array::reArrange()
// {
//     int i=0,j=arr->length-1;
//     int temp;
//     while(i<j)
//     {
//         while(arr->elements[i]<0)
//             i++;
//         while(arr->elements[j]>0)
//             j--;
//         if(i<j)
//         {
//             temp=arr->elements[i];
//             arr->elements[i]=arr->elements[j];
//             arr->elements[j]=temp;
//         }
//     }
// }
Array* Array::setUnion(Array &arr1)
{
    int i,j,k;
    i=j=k=0;
    Array *finalArr = new Array; 
    while(i<length && j<arr1.length)
    {
        if(arr[i]<arr1.arr[j])
            finalArr->arr[k++]=arr1.arr[i++];
        else if(arr1.arr[j]<arr[i])
            finalArr->arr[k++]=arr1.arr[j++];
        else
        {
            finalArr->arr[k++]=arr[i++];
            j++;
        }
    }
    while(i<length)
        finalArr->arr[k++]=arr[i++];
    while(j<arr1.length)
        finalArr->arr[k++]=arr1.arr[j++];
    finalArr->length=k;
    return finalArr;
}
Array* Array::intersection(Array &arr1)
{
    int i,j,k;
    i=j=k=0;
    Array *finalArr = new Array;
    while(i<length && j<arr1.length)
    {
        if(arr[i]<arr1.arr[j])
            i++;
        else if(arr1.arr[j]<arr[i])
            j++;
        else
        {
            finalArr->arr[k++]=arr[i++];
            j++;
        }
    }

    finalArr->length=k;
    return finalArr;

}
Array* Array::difference(Array &arr1)
{
    int i,j,k;
    i=j=k=0;
    Array *finalArr= new Array;
    while(i<length && j<arr1.length)
    {
        if(arr[i]<arr1.arr[j])
            finalArr->arr[k++]=arr[i++];

        else if(arr1.arr[j]<arr[i])
            j++;

        else
        {
            i++;
            j++;
        }
    }
    while(i<length)
        finalArr->arr[k++]=arr[i++];

    finalArr->length=k;
    return finalArr;
}
void Array::missingElements() 
{
    int i,sum=0;
    for(i=0;i<length;i++)
    {
        sum += arr[i];
    } 
    int n=arr[i-1];
    int s = n*(n+1)/2;
    cout<<"Missing element is "<<s-sum<<endl;
}
void Array::missingElements1()
{
    int diff=arr[0]-0;
    for(int i=0;i<length;i++)
    {
        if(arr[i]-i!=diff)   
        {
            cout<<"Missing element "<<i+diff<<endl;
            break;
        }
    }
}
void Array::multiMissingElements()
{
    int diff=arr[0]-0;
    cout<<"Missing elements are ";
    for(int i=0;i<length;i++)
    {
        if(arr[i]-i!=diff)   
        {
            while(diff<arr[i]+i)
            {
                cout<<diff+i<<" ";
            }
        }
    }
    cout<<endl;
}
void Array::multiMissingElements1()
{
    int h=this->max();
    int *temp=new int[h+1];
    temp={0};
    int i;
    cout<<"Missing elements are ";
    for(i =0;i<length;i++)
    {
        temp[arr[i]]++;
    }
    for(i =0;i<=h;i++)
    {
        if(temp[i]==0)
        {
            cout<<temp[i]<<" ";
        }
    }
    cout<<endl;
}
void Array::duplicate()
{
    int i,j;
    for (i=0;i<length-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            j=i+1;
            while(arr[j]==arr[i])
                j++;
            cout<<arr[i]<<" is appearing "<<j-i<<" times"<<endl; 
            i=j-1;
        }
    }
}
void Array::duplicate1()
{
    int h=this->max();
    int *temp=new int[h+1];
    temp={0};
    int i;
    for(i=0;i<length;i++)
    {
        temp[arr[i]]++;
    }
    for(i=0;i<h;i++)
    {
        if(temp[i]>1)
        {
            cout<<i<<" is appearing "<<temp[i]<<" times"<<endl;
        }
    }

}
void Array::pair(int k)
{
    int i,j;
    for(i=0;i<length-1;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(arr[i]+arr[j]==k)
            {
                cout<<arr[i]<<"+"<<arr[j]<<"="<<k<<endl;
            }
        }
    }
}
void Array::pair1(int k)
{
    int h=this->max();
    int *tmpArr=new int[h+1];
    tmpArr={0};
    int i,j;
    for(i=0;i<length;i++)
    {
        if(tmpArr[k-arr[i]]!=0)
        {
            cout<<" ";
        }
        else
            tmpArr[k-arr[i]]++;

    }
}
void Array::pair2(int k)
{
    int i=0,j=length-1;
    while(i<j)
    {
        if(arr[i]+arr[j]==k)
        {
            cout<<arr[i]<<"+"<<arr[j]<<"="<<k<<endl;
        }
    
        if(arr[i]+arr[j]<k)
            i++;
        else
            j++;
    }
    
}
void Array::minMax()
{
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<length;i++)
    {
        if(arr[i]<min)
            min=arr[i];
        else if(arr[i]>max)
            max=arr[i];

    }
    cout<<"Max is "<<max<<endl<<"Min is "<<min<<endl;
}
void Array::selectionSort()
{
    int i,j,minIndex;
    for(i=0;i<length-1;i++)
    {
        minIndex=i;
        for(j=i+1;j<length;j++)
        {
            if(arr[j]<arr[i])
                minIndex=j;
        }
        if(minIndex!=i)
        {
            swap(arr[minIndex],arr[i]); 
        }
    }
}
void Array::bubbleSort()
{
    int i, j, flag;
    for(i=0; i<length-1; i++)
    {
        flag=0;
        for(j=0; j<length-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
void Array::insertionSort()
{
    int i,j;
    for(i=1;i<length;i++)
    {
        int temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int partition(int arr[],int start,int end) 
{
		int pivot=arr[1];
		int i=start,j=end;
		do
		{
			while(arr[i]<=pivot) {
				i++;
			}
			while(arr[j]>pivot) {
				j--;
			}
			
			if(i<j) {
				int tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
		}while(i<j);
		
		int tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
		
		return j;
}
void quickSort(int arr[], int low,int high) 
{
		while(low<high) 
        {
			int p=partition(arr,low,high);
			quickSort(arr,low,p-1);
			quickSort(arr,p+1,high);
		}
}