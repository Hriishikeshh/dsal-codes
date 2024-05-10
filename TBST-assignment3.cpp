#include<iostream>
using namespace std;

class node{
    int data;
    bool lthread,rthread;
    node* left,*right;
    public:
    node(int val){
        data=val;
        lthread=rthread=true;
        left=right=NULL;
    }

    friend class tbst;
};

class tbst{
    node* root;

    public:
    tbst(){
        root=NULL;
    }

    void create(int x){
        node* temp=root;
        node* parent=NULL;

        while(temp!=NULL){
            if(x==temp->data){
                cout<<"duplicate entry!";
                return;
            }
            parent=temp;
            if(x>temp->data){
                if(temp->rthread==false) temp=temp->right;
                else break;
            }
            else if(x<temp->data) {
                if(temp->lthread==false) temp=temp->left;
                else break;
            }
        }

        node* newnode=new node(x);
        newnode->lthread=true;
        newnode->rthread=true;
        if(parent==NULL){
            root=newnode;
            newnode->left=NULL;
            newnode->right=NULL;
        }
        else if(x>parent->data){
            newnode->right=parent->right;
            newnode->left=parent;;
            parent->right=newnode;
            parent->rthread=false;
        }
        else{
            newnode->left=parent->left;
            newnode->right=parent;
            parent->left=newnode;
            parent->lthread=false;
        }

    }

    node* inordersuccessor(node* r){
        if(r->rthread==true) return r->right;
        r=r->right;
        while(r->lthread==false) r=r->left;
        return r;
    }

    node* inorderpredecessor(node* r){
        if(r->lthread==true) return r->left;
        r=r->left;
        while(r->rthread==false) r=r->right;
        return r;
    }

    void inorder(){
        if(root==NULL) cout<<"empty!";
        node* temp=root;
        while(temp->lthread==false) temp=temp->left;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=inordersuccessor(temp);
        }
    }

    void preorder(){
        if(root==NULL) cout<<"empty!";
        node* temp=root;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            if(temp->lthread==false) temp=temp->left;
            else if(temp->rthread==false) temp=temp->right;
            else{
                while(temp!=NULL && temp->rthread==true) temp=temp->right;
                if(temp!=NULL) temp=temp->right;
            }
        }
    }

    void remove(int x){
        node* temp=root;
        node* parent=NULL;
        int found=0;
        while(temp!=NULL){
            if(x==temp->data){
                cout<<"found!";
                found=1;
                break;
            }
            parent=temp;
            if(x>temp->data){
                if(temp->rthread==false) temp=temp->right;
                else break;
            }
            else if(x<temp->data){
                if(temp->lthread==false) temp=temp->left;
                else break;
            }
        }

        if(found==0){
            cout<<"element not in tree!";
            return;
        }
        else if(temp->lthread==false && temp->rthread==false){
            root=case3(temp,parent);
        }
        else if(temp->rthread==false || temp->lthread==false){
            root=case2(temp,parent);
        }
        else{
            root=case1(temp,parent);
        }
    }

    //leaf node
    node* case1(node* temp,node* parent){
        if(parent==NULL) root=NULL;
        else if(temp==parent->left){
            parent->left=temp->left;
            parent->lthread=true;
        }
        else{
            parent->right=temp->right;
            parent->rthread=true;
        }
        delete temp;
        return root;
    }

    //one child
    node* case2(node* temp,node* parent){
        node* child;
        if(temp->rthread==false) child=temp->right;
        else child=temp->left;

        if(temp==parent->left) parent->left=child;
        else parent->right=child;

        node* insuc=inordersuccessor(temp);
        node* inpre=inorderpredecessor(temp);

        if(temp->lthread==false){
            inpre->right=insuc;
        }
        else{
            insuc->left=inpre;
        }
        delete temp;
        return root;
    }

    //two children
    node* case3(node* temp,node* parent){
        node* parsucc=temp;
        node* succ=temp->right;
        while(succ->lthread==false){
            parsucc=succ;
            succ=succ->left;
        }
        temp->data=succ->data;
        if(succ->lthread==true && succ->rthread==true){
            root=case1(succ,parsucc);
        }
        else{
            root=case2(succ,parsucc);
        }
        return root;
    }

};

int main(){
    tbst t;
    do{
        cout<<"\n1. Insert\n2. Inorder\n3. preorder\n4. delete\n5. exit\nenter choice:";
        int ch;
        cin>>ch;
        if(ch==1){
            int x;
            cout<<"Enter the element: ";
            cin>>x;
            t.create(x);
        }
        else if(ch==2){
            t.inorder();
        }
        else if(ch==3){
            t.preorder();
        }else if(ch==4){
            int k;
            cout<<"enter value to delete :";
            cin>>k;
            t.remove(k);
        }
        else{
            break;
        }
    }while(true);
}