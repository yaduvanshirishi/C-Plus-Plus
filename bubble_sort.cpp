#include<iostream>
using namespace std;
int enter_numbers(int m);
int bubble_sort(int *arr,int n);
int swap(int *arr,int start,int end);
int enter_numbers(int m){
  int *p=new int[m];
  for(int i=0;i<m;i++){
    cin>>p[i];
  }
  bubble_sort(p,m);
  cout<<"SOrted numbers"<<endl;
  for(int i=0;i<m;i++){
    cout<<p[i]<<" ";
  }
  cout<<endl;
  return 0;
}
int swap(int *arr,int start,int end){
  int temp;
  temp=arr[start];
  arr[start]=arr[end];
  arr[end]=temp;
  return end;
}
int bubble_sort(int *arr,int n){
  for(int j=1;j<n;j++){
    for(int i=0;i<n-1;i++){
      if(arr[i]>arr[i+1])
          swap(arr,i,i+1);
        }
        //TO know sorting is going on line by line
        cout<<"SOrted numbers"<<j<<endl;
        for(int i=0;i<n;i++){
          cout<<arr[i]<<" ";
        }
        cout<<endl;
  }

    //swap(arr,startpos,minpos);
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
