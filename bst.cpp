/*
Beginning with an empty binary search tree with complexity analysis, 
Construct binary search tree by inserting the values in the order given. After constructing a binary tree –
 
 i. Insert new node  
 ii. Find number of nodes in longest path 
 iii. Minimum data value found in the tree  
 iv. How to delete a node from BST with the help of all three cases  
 v. Search a value 
*/

#include <iostream>
#include <climits>
using namespace std;


class Node{
	
	public:
		int data;
		Node *left;
		Node *right;
};

Node *root;

Node *getNode(int node_value)
{
	Node *temp = new Node;
	temp -> data = node_value;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void insert(int node_value)
{
	/*
	case 1 - when tree is empty 
		simply create a node and insert to root;
	case 2 - when value is less or equal than root and left pointer points to null
		create a node
		just insert to left
	case 3 - when value is greater than root and right pointer points to null
		create a node 
		just insert to right
	case 4 - when both pointers are not null
		if value less than root 
			traverse to left subtree
		if value greater than or equal than root
			traverse to right subtree
	*/
	
	Node *temp = getNode(node_value);
	
	if (root == NULL)
	{
		root = temp;
		return;
	}
	Node *curr_ptr = root;
	while(curr_ptr!=NULL)
	{
		if(node_value <= curr_ptr->data && curr_ptr -> left == NULL)
		{
			curr_ptr->left = temp;
			return;
		}
		else if(node_value > curr_ptr->data && curr_ptr -> right == NULL)
		{
			curr_ptr -> right = temp;
			return;
		}
		else if(node_value <= curr_ptr->data && curr_ptr -> left != NULL)
			curr_ptr = curr_ptr -> left;
		else
			curr_ptr = curr_ptr -> right;
	}
}

void inorder(Node *local_root)
{
	if(local_root == NULL) return;
	inorder(local_root->left);
	cout<<local_root->data<<" ";
	inorder(local_root->right);
}

int maxLengthBST(Node *local_root)
{
	if(local_root == NULL) return 0;
	
	else 
	{
	
		int leftNodes = maxLengthBST(local_root->left);
		int rightNodes = maxLengthBST(local_root->right);
	
		if (leftNodes > rightNodes) return leftNodes + 1;
		else return rightNodes + 1;
	}
	
}

int minimum(int x, int y, int z) {
	int min = x; /* assume x is the smallest */

	if (y < min) { /* if y is smaller than min, assign y to min */
		min = y;
	} /* end if */

	if (z < min) { /* if z is smaller than min, assign z to min */
		min = z;
	} /* end if */

	return min; /* max is the largest value */
}

int minData(Node *local_root)
{
	if(local_root == NULL) return INT_MAX;
	else
	{
		int minValue = local_root->data;
		
		minValue = minimum(minValue, 
						   minData(local_root->left), 
						   minData(local_root->right));
						   
		return minValue;
	}
}

void search(Node *lRoot, int key)
{
	if(lRoot == NULL)
	{
		cout<<"ELement not found\n";
		return;
	}
	Node *curr_ptr = lRoot;
	while(curr_ptr!=NULL)
	{
		if(curr_ptr->data == key)
		{
			cout<<"\nElement found\n";
			return;
			//return curr_ptr;
		}
		else if(curr_ptr->data > key)
			curr_ptr = curr_ptr->left;
		else
			curr_ptr = curr_ptr->right;
	}
	cout<<"\nElement not found\n";
	return ;
}

Node *findMin(Node *ptr)
{
	Node *curr = ptr;
	while(curr && curr -> left !=NULL)
		curr = curr -> left;
	
	return curr;
}

Node* deleteNode(Node *lRoot,int value)
{
	if(lRoot == NULL) return lRoot;
	if(value < lRoot -> data)
		lRoot -> left = deleteNode(lRoot -> left, value);
	else if(value > lRoot -> data)
		lRoot -> right = deleteNode(lRoot -> right, value);
	else
	{
		if(lRoot -> left == NULL)
		{
			Node *temp = lRoot -> right;
			free(lRoot);
			return temp;
		}
		else if(lRoot -> right == NULL)
		{
			Node *temp = lRoot -> left;
			free(lRoot);
			return temp;
		}
		
		//Inorder successor (min value in right subtree)
		Node *temp = findMin(lRoot->right);
		
		lRoot -> data = temp -> data;
		
		lRoot -> right = deleteNode(lRoot -> right, temp -> data);
	}
	return lRoot;
}

int main() {
	
	int total_nodes; cin>>total_nodes;
	root = NULL;
	
	for(int i = 0;i<total_nodes; i++)
	{
		int node_val; cin>>node_val;
		insert(node_val);
		//insert(5);
		//insert(6);
		//insert(1);
	}
	
	cout<<"The inorder traversal of BST is :\n";
	inorder(root);
	
	cout<<"\nThe number of nodes in longest path of BST is :"<<
	maxLengthBST(root);
	
	cout<<"\nMinimum Data value found in the tree is :"<<
	minData(root);
	
	int value;
	cout<<"\nEnter which element you want to delete :";
	cin>> value;
	
	//search(root, value);
	
	deleteNode(root, value);
	cout<<"\nThe inorder traversal of BST after deletion is :\n";
	inorder(root);
	
	cout<<"\nEnter the element you want to search for?;";
	cin>>value;
	search(root, value);
	
	
	return 0;
}
