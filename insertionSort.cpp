#include <iostream>
using namespace std;
 
const int MAX = 1e5;
 
void print(int arr[], int n){
 
	for(int i =0; i < n; i++) 
		cout<< arr[i]<<" ";
 
	cout<<"\n";
}
 
void insertion_sort(int arr[], int n){
 
	int pos, nextpos;
	for(int pos = 0; pos < n; pos++){
 
		nextpos = pos;
		while(nextpos > 0 && arr[nextpos] < arr[nextpos - 1]){
			swap(arr[nextpos], arr[nextpos - 1]);
			nextpos = nextpos - 1;
		}
 
	}
 
}
 
int main() {
 
	int n; cin>>n;
	int arr[MAX];
 
	for(int i = 0;i <n;i++) cin>> arr[i];
 
	cout<<"Array Elements before Insertion Sorting : ";
	print(arr, n);
 
	insertion_sort(arr, n);
 
	cout<<"Array Elements after Insertion Sorting : ";
	print(arr, n);
	return 0;
}
