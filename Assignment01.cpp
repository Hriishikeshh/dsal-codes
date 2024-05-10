//============================================================================
// Name        : DSAL_G1_21159_Assignment01.cpp
// Author      : Dhanvantari
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class node{
	int data;
	node*left;
	node*right;
public:
	node(int a){
		data=a;
		left=right=NULL;
	}
	friend class Binary_Tree;
	friend class stack;
};

class Queue{
	node*Que[20];
	int rear,front;
public:
	Queue(){
		rear=-1;
		front=-1;
	}
	bool isEmpty(){
		if(front==-1 || front>rear){
			return true;
		}
		else{
			return false;
		}
	}
	void add(node*t){
		if(rear==19){
			cout<<"Queue is Full!";
		}
		else{
			rear++;
			if(rear==0){
				front=rear;
			}
			Que[rear]=t;
		}
	}
	node* delet(){
		if(isEmpty()){
			cout<<"Queue is Empty!";
		}
		else{
			node* p;
			p=Que[front];
			front++;
			if(front > 19){
				front=rear=-1;
			}
			return p;

		
		}
	}
};

class stack{
int top;
node* s[20];
public:
stack(){
top=-1;
}

bool isEmpty(){
if(top==-1){
return true;
}
else{
return false;
}
}
void push(node*t){
if(top == 19){
cout<<"Stack is full"<<endl;
}
else{
top++;
s[top]=t;
}
}
node* pop()
{
	node* t=NULL;
	if(top==-1){
	cout<<"Stack is Empty"<<endl;
	}
	else{
	t=s[top];
	top--;

	}
	return t;
	}

};

class Binary_Tree{
	node*root;
public:
    int countL=0,countI=0;
	Binary_Tree(){
		root =NULL;
	}
	node* create(int x){
		if(root==NULL){
			root=new node(x);

		}
		else{
			insert(root,x);
		}
		return root;
	}
	void insert(node*t,int y){
		char ch;
		cout<<"\n"<<y<<" node you want to insert( left/Right) with respect to "<<t->data;
		cin>>ch;
		if(ch=='L'||ch=='l'){
			if(t->left==NULL){
				t->left=new node(y);
				cout<<"Node is created at left";
			}
			else{
				insert(t->left,y);
			}
		}
		else{
			if(t->right==NULL)
			{
				t->right=new node(y);
				cout<<"Node is created at right";
			}

			else
			{
				insert(t->right,y);
			}
	}
	}

	void inorder(node*t)
	{
		if(t==NULL){
			return;
		}
		else{

			inorder(t->left);
			cout<<t->data<<" ";
			inorder(t->right);
		}
	}

	void preorder(node*t){
		if(t==NULL){
			return;
		}
		else{
			cout<<t->data<<" ";
			preorder(t->left);
			preorder(t->right);
		}
	}
	void postorder(node*t){
		if(t==NULL){
			return;
			}
		else{
		 postorder(t->left);
		 postorder(t->right);
		 cout<<t->data<<" ";
				}
	}
	void BFS(node* t) {
		Queue Q;
		Q.add(t);
		node* temp;

		while (!Q.isEmpty())
		{
			temp = Q.delet();
			cout << temp->data << " ";

			if (temp->left != NULL) {
				Q.add(temp->left);
			}

			if (temp->right != NULL) {
				Q.add(temp->right); 
			}
		}
	}

	void Iter_inorder(stack s,node*T){
		while(1){
			while(T != NULL){
				s.push(T);
				T=T->left;
			}
			if(s.isEmpty()){
				return;
			}
			T=s.pop();
			cout<<T->data<<" ";
			T=T->right;
		}
		}

	void Iter_preorder(stack s,node*T)
	{
		while(1){
			while(T!=NULL){
				cout<<T->data<<" ";
				s.push(T->right);
				T=T->left;
			}
			if(s.isEmpty()){
				return;
			}
			T=s.pop();
		}
	}


	void Iter_postorder( stack s, node *T)
	{
		node*temp;
		node*p;
		temp=new node(0);
		while(1)
		{
			while(T!=NULL)
			{
				s.push(T);
				if(T->right!=NULL)
				{
				s.push(T->right);
				s.push(temp);
				}
				T=T->left;
			}
			if(s.isEmpty())
			{
				cout<<p->data<<" ";
				return;
			}
			else
			{
				p=s.pop();
			}
			while(p!=temp && !s.isEmpty())
			{
				cout<<p->data<<" ";
				p=s.pop();
			}
			if(!s.isEmpty())
			{
				T=s.pop();
			}
		}
	}

	int height(node*t){
		if(t==NULL){
			return 0;
		}
		else{
			int lheight=height(t->left);
			int rheight=height(t->right);
			if(lheight>rheight){
				return lheight+1;
			}
			else{
				return rheight+1;
			}
		}
	}

	void leaf_internal(node*t){
		if(t->left==NULL && t->right==NULL)
		{
			cout<<t->data<<" ";
			countL++;
			return;
		}
		else
		{  countI++;
		if(t->left!=NULL)
		{
            leaf_internal(t->left);
		}
		if(t->right!=NULL)
		{
            leaf_internal(t->right);
		}	
			
		}
	}

	void mirror(node*p){
			if(p==NULL){
			   return;
			}
			else{
				mirror(p->left);
				mirror(p->right);
				node* temp;
				temp=p->left;
				p->left=p->right;
				p->right=temp;
			}
		}

	void delet(node*t)
	{
		if(t==NULL)
		{
			return;
	    }
		delet(t->left);
		delet(t->right);
		cout<<"Deleting "<<t->data<<endl;
		delete t;
	}


	void operator = (Binary_Tree bt)
	{
		this->root = copy_tree(bt.root);
	}
	node* copy_tree(node *root){
		if( root == NULL)
		{
			return NULL;
		}
		else
		{
			node *temp = new node(root->data);
			temp->left = root->left;
			temp->right = root->right;
			return temp;

		}
	}
};
int main()
{
 Binary_Tree T;
 node*r=NULL;
 while(true){
	 cout<<"\n1.Create"<<endl;
	  	cout<<"2.Display"<<endl;
	  	cout<<"2.1.PreOrder(iterative or recurssive)"<<endl;
	  	cout<<"2.2.Inorder(iterative or recurssive)"<<endl;
	  	cout<<"2.3.PostOrder(iterative or recurssive)"<<endl;
	  	cout<<"3. Breadth first search(recurssive):"<<endl;
	  	cout<<"4.Height"<<endl;
	  	cout<<"5.Leaf Count"<<endl;
	  	cout<<"6.Internal Nodes"<<endl;
	  	cout<<"7.Mirror the tree"<<endl;
		cout<<"8.Delete "<<endl;
		cout<<"9.Copy and display copied tree: ";
	  	cout<<"10.Exit"<<endl;
		int ch;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
		case 1:
			int n;
			cout<<"How many nodes you want to enter: ";
			cin>>n;
			int i;
			i=0;
			while(i<n){
			int a;
			cout<<"Enter the data: ";
			cin>>a;
			r=T.create(a);
			i++;
				}
			break;
		case 2:
			char cha;
			cout<<"Which Traversal method you want to use(Recurssive(r) or iterarive(i))?";
			cin>>cha;
			if(cha=='r')
			{
				int c;
				cout<<"Which Traversal method you want to use?";
				cin>>c;
				if(c==1){
					cout<<"\n(Inorder traversal)Binary tree: ";
					T.inorder(r); 
				}
				else if(c==2){
					cout<<"\n(Preorder Traversal)Binary tree:";
					T.preorder(r);
				}
				else if(c==3){
					cout<<"\n(Postorder Traversal)Binary tree:";
					T.postorder(r); 
				}
				else{
					cout<<"Wrong Choice";
				}
			}
			else if(cha=='i')
			{
				stack t;
				int c;
				cout<<"Which Traversal method you want to use?";
				cin>>c;
				if(c==1)
				{
					cout<<"\n(Inorder traversal)Binary tree: ";
					T.Iter_inorder(t,r); 
				}
				else if(c==2)
				{
					cout<<"\n(Preorder Traversal)Binary tree:";
					T.Iter_preorder(t,r);
				}
				else if(c==3)
				{
					cout<<"\n(Postorder Traversal)Binary tree:";
					T.Iter_postorder(t,r); 
				}
			}
			else
			{
				cout<<"\nwrong choice"<<endl;
			}
				break;
		case 3:
				cout<<"\nBreadth First Search: ";
				T.BFS(r);
				break;
		case 4:
			cout<<"\nHeight of Tree: "<<T.height(r);
			break;
		case 5:
			cout<<"\nLeaf node:";
			T. leaf_internal(r);
			cout<<"\nNo.of External nodes="<<T.countL;
			break;
		case 6:
				cout<<"\nNo.of Internal nodes: "<<T.countI;
				break;
		case 7:
			T.mirror(r);
			break;
		case 8:
			T.delet(r);
			break;
		case 9:
			node* q;
			q=r;
			T.BFS(q);
		case 10:
			exit(0);
			break;
		default:
			break;
	  }
	

 }
	return 0;
}
