#include <bits/stdc++.h>
using namespace std;

enum COLOR
{
    RED,
    BLACK
};

class Node
{
public:
    int val;
    COLOR color;
    Node *left, *right, *parent;

    Node(int val) : val(val)
    {
        parent = left = right = NULL;
        // Node is created during insertion
        // By default Node is RED
        color = RED;
    }
    // check if node is left child of parent
    bool isOnLeft()
    {
        return this == parent->left;
    }

    Node *uncle()
    {
        // If no parent or grandparent, then no uncle
        if (parent == NULL or parent->parent == NULL)
            return NULL;

        if (parent->isOnLeft())
            // uncle on right
            return parent->parent->right;
        else
            // uncle on left
            return parent->parent->left;
    }

    // returns pointer to sibling
    Node *sibling()
    {
        // sibling null if no parent
        if (parent == NULL)
            return NULL;

        if (isOnLeft())
            return parent->right;

        return parent->left;
    }

    // moves node down and moves given node in its place
    void moveDown(Node *locParent)
    {
        if (parent != NULL)
        {
            if (isOnLeft())
                parent->left = locParent;
            else
                parent->right = locParent;
        }
        locParent->parent = parent;
        parent = locParent;
    }

    bool hasRedChild()
    {
        return (left and left->color == RED) or
               (right and right->color == RED);
    }
};

class RBTree
{
    Node *root;

    // left rotates the given node
    void leftRotate(Node *pt)
    {
        // new parent will be node's right child
        Node *pt_right = pt->right;

        pt->right = pt_right->left;

        if (pt->right != NULL)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_right;

        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;

        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void rightRotate(Node *pt)
    {
        // new parent will be node's left child
        Node *pt_left = pt->left;

        pt->left = pt_left->right;

        if (pt->left != NULL)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_left;

        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;

        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    void swapColors(Node *x1, Node *x2)
    {
        COLOR temp;
        temp = x1->color;
        x1->color = x2->color;
        x2->color = temp;
    }

    void swapValues(Node *u, Node *v)
    {
        int temp;
        temp = u->val;
        u->val = v->val;
        v->val = temp;
    }

    // fix red red at given node
    void fixRedRed(Node *x)
    {
        // if x is root color it black and return
        if (x == root)
        {
            x->color = BLACK;
            return;
        }

        // initialize parent, grandparent, uncle
        Node *parent = x->parent, *grandparent = parent->parent,
             *uncle = x->uncle();

        if (parent->color != BLACK)
        {
            if (uncle != NULL && uncle->color == RED)
            {
                // uncle red, perform recoloring and recurse
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                fixRedRed(grandparent);
            }
            else
            {
                // Else perform LR, LL, RL, RR
                if (parent->isOnLeft())
                {
                    if (x->isOnLeft())
                    {
                        // for left right
                        swapColors(parent, grandparent);
                    }
                    else
                    {
                        leftRotate(parent);
                        swapColors(x, grandparent);
                    }
                    // for left left and left right
                    rightRotate(grandparent);
                }
                else
                {
                    if (x->isOnLeft())
                    {
                        // for right left
                        rightRotate(parent);
                        swapColors(x, grandparent);
                    }
                    else
                    {
                        swapColors(parent, grandparent);
                    }

                    // for right right and right left
                    leftRotate(grandparent);
                }
            }
        }
    }

    // find node that do not have a left child
    // in the subtree of the given node
    Node *successor(Node *x)
    {
        Node *temp = x;

        while (temp->left != NULL)
            temp = temp->left;

        return temp;
    }

    // Find node that replaces a deleted node in tree
    Node *BSTNodeReplace(Node *x)
    {
        // when node have 2 children
        if (x->left != NULL and x->right != NULL)
            return successor(x->right);

        // when leaf we don't not need to do anything
        if (x->left == NULL and x->right == NULL)
            return NULL;

        // when single child
        if (x->left != NULL)
            return x->left; //If left node then return left
        else
            return x->right; //Else return right
    }

    // Utitlity function to delete a node
    void deleteNode(Node *v)
    {
        Node *u = BSTNodeReplace(v);

        // True when u and v are both black
        bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK));
        Node *parent = v->parent;

        if (u == NULL)
        {
            // u is NULL therefore v is leaf
            if (v == root)
            {
                // v is root, making root null
                root = NULL;
            }
            else
            {
                if (uvBlack)
                {
                    // u and v both black
                    // v is leaf, fix double black at v
                    fixDoubleBlack(v);
                }
                else
                {
                    // u or v is red
                    if (v->sibling() != NULL)
                        // sibling is not null, make it red"
                        v->sibling()->color = RED;
                }

                // delete v from the tree
                if (v->isOnLeft())
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
            }
            delete v;
            return;
        }

        if (v->left == NULL or v->right == NULL)
        {
            // v has 1 child
            if (v == root)
            {
                // v is root, assign the value of u to v, and delete u
                v->val = u->val;
                v->left = v->right = NULL;
                delete u;
            }
            else
            {
                // Detach v from tree and move u up
                if (v->isOnLeft())
                {
                    parent->left = u;
                }
                else
                {
                    parent->right = u;
                }
                delete v;
                u->parent = parent;
                if (uvBlack)
                {
                    // u and v both black, fix double black at u
                    fixDoubleBlack(u);
                }
                else
                {
                    // u or v red, color u black
                    u->color = BLACK;
                }
            }
            return;
        }

        // v has 2 children, swap values with successor and recurse
        swapValues(u, v);
        deleteNode(u);
    }

