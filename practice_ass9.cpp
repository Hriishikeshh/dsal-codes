#include<iostream>
using namespace std;

class node {
    int data;
    int height;
    node* left;
    node* right;

public:
    node(int key) {
        height = 1;
        data = key;
        left = right = NULL;
    }

    friend class avl;
};

class avl {
    node* root;

public:
    avl() {
        root = NULL;
    }

    node* insert(node* c, int key) {
        if (c == NULL) {
            c = new node(key);
            return c;
        }
        if (key < c->data) {
            c->left = insert(c->left, key);
        }
        else if (key > c->data) {
            c->right = insert(c->right, key);
        }
        updateHeight(c); // Update height after insertion
        cout<<c->data<<" left height:"<<height(c->left)<<" right height:"<<height(c->right)<<endl;
        return balance(c); // Balance the tree if needed
    }

    int height(node* c) {
        if (c == NULL) {
            return 0;
        }
        return c->height;
    }

    int balancing_factor(node* c) {
        if (c == NULL) {
            return 0;
        }
        return height(c->left) - height(c->right);
    }

    void updateHeight(node* c) {
        if (c == NULL) {
            return;
        }
        c->height = 1 + max(height(c->left), height(c->right));
    }

    node* balance(node* c) {
        cout<<balancing_factor(c)<<endl;
        if (balancing_factor(c) == 2) {
            if (balancing_factor(c->left) < 0) {
                c = LRrotation(c);
            }
            else {
                c = LLrotation(c);
            }
        }
        else if (balancing_factor(c) == -2) {
            if (balancing_factor(c->right) > 0) {
                c = RLrotation(c);
            }
            else {
                c = RRrotation(c);
            }
        }
        return c;
    }

    node* LLrotation(node* c) {
        node* temp = c->left;
        c->left = temp->right;
        temp->right = c;
        updateHeight(c); 
        updateHeight(temp);
        return temp; // Return the new root of the subtree
    }

    node* RRrotation(node* c) {
        node* temp = c->right;
        c->right = temp->left;
        temp->left = c;
        updateHeight(c);
        updateHeight(temp);
        return temp; // Return the new root of the subtree
    }

    node* LRrotation(node* c) {
        c->left = RRrotation(c->left);
        return LLrotation(c);
    }

    node* RLrotation(node* c) {
        c->right = LLrotation(c->right);
        return RRrotation(c);
    }

    void display(node* c){
        if(c==NULL){
            return;
        }
        node* queue[1000];
        int front=0,rear=0;
        queue[rear++]=c;
        while(front!=rear){
            node* temp=queue[front++];
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                queue[rear++]=temp->left;
            }
            if(temp->right!=NULL){
                queue[rear++]=temp->right;
            }
        }
    }

};

int main() {
    avl a;
    int n, x;
    node* root=NULL;
    do {
        cout << "1.Insert\n2.Display\n3.Exit\n";
        cin >> n;
        switch (n) {
            case 1:
                cout << "Enter the element to insert\n";
                cin >> x;
                root=a.insert(root, x);
                break;
            case 2:
                cout << "Tree: ";
                a.display(root);
                cout << endl;
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (n != 3);

    return 0;
}
