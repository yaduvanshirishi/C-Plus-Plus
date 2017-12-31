#include<iostream>
#include<cstdlib>
using namespace std;
struct Node {
  int data;
  Node *next;
};
struct Node *head;
int insert(int x);
int print();

int insert(int x){
  Node* temp=(Node*)malloc(sizeof(struct Node));
  temp->data=x;
  temp->next=head;
  head=temp;
}

int print(){
  struct Node* temp=head;
  cout<<"The list is : "<<endl;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
int main(){
  int x,n;
  head = NULL;
  cout<<"Enter numbers of nodes want for list ??"<<endl;
  cin>>n;
  for(int i=0;i<n;i++){
    cout<<"Enter elements : "<<i+1<<endl;
    cin>>x;
    insert(x);
    print();
  }
  return 0;

}
