//============================================================================
// Name        : DSAL_G1_21159_Assignment06.cpp
// Author      : Dhanvantari
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node{
	int key;
	node*next;
public:
	node(){
		key=-1;
		next=NULL;
	}
	friend class graph;
	friend class Queue;
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
			if(front == -1 || front>rear){
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
		int delet(){
			if(isEmpty()){
				cout<<"Queue is Empty!";
				return 0;
			}
			else
			{
				node* p;
				p=Que[front];
				front++;
				if(front > 19){
					front=rear=-1;
				}
				return p->key;
			}

		}
	};
class stack
{
	int top;
	node* s[20];
	friend class graph;
	public:
	stack()
	{
		top=-1;
	}

	bool isEmpty()
	{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
	}
	void push(node*t)
	{
	if(top==19)
		{
			cout<<"Stack is full"<<endl;
		}
	else
		{
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
	else
	{
		t=s[top];
		top--;
	}
		return t;
	}

};
class graph
{
	node* list[20];

public:
	graph()
	{
		for (int i=1;i<=20;i++)
			{
				list[i]=new node;
				list[i]->key=i;
			}
	}

	void create()
	{
		int edg;
		cout<<"Enter the no. of edges in the graph:";
		cin>>edg;
		for(int i=0;i<edg;i++)
		{
			int s,d;
			cout<<"Enter the source: ";
			cin>>s;
			cout<<"Enter the destination: ";
			cin>>d;

			//assign source and dest to new nodes
			node* temp1=new node;
			node* temp2=new node;
			temp1->key=s;
			temp2->key=d;

			//add the nodes to the list
			//source
			node* t = list[s];
			while(t->next!=NULL)
			{	
				t=t->next;
			}
			t->next=temp2;

			//destination	
			node* l=list[d];
			while(l->next!=NULL)
			{
				l=l->next;
			}
			l->next=temp1;
		}
	}

	void bfs()
	{
		int visit[20];
		for(int i=0;i<20;i++)
		{
			visit[i]=0;
		}

		Queue Q;
		node* temp=list[1];
		Q.add(temp);
		visit[temp->key]=1;

		while(!Q.isEmpty())
		{
			int x=Q.delet();
			cout<<x<<" ";
			temp=list[x];
			while(temp!=NULL)
			{
				if(visit[temp->key]==0){
					Q.add(temp);
					visit[temp->key]=1;
				}
				temp=temp->next;
			}
		}
	}

	void display(int n)
	{
		for(int i=0;i<n;i++)
		{
			node* temp=list[i];
			while(temp != NULL)
			{
				cout<<"|"<<temp->key<<"|";
				if(temp->next!= NULL)
				{
					cout<<"->";
				}
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	void dfs()
	{
		int visit[20];
		for(int i=0;i<20;i++){
			visit[i]=0;
		}

		stack st;
		node* temp=list[1];
		st.push(temp);
		visit[temp->key]=1;
		
		while(temp != NULL)
		{
			node* q=st.pop();
			cout<<q->key<<" ";
			temp=list[q->key];
			while(temp!=NULL){
				if(visit[temp->key]==0){
					st.push(temp);
					visit[temp->key]=1;
				}
				temp=temp->next;
			}
		}
	}
};

int main() {
	 graph g;
	 g.create();
	 g.display(20);
	 cout<<"BFS: ";
	 g.bfs();
	 
	//  cout<<"\nDFS: ";
	//  g.dfs();

	return 0;
}
