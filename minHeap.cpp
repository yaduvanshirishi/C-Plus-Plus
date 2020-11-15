#include<bits/stdc++.h> 
using namespace std; 
 
class MinHeap 
{ 
    int *arr; 
    int capacity; 
    int heap_size; 
 
	public: 
    // Constructor 
    	MinHeap(int capacity); 
 
    	void MinHeapify(int i); 
 
    	int parent(int i) { return (i-1)/2; } 
 
	    int left(int i) { return (2*i + 1); } 
 
    	int right(int i) { return (2*i + 2); } 
 
    	int extractMin(); 
 
    	void decreaseKey(int i, int val); 
 
    	int getMin() { return arr[0]; } 
 
    	void deleteKey(int i); 
 
    	void insertKey(int key); 
}; 
 
MinHeap::MinHeap(int c) 
{ 
    heap_size = 0; 
    capacity = c; 
    arr = new int[c]; 
} 
 
void MinHeap::insertKey(int key) 
{ 
    if (heap_size == capacity) 
    { 
        cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    } 
 
    // First insert the new key at the end 
    heap_size++; 
    int i = heap_size - 1; 
    arr[i] = key; 
 
    // Fix the min heap property if it is violated 
    while (i != 0 && arr[parent(i)] > arr[i]) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
} 
 
void MinHeap::decreaseKey(int i, int val) 
{ 
    arr[i] = val; 
    while (i != 0 && arr[parent(i)] > arr[i]) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
} 
 
// Method to remove minimum element (or root) from min heap 
int MinHeap::extractMin() 
{ 
    if (heap_size <= 0) 
        return INT_MAX; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return arr[0]; 
    } 
 
    // Store the minimum value, and remove it from heap 
    int root = arr[0]; 
    arr[0] = arr[heap_size-1]; 
    heap_size--; 
    MinHeapify(0); 
 
    return root; 
} 
 
void MinHeap::deleteKey(int i) 
{ 
    decreaseKey(i, INT_MIN); 
    extractMin(); 
} 
 
void MinHeap::MinHeapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && arr[l] < arr[i]) 
        smallest = l; 
    if (r < heap_size && arr[r] < arr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(arr[i], arr[smallest]); 
        MinHeapify(smallest); 
    } 
} 
 
int main() 
{ 
	int n; cin>>n;
	MinHeap h(n);
	int data;
    //MinHeap h(11);
    for(int i=0;i<n;i++)
    {
    	cin>>data;
    	h.insertKey(data);
    }
 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    //h.decreaseKey(2, 1); 
    //cout << h.getMin(); 
    return 0; 
} 
