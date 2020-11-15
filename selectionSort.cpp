#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e5;
 
void print(int arr[],int n)
{
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
 
	cout<<"\n";
}
 
void selection_sort(int arr[], int n){
 
	int minIndex = 0, i, j;
	for(i = 0; i < n; i++)
	{
		minIndex = i;
		for(j = i + 1; j < n; j++)
		{
			if(arr[minIndex] > arr[j])
				minIndex = j;
		}
		//print(arr,n);
		swap(arr[minIndex], arr[i]);
	}
}
 
 
 
int main() {
 
	int n; cin>>n;
	int arr[MAX];
	for(int i=0;i<n;i++) cin>>arr[i];
 
	cout<<"Array elements before sorting:\n";
	print(arr,n);
	selection_sort(arr,n);
	cout<<"Array elements after sorting:\n";
	print(arr,n);
	return 0;
}
