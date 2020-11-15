#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5;
 
int linear_search(int arr[], int n, int element)
{
	int position = 0; 
	int i = 0;
	while((arr[i]!=element) && (i < n))
	{
		position++;
		i++;
	}
	if(i < n) return position;
	else return -1;
}
 
int binary_search(int arr[], int n, int element)
{
	sort(arr, arr+n);
	int low = 0, high = n - 1;
 
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(arr[mid] == element) return mid;
		else if(arr[mid] > element) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
 
int main() {
 
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int arr[MAX];
		for(int i=0;i<n;i++) cin>>arr[i];
 
		int element;
		cout<<"Enter the element which you want to search:"<<endl;
		cin>>element;
 
		int pos = linear_search(arr, n, element);
 
		//Assuming position starting from 1
		if (pos == -1) cout<<"Not Found"<<endl;
		else
			cout<<"Found, Using Linear Search at Position:"<<pos + 1<<endl;
 
		//Assuming position starting from 1
		pos = binary_search(arr, n, element);
		if (pos == -1) cout<<"Not Found"<<endl;
			cout<<"Found, Using Binary Search at Position:"<<pos + 1<<endl;
	}
	return 0;
}
