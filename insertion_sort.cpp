#include<iostream>
using namespace std;
int display(int *arr,int num);
int insertion_sort(int *arr,int num);
int insertion_sort(int *arr,int num){
  int value,hole,i;
  for(i=1;i<num;i++){
    //here hole is used as a next position element
    value = arr[i];
    hole=i;
    while(hole>0 && arr[hole-1]>value){
      arr[hole]=arr[hole-1];
      hole=hole-1;
    }
    arr[hole]=value;
  }
}
int display(int *arr,int num){
  for(int i=0;i<num;i++)
  cout<<arr[i]<<" ";
  cout<<endl;
}
int main(){
  int n;
  cout<<"Enter number of elements in an array : "<<endl;
  cin>>n;
  int *arr=new int[n];
  cout<<"Enter elements of array : "<<endl;
  for(int i=0;i<n;i++)
  cin>>arr[i];
  cout<<"Array elements are : "<<endl;
  display(arr,n);
  insertion_sort(arr,n);
  cout<<"Sorted elements are : "<<endl;
  display(arr,n);
  return 0;
}