    void fixDoubleBlack(Node *x)
    {
        if (x == root)
            // Reached root
            return;

        Node *sibling = x->sibling(), *parent = x->parent;
        if (sibling == NULL)
        {
            // No sibiling, double black pushed up
            fixDoubleBlack(parent);
        }
        else
        {
            if (sibling->color == RED)
            {
                // Sibling red
                parent->color = RED;
                sibling->color = BLACK;
                if (sibling->isOnLeft())
                {
                    // left case
                    rightRotate(parent);
                }
                else
                {
                    // right case
                    leftRotate(parent);
                }
                fixDoubleBlack(x);
            }
            else
            {
                // Sibling black
                if (sibling->hasRedChild())
                {
                    // at least 1 red children
                    if (sibling->left != NULL and sibling->left->color == RED)
                    {
                        if (sibling->isOnLeft())
                        {
                            // left left
                            sibling->left->color = sibling->color;
                            sibling->color = parent->color;
                            rightRotate(parent);
                        }
                        else
                        {
                            // right left
                            sibling->left->color = parent->color;
                            rightRotate(sibling);
                            leftRotate(parent);
                        }
                    }
                    else
                    {
                        if (sibling->isOnLeft())
                        {
                            // left right
                            sibling->right->color = parent->color;
                            leftRotate(sibling);
                            rightRotate(parent);
                        }
                        else
                        {
                            // right right
                            sibling->right->color = sibling->color;
                            sibling->color = parent->color;
                            leftRotate(parent);
                        }
                    }
                    parent->color = BLACK;
                }
                else
                {
                    // 2 black children
                    sibling->color = RED;
                    if (parent->color == BLACK)
                        fixDoubleBlack(parent);
                    else
                        parent->color = BLACK;
                }
            }
        }
    }

    // prints level order for given node
    void levelOrder(Node *ptr)
    {
        if (ptr == NULL)
            // return if node is null
            return;

        // queue for level order
        queue<Node *> q;
        Node *curr;

        // push x
        q.push(ptr);

        while (!q.empty())
        {
            // while q is not empty
            // dequeue
            curr = q.front();
            q.pop();

            // print node value
            cout << curr->val << " ";

            // push children to queue
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }

    // prints inorder recursively
    void inorder(Node *x)
    {
        if (x == NULL)
            return;
        inorder(x->left);
        cout << x->val << " ";
        inorder(x->right);
    }

public:
    // constructor
    // initialize root
    RBTree()
    {
        root = NULL;
    }

    Node *getRoot()
    {
        return root;
    }

    // searches for given value
    // if found returns the node (used for delete)
    // else returns the last node while traversing (used in insert)
    Node *search(int key)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (key < temp->val)
            {
                if (temp->left == NULL)
                    break;
                else
                    temp = temp->left;
            }
            else if (key == temp->val)
            {
                break;
            }
            else
            {
                if (temp->right == NULL)
                    break;
                else
                    temp = temp->right;
            }
        }

        return temp;
    }

    // inserts the given value to tree
    void insert(int n)
    {
        Node *newNode = new Node(n);
        if (root == NULL)
        {
            // when root is null
            // simply insert value at root
            newNode->color = BLACK;
            root = newNode;
        }
        else
        {
            Node *temp = search(n);
            // return if value already exists
            if (temp->val == n)
                return;
            // if value is not found, search returns the node
            // where the value is to be inserted
            newNode->parent = temp;

            if (n < temp->val)
                temp->left = newNode;
            else
                temp->right = newNode;

            // fix Red Red Conflict if exists
            fixRedRed(newNode);
        }
    }

    // utility function that deletes the node with given value
    void deleteByVal(int n)
    {
        if (root == NULL)
            // Tree is empty
            return;

        Node *v = search(n), *u;

        if (v->val != n)
        {
            cout << "Node not found to delete:" << n << "\n";
            return;
        }
        deleteNode(v);
    }

    // prints inorder of the tree
    void printInOrder()
    {
        cout << "Inorder: " << endl;
        if (root == NULL)
            cout << "Tree is empty" << endl;
        else
            inorder(root);
        cout << endl;
    }

    // prints level order of the tree
    void printLevelOrder()
    {
        cout << "Level order: " << endl;
        if (root == NULL)
            cout << "Tree is empty" << endl;
        else
            levelOrder(root);
        cout << endl;
    }
};

int main()
{
    RBTree tree;

    bool enter = true;

    while (enter)
    {
        cout << "Red Black Tree Program:\n";
        cout << "-----------------------\n\n";
        cout << "1 - Insert\n";
        cout << "2 - Level Order Traversal\n";
        cout << "3 - Inorder Traversal\n";
        cout << "4 - Searching\n";
        cout << "5 - Deletion\n";
        cout << "6 - Exit\n";

        int choice;
        cout << "Enter your choice:";
        cin >> choice;
        Node *ptr;
        int val;

        switch (choice)
        {
        case 1:
            int n;
            cout << "\nNumber of elements wants to insert:";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int val;
                cin >> val;
                tree.insert(val);
            }
            break;
        case 2:
            cout << "\nLevel Order Traversal of Created Tree:\n";
            tree.printLevelOrder();
            break;

        case 3:
            cout << "\nInorder Traversal of Created Tree:\n";
            tree.printInOrder();
            break;

        case 4:
            cout << "\nEnter the element you want to search:";
            int val;
            cin >> val;
            ptr = tree.search(val);
            if (val == ptr->val)
                cout << "\nFound\n";
            else
                cout << "\nNot Found\n";
            break;

        case 5:
            cout << "\nEnter the element you want to delete!:";
            cin >> val;
            tree.deleteByVal(val);
            break;

        default:
            cout << "\nGood bye...\n";
            enter = false;
        }
    }
    return 0;
}
