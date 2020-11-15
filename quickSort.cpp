#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5;
 
void swap(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
 
int partition(int arr[], int p, int r)
{
	int pivot = arr[r];
	int i = p - 1;
	for(int j = p; j <r; j++)
	{
		if(arr[j] <= pivot)
		{
			i = i + 1;
			swap(arr, i, j);
 
		}
	}
	swap(arr[i+1], arr[r]);
	return i + 1;
}
 
void quickSort(int arr[], int p, int r)
{
	if(p < r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
	}
}
 
int main() {
 
	int n;cin>>n;
	int arr[MAX];
	for(int i=0;i<n;i++) cin>>arr[i];
	quickSort(arr, 0, n-1);
 
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
 
	cout<<"\n";
 
	return 0;
}
