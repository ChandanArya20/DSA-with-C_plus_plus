#include <iostream>
using namespace std;
int main()
{
    int m=3, n=4;
    int** mat=new int*[m];
    for(int i=0;i<m;m++)
    {
        mat[i]=new int[n];
    }
    cout<<"RAM"<<endl;
    return 0;
}