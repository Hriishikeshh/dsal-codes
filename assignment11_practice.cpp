#include<iostream>
#include<fstream>
using namespace std;

class student{
    int roll;
    string name;
    public:
    student(){
        roll=0;
        name="";
    }

    student(int r,string n){
        roll=r;
        name=n;
    }

    friend fstream &operator<<(fstream &out1,student &s);
    friend fstream &operator>>(fstream &in1,student &s);
    friend ostream &operator<<(ostream &out1,student &s);


    void display(fstream &in,student &s){
        in.open("demo-practice.txt",ios::in);
        while(!in.eof()){
            in>>s;
            if(in.eof()) break;
            cout<<s;
        }
        in.close();
    }
    void search(fstream &in,int x,student &s){
        in.open("demo-practice.txt",ios::in);
        while(!in.eof()){
            in>>s;
            if(s.roll==x){
                cout<<s;
                break;
            }
            else if(in.eof()){
                cout<<"Record not found";
            }
        }
        in.close();
    }
    void delet(fstream &in,int x,int n,student &s){

        student arr[n];
        in.open("demo-practice.txt",ios::in);
        for(int i=0;i<n;i++){
            in>>s;
            arr[i]=s;
        }
        in.close();

        in.open("demo-practice.txt",ios::out | ios::trunc);
        for(int i=0;i<n;i++){
            if(arr[i].roll==x){
                continue;
            }
            else{
                in<<arr[i];
                cout<<arr[i];
            }
        }
        in.close();
    }
};

fstream &operator<<(fstream &out1,student &s){
    out1<<s.roll<<" ";
    out1<<s.name<<" ";
    return out1;
}

fstream &operator>>(fstream &in1,student &s){
    in1>>s.roll;
    in1>>s.name;
    return in1;
}

ostream &operator<<(ostream &out1,student &s){
    out1<<s.roll<<" ";
    out1<<s.name<<" ";
    return out1;
}





int main(){
    student s;
    fstream fs;

    int k;
    cout<<"enter entries: ";
    cin>>k;

    fs.open("demo-practice.txt",ios::out);
    for(int i=0;i<k;i++){
        string name;
        int roll;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter roll: ";
        cin>>roll;
        student s(roll,name);
        fs<<s;
    }
    fs.close();
    
    s.display(fs,s);

    int roll;
    cout<<"enter roll to search :";
    cin>>roll;
    s.search(fs,roll,s);

    int rollno;
    cout<<"enter roll no. to delete :";
    cin>>rollno;
    s.delet(fs,rollno,k,s);

}