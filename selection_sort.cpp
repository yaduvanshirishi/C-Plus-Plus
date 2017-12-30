#include<iostream>
using namespace std;
int enter_numbers(int m);
int selection_sort(int *arr,int n);
int swap(int *arr,int start,int end);
int enter_numbers(int m){
  int *p=new int[m];
  for(int i=0;i<m;i++){
    cin>>p[i];
  }
  selection_sort(p,m);
  cout<<"Sorted numbers"<<endl;
  for(int i=0;i<m;i++){
    cout<<p[i]<<" ";
  }
  return 0;
}
int swap(int *arr,int start,int end){
  int temp;
  temp=arr[start];
  arr[start]=arr[end];
  arr[end]=temp;
  return end;
}
int selection_sort(int *arr,int n){
  for(int startpos=0;startpos<n;startpos++){
    int minpos=startpos;
    for(int j=minpos+1;j<n;j++){
      if(arr[minpos]>arr[j]){
        minpos=j;
      }
    }
    swap(arr,startpos,minpos);
  }
  return 0;
}
int main(){
  int n;
  cout<<"How many numbers : ";
  cin>>n;
  cout<<"Enter Numbers :"<<endl;
  enter_numbers(n);
  return 0;
}
