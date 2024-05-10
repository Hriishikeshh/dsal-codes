#include<iostream>
using namespace std;

class tbook{
    long tele;
    int key;
};

class telebook{

    public:
        int hash[10];

        telebook(){
            for(int i=0;i<10;i++){
                hash[i]=0;
            }
        }

        int hashcode(int key){
            return key%10;
        }

        int getemptyindex(int key){
            int flag=0;
            int index=hashcode(key);
            for(int i=index;i<10;i++){
                flag+=1;
                if(hash[i]==0){
                    return i;
                    break;
                }
                else{
                    continue;
                }
            }
            return flag;
        }

        bool isfull(){
            int flag=0;
            for(int i=0;i<10;i++){
                if(hash[i]==0){
                    flag=0;
                    break;
                }
                else{
                    flag=1;
                }
            }
            if(flag==1) return true;
            else return false;
        }

        //without replacement
        int allocate2(int key){

            if(!isfull()){
            int k=getemptyindex(key);
            int index=hashcode(key);
            if(hash[index]!=0){
                index=getemptyindex(key);
            }
            hash[index]=key;
            cout<<"comparisons required are "<<k<<endl;
            }
            else if(isfull()){
                cout<<"array full!"<<endl;
            }
        }

        //with replacement
        int allocate1(int key){
            int flag=0;
            int index=hashcode(key);
            int index2=0;

            for(int i=0;i<10;i++){
                flag+=1;
                if(index==i && (hash[index]%10)==i){
                    if(isfull()){
                        cout<<"array if full"<<endl;
                        break;
                    }
                    else{
                        index=getemptyindex(key);
                        hash[index]=key;
                        break;
                    }
                    
                }
                else if(index==i && (hash[index]%10)!=0){
                    if(isfull()){
                        hash[index]=key;
                        break;
                    }
                    else{
                        int temp=hash[index];
                        hash[index]=key;
                        index2=getemptyindex(temp);
                        hash[index2]=temp;
                        break;
                    }
                }
                else if(index==i && hash[index]==0){
                    hash[index]=key;
                    break;
                }
            }
            
            cout<<"comparisons required are "<<flag<<endl;
        }

        //delete
        int deletion(int key){
            int index,flag=0;
            for(int i=0;i<10;i++){
                if(key==hash[i]){
                    flag=1;
                    index=i;
                    break;
                }
            }
            if(flag==1){
                hash[index]=0;
                cout<<"element deleted"<<endl;
            }
        }

        int search(int key){
            int index,flag=0,counter=0;
            for(int i=0;i<10;i++){
                counter+=1;
                if(key==hash[i]){
                    flag=1;
                    index=i;
                    break;
                }
            }
            if(flag==1){
                cout<<"index is "<<index<<endl;
                cout<<"comparisons : "<<counter<<endl;
            }
            else{
                cout<<"not available"<<endl;
            } 
        }

        void display(){
            cout<<"index"<<"   "<<"key"<<endl;

            for(int i=0;i<10;i++){
                cout<<i<<"       "<<hash[i]<<endl;
            }
        }

};

int main(){
    telebook t1;
    telebook t2;

    int ch;

    cout<<"a.with replacement\nb.without replacement"<<endl;
    char c;
    cin>>c;

    if(c=='a'){

        do{
            cout << "\n1)Insert\n2)Display\n3)Search\n4)delete\n5)exit\nEnter your choice:";
            cin >> ch;

            if(ch==1){
            int ele;
            cout << "\nEnter the element:";
            cin >> ele;
            t1.allocate1(ele);
            }
            else if(ch==2){
                t1.display();
            }
            else if(ch==3){
                int key;
                cout<<"enter key to search: ";
                cin>>key;
                t1.search(key);
            }
            else if(ch==4){
                int key;
                cout<<"enter key to delete: ";
                cin>>key;
                t1.deletion(key);
            }
            else if(ch==5){
                break;
            }
        }while(ch!=5);
    }
    else if(c=='b'){

            do{
            cout << "\n1)Insert\n2)Display\n3)Search\n4)delete\n5)exit\nEnter your choice:";
            cin >> ch;

            if(ch==1){
            int ele;
            cout << "\nEnter the element:";
            cin >> ele;
            t2.allocate2(ele);
            
            }
            else if(ch==2){
                t2.display();
            }
            else if(ch==3){
                int key;
                cout<<"enter key to search: ";
                cin>>key;
                t2.search(key);
            }
            else if(ch==4){
                int key;
                cout<<"enter key to delete: ";
                cin>>key;
                t1.deletion(key);
            }
            else if(ch==5){
                break;
            }
        }while(ch!=5);
    }
}
