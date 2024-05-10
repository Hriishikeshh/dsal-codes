//============================================================================
// Name        : DSAL_G1_21159_Assingnment02.cpp
// Author      : Dhanvantari
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class node{
     string keyword;
     string meaning;
     node*left;
     node*right;
public:
     node(){
    	 left=right=NULL;
     }
     friend class BST;
};

class BST{
	node*root;
public:
	BST()
	{
		root=NULL;
	}

	node* create()
	{   node*newnode=new node;
		cout<<"Enter the keyword: ";
		cin>>newnode->keyword;
		cout<<"\nEnter the Meaning of the keyword: ";
		cin>>newnode->meaning;

		if(root==NULL)
		{
		    root=newnode;
		}
		else{
			insert_iter(root,newnode->keyword,newnode->meaning);
		}
		return root;
	}
	void insert_iter(node *root,string key,string mean)
	{	node*t=new node;
	    t->keyword=key;
	    t->meaning=mean;
        if(root==NULL){
            root=t;
        }
        else{
              node *temp,*temp1;
              temp=temp1=root;
            while(temp!=NULL)
			{
                temp1=temp;
                if(temp->keyword > t->keyword){
                    temp=temp->left;
                }
                else
                {
                    temp=temp->right;
                }
            }
        if(temp1->keyword > t->keyword){
            temp1->left=t;
        }
        else if(temp1->keyword < t->keyword){
            temp1->right=t;
        }
        else
        {
            cout<<"Duplicate Entry.";
        }
	}

	}
	void inorder(node*t){
		if(t==NULL){
			return;
		}
		else{

			inorder(t->left);
			cout<<t->keyword<<": "<<t->meaning<<endl;
			inorder(t->right);
		}
        }

	void preorder(node*t){
			if(t==NULL){
				return;
			}
			else{
				cout<<t->keyword<<": "<<t->meaning<<endl;
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
			 cout<<t->keyword<<": "<<t->meaning<<endl;
					}
		}
	void update(node*r,string str,string mean)
	{
		node*t=r;
		while(t!=NULL)
			{
				if(t->keyword!=str){
					if(str< t->keyword){
					t=t->left;
					}
				else{
					t=t->right;
					}
				}
				else{
					break;
				}
			}
			if(t!=NULL){
				t->meaning=mean;
			}
		  if(t==NULL){
			cout<<"This keyword is not present in the given BST"<<endl;
		   }		
		   
	}

	int search_count(string key){
		node*t;
		int count=0;
		t=root;
		while(t!=NULL){
			if(t->keyword!=key){
					if(key < t->keyword){
					t=t->left;
					}
				else{
					t=t->right;
					}
					count++;
			}
			else{
				break;
			}
		}
		if(t==NULL){
			cout<<"This keyword is not present in the given BST"<<endl;
		   }	
		return count;

	}
	void delet(string str){
     node*t=root;
     node*p=NULL;
     int found=0;
     while(t!=NULL && found==0){
    	 if(t->keyword==str){
    		 found=1;
    		 break;
    	 }
    	 else if(t->keyword<str){
    		 p=t;
    		 t=t->right;
    	 }
    	 else{
    		 p=t;
    		 t=t->left;
    	 }
     }
     if(found!=1){
    	   cout<<"This keyword is not present in the given BST"<<endl;
       }
     else{
     if(t->left!=NULL && t->right!=NULL){
    	 node*CS;
    	 CS=t->right;
    	 while(CS->left!=NULL){
    		 p=CS;
    		 CS=CS->left;
    	 }
    	 t->keyword=CS->keyword;
		 t=CS;
     }
     if(t->left==NULL && t->right==NULL){
    	 if(t==p->left){
    		 p->left=NULL;
    	 }
    	 else{
    		 p->right=NULL;
    	 }
    	 delete t;
     }
     else if(t->left!=NULL && t->right==NULL){
    	 if(t==p->left){
    		 p->left=t->left;
    	 }
    	 else{
    		 p->right=t->left;
    	 }
    	 delete t;
     }
     else{
    	 if(t==p->left){
    		 p->left=t->right;
    	 }
    	 else {
    		 p->right=t->right;
    	 }
         delete t;
     }
	}
	}

};
int main()
{	string str;
	string meaning;
	BST T;
	node*r;
	int n;
	cout<<"How many nodes you want to enter: ";
	cin>>n;
	int i;
	i=0;
	while(i<n){
	r=T.create();
	i++;
	}
	while(true){
		cout<<"\n1.Insert the new keyword ";
		cout<<"\n2.Update the meaning of the keyword ";
		cout<<"\n3.Delete the keyword ";
		cout<<"\n4.Display the tree(inorder) ";
		cout<<"\n5.Display the tree(preorder) ";
		cout<<"\n6.Display the tree(postorder) ";
		cout<<"\n7.Display the count of comparisions needed to search the keyword";
		cout<<"\n8.Exit ";
		int ch;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch){
		case 1:
            cout<<"Enter the keyword: ";
            cin>>str;
            cout<<"\nEnter the Meaning of the keyword: ";
            cin>>meaning;
			T.insert_iter(r,str,meaning);
			break;
		case 2:
			cout<<"Enter the updated meaning:";
			cin>>meaning;
			cout<<"Enter the keyword that is to be updated: ";
			cin>>str;
			T.update(r,str,meaning);
			break;
		case 3:

			cout<<"Enter the keyword that is to be deleted: ";
			cin>>str;
			T.delet(str);
			break;
		case 4:
			T.inorder(r);
			break;
		case 5:
			T.preorder(r);
			break;
		case 6:
			T.postorder(r);
			break;
		case 7:
			int count;
			cout<<"Enter the keyword that is to be searched: ";
			cin>>str;
			count=T.search_count(str);
			cout<<"Count:"<<count<<endl;
			break;	
		case 8:
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}
