#include <iostream>
using namespace std;
class Array
{
private:
    int *arr;
    int size;
    int length;
public:
    Array()
    {
        arr=new int[50];
        size=50;
        length=0;
    }
    Array(int sz)
    {
        size=sz;
        arr=new int[size];
        length=0;
    }
    void display();
    bool isFull();
    void swap(int &x,int &y);
    void append(int data);
    void insert(int index, int data);
    void insertAtLoc(int loc, int data);
    void insertAtBig(int data);
    void insertSort(int data );
    int deleteData(int index);
    int linearSearch(int key);
    int binarySearch(int key);
    int getData(int index);
    void setData(int index, int data);
    int max();
    int min();
    int sum();
    float avg();
    void reverse();
    void reverse1();
    void leftShift();
    void rotate();
    bool isSorted();
    Array* merge(Array &arr1);
    Array* setUnion(Array &arr1);
    Array* intersection(Array &arr1);
    Array* difference(Array &arr1);
    void missingElements();
    void missingElements1();
    void multiMissingElements();
    void multiMissingElements1();
    void duplicate();
    void duplicate1();
    void reArrange();
    void pair(int k);
    void pair1(int k);
    void pair2(int k);
    void minMax();
    void selectionSort();
    void bubbleSort();
    void insertionSort();
    int partition(int arr[],int start,int end);
    void quickSort(int arr[],int low,int high);
};