/**
 *
 *
    1
   /  \
  2    3
 / \ 
4   5
 
 *
 */
 
#include <iostream>
#include <queue>
using namespace std;
 
struct treeNode{
	struct treeNode *left;
	int data;
	struct treeNode *right;
};
 
struct treeNode *getNode(int data)
{
	struct treeNode* tmp = new treeNode();
	tmp -> data = data;
	tmp ->left = NULL;
	tmp ->right = NULL;
 
	return tmp;
}
 
void levelOrder(struct treeNode *root)
{
	if(root == NULL) return;
	queue<treeNode *> q;
	q.push(root);
 	cout<<"Binary Tree Nodes using Level Order Traversal :";
	while(!q.empty())
	{
		treeNode *curr = q.front();
		cout<<curr->data<<" ";
		if(curr->left!=NULL) q.push(curr->left);
		if(curr->right!=NULL) q.push(curr->right);
		q.pop();
	}
}
 
int main() {
 
	struct treeNode *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
 
	levelOrder(root);
	cout<<"\n";
 
	return 0;
}

