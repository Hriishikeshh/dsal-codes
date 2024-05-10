#include<iostream>
using namespace std;


class node{
    int key,value;
    node* next;
    public:
    node(int k,int v){
        key=k;
        value=v;
        next=NULL;
    }

    friend class hashtable;
};

class hashtable{
    node* hash[10];

    public:
    hashtable(){
        for(int i=0;i<10;i++){
            hash[i]=NULL;
        }
    }

    int hashcode(int key){
        return key%10;
    }

    void create(int k,int v){
        int index=hashcode(k);
        node* newnode=new node(k,v);
        if(hash[index]==NULL) hash[index]=newnode;
        else{
            node* temp=hash[index];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }

    void display(){
        cout<<"sr   key->value\n";
        for(int i=0;i<10;i++){
            cout<<i<<"    ";
            node* temp=hash[i];
            while(temp!=NULL){
                cout<<temp->key<<"->"<<temp->value<<",";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

};

int main(){
    hashtable h;

    do{
        cout<<"1. Create\n2. Display\n3. Exit\n";
        int ch;
        cin>>ch;
        if(ch==1){
            int key,value;
            cout<<"Enter key and value: ";
            cin>>key>>value;
            h.create(key,value);
        }
        else if(ch==2){
            h.display();
        }
        else if(ch==3){
            break;
        }
    }while(true);
}