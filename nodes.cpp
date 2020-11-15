#include <iostream>
using namespace std;
 
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
 
int leafCount(struct Node *root){
 
	if(root == NULL)
		return 0;
	else if(root->left == NULL && root->right == NULL)
		return 1;
	else
		return leafCount(root->left) + leafCount(root->right);
}
 
int totalCount(struct Node *root){
 
	if(root == NULL)
		return 0;
	else if(root->left == NULL && root->right == NULL)
		return 1;
	else
		return 1 + totalCount(root->right) + totalCount(root->left);
};
 
struct Node *getNode(int data){
	struct Node *tmp = new Node();
	tmp ->data = data;
	tmp ->left = NULL;
	tmp -> right = NULL;
	return tmp;
}
 
int main() {
 
	struct Node *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
 
	int l, t;
	l = leafCount(root);
	t = totalCount(root);
	cout<<"Number of leaf nodes :"<<l<<"\n";
	cout<<"Number of internal nodes :"<<t - l;
	cout<<"\n";
	return 0;
}

