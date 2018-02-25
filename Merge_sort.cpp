/*
<How Merge-Sort Algoithm Works>
____________________________________
1-Break problem into disjoint parts
2-Solve Each Part Seperately
3-Combine the Solutions Effectiently

<Merging>
________________________________________

1-Combine two Sorted lists A,B into C
2-If A is empty ,Copy B into C
3-If B is empty ,Copy A into C
4-Else compare firt element of A and B and move the smaller of the two into C
5-Repeat until all elements in A and B have been moved
*/

#include<iostream>
#include<cstdlib>
using namespace std;

//Declaration of Three functions
void printfxn(int A[], int size);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int nL = m - l + 1;
    int nR =  r - m;

    /* two arrays */
    int L[nL], R[nR];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < nL; i++)
        L[i] = arr[l + i];
    for (j = 0; j < nR; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // first subarray index
    j = 0; // second subarray index
    k = l; // Initial index of merged subarray
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any remaining */
    while (i < nL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any remaining*/
    while (j < nR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        //because Total r+1 elements avoids overflow
        /*********/
        int m = l+(r-l)/2;
        /*********/
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void printfxn(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<"\n";
}

int main()
{
    int n,i;
    cout<<"Number of elements you want in array : "<<endl;
    cin>>n;
    //Array block allocating By Dynamically i mean Dynamic memory Allocation
    int *arr=new int[n];
    //Enter all elements in Array
    cout<<"Enter values : "<<endl;
    for(i=0;i<n;i++)
    cin>>arr[i];

    cout<<"Entered elements are : "<<endl;
    printfxn(arr, n);
    //MergeSort function calling
    
    mergeSort(arr, 0, n - 1);
    cout<<"Sorted Elements are : "<<endl;
    printfxn(arr, n);

    return 0;
}
