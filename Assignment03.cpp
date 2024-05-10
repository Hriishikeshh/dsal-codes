//============================================================================
// Name        : 21169Assign3final.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*Create an inordered threaded binary search tree. Perform inorder, preorder
traversals without recursion and deletion of a node. Analyze time and space
complexity of the algorithm.*/

#include <iostream>
using namespace std;

class node
{
	int data;
	node *left;
	node *right;
	bool rthread;
	bool lthread;
public:
	node(int data_)
	{
		data = data_;
		left = NULL;
		right = NULL;
	}
	friend class TBT;
};
class TBT
{
public:
	node* root;
	TBT()
	{
		root = NULL;
	}

	void insert(int ele)
	{
		node* temp = root;
		node* parent = NULL;
		while (temp != NULL)
		{
			if (ele == temp->data)
			{
				cout<<"Duplication not permitted!"<<endl;
				return;
			}
			parent = temp;
			if (ele < temp->data)
			{
				if (temp->lthread == false)
				{
					temp = temp->left;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (temp->rthread == false)
				{
					temp = temp->right;
				}
				else
				{
					break;
				}
			}
		}
		node* newNode = new node(ele);
		newNode->lthread = true;
		newNode->rthread = true;
		if (parent == NULL)
		{
			root = newNode;
			newNode->left = NULL;
			newNode->right = NULL;
		}
		else if (ele < parent->data)
		{
			newNode->left = parent->left;
			newNode->right = parent;
			parent->lthread = false;
			parent->left = newNode;
		}
		else
		{
			newNode->right = parent->right;
			newNode->left = parent;
			parent->rthread = false;
			parent->right = newNode;
		}
	}

	void inorder()
	{
		if (root == NULL)
		{
			cout<<"Empty!"<<endl;
		}
		node* temp = root;
		while (temp->lthread == false)
		{
			temp = temp->left;
		}
		while (temp != NULL)
		{
			cout<<temp->data<<endl;
			temp = inorderSuccessor(temp);
		}
	}

	node* inorderSuccessor(node* r)
	{
		if (r->rthread == true)
		{
			return r->right;
		}
		r = r->right;
		while (r->lthread == false)
		{
			r = r->left;
		}
		return r;
	}

	node* inorderPredecessor(node* r)
	{	
		if (r->lthread == true)
		{
			return r->left;
		}
		r = r->left;
		while (r->rthread == false)
		{
			r = r->right;
		}
		return r;
	}

	node* remove(int ele)
	{
		node* temp = root;
		node* parent = NULL;
		int found = 0;
		while (temp != NULL)
		{
			if (ele == temp->data)
			{
				found = 1;
				break;
			}
			parent = temp;
			if (ele < temp->data)
			{
				if (temp->lthread == false)
				{
					temp = temp->left;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (temp->rthread == false)
				{
					temp = temp->right;
				}
				else
				{
					break;
				}
			}
		}
		if (found == 0)
		{
			cout<<"Element not present in tree!"<<endl;
		}
		else if (temp->rthread == false && temp->lthread == false)
		{
			root = caseC(parent,temp);
		}
		else if (temp->lthread == false || temp->rthread == false)
		{
			root = caseB(parent,temp);
		}
		else
		{
			root = caseA(parent,temp);
		}
		return root;
	}

	node* caseA(node* par, node* ptr)//fresh leaf node
	{
		if (par == NULL)
		{
			root = NULL;
		}
		else if (ptr == par->left)
		{
			par->lthread = true;
			par->left = ptr->left;
		}
		else
		{
			par->rthread = true;
			par->right = ptr->right;
		}
		delete ptr;
		return root;
	}

	node* caseB(node* par, node* ptr)//patially branched node
	{
		node* child;
		if (ptr->lthread == false)
		{
			child = ptr->left;
		}
		else
		{
			child = ptr->right;
		}


		if (par == NULL)//deletion of root itself
		{
			root = child;
		}
		else if (ptr == par->right)//bypass ptr node
		{
			par->right = child;
		}
		else
		{
			par->left = child;
		}


		node* s = inorderSuccessor(ptr);
		node* p = inorderPredecessor(ptr);
		if (ptr->lthread == false)
		{
			p->right = s;
		}
		else if (ptr->rthread == false)
		{
			s->left = p;
		}
		delete ptr;
		return root;
	}

	node* caseC(node* par, node* ptr)//complete internal node
	{
		node* parsucc = ptr;
		node* succ = ptr->right;
		while (succ->lthread == false)
		{
			parsucc = succ;
			succ = succ->left;
		}
		ptr->data = succ->data;
		
		if (succ->lthread == true && succ->rthread == true)
		{
			root = caseA(parsucc,succ);
		}
		else
		{
			root = caseB(parsucc,succ);
		}
		return root;
	}

	void preorder()
	{
		if (root == NULL)
		{
			cout<<"Empty Tree!"<<endl;
			return;
		}
		node* temp = root;
		while (temp != NULL)
		{
			cout<<temp->data<<endl;
			if (temp->lthread == false)
			{
				temp = temp->left;
			}
			else if (temp->rthread == false)
			{
				temp = temp->right;
			}
			else
			{
				while (temp != NULL && temp->rthread == true)
				{
					temp = temp->right;
				}
				if (temp != NULL)
				{
					temp = temp->right;
				}
			}
		}
	}
};

int main()
{
	TBT t;
	int choice;
	while (true)
	{
		cout<<"1) Insert an element."<<endl;
		cout<<"2) Delete an element."<<endl;
		cout<<"3) Inorder traversal."<<endl;
		cout<<"4) Preorder traversal."<<endl;
		cout<<"5) Stop."<<endl;
		cout<<"Enter choice: "<<endl;
		cin>>choice;
		if (choice == 1)
		{
			int ele;
			cout<<"Enter element to be inserted: "<<endl;
			cin>>ele;
			t.insert(ele);
		}
		else if (choice == 2)
		{
			int ele;
			cout<<"Enter element to be deleted: "<<endl;
			cin>>ele;
			t.remove(ele);
		}
		else if (choice == 3)
		{
			t.inorder();
		}
		else if (choice == 4)
		{
			t.preorder();
		}
		else if (choice == 5)
		{
			cout<<"Thank You!"<<endl;
			break;
		}
		else
		{
			cout<<"Wrong Choice!"<<endl;
		}
	}
	return 0;
}
