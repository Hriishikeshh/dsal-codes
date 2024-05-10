//============================================================================
// Name        : DSAL_G1_21159_Assignment04.cpp
// Author      : Dhanvantari
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class DataItem{
	int tele;
	string name;
//public:
//	DataItem(){
//		cout<<"Hello"<<endl;
//	}
	friend class hash_class;
};

class hash_class{
	DataItem h_table[10];
public:
	hash_class(){
		for(int i=0;i<10;i++){
			h_table[i].tele=-1;
			h_table[i].name=" ";
		}
	}

	void insert_woutreplace(string name,int tele){
		DataItem t;
		t.tele=tele;
		t.name=name;
		int h_key=t.tele;
		h_key=h_key%10;
			int count=0;
			while(h_table[h_key].tele!=-1)
			{	count++;
				h_key++;
				h_key=h_key%10;
				if(count==10)
				{
					cout<<"Hash Table is Full!"<<endl;
					break;

				}
			}
			if(count!=10){
			h_table[h_key]=t;
			}
		}
	
	void insert_wreplace(string name,int tele){
			DataItem t;
			t.tele=tele;
			t.name=name;
			int h_key=tele%10;
            if(h_table[h_key].tele % 10 != h_key)
            {   
                DataItem temp=h_table[h_key];
                h_table[h_key]=t;
                t=temp;
            }
			{   int count=0;
				while(h_table[h_key].tele!=-1)
                {   count++;
                    h_key++;
                    h_key=h_key%10;
                    if(count==10){
                        cout<<"Hash is full;";
                        return;
                    }
                }
                h_table[h_key]=t;
			}
            }

	void search(int tele)
	{
	    int key = tele % 10;
	    for (int count = 0; count < 10; count++)
	    {
	        if (h_table[key].tele == tele)
	        {
	            cout << "Found. Name: " << h_table[key].name << " Telephone: " << h_table[key].tele << endl;
	            return;
	        }
	        key = (key + 1) % 10;
	    }
	    cout << "Person with given telephone number is not found." << endl;
	}

	void delet(int tele)
	{
	    int key = tele % 10;
	    for (int count = 0; count < 10; count++)
	    {
	        if (h_table[key].tele == tele)
	        {
	            cout << "Deleted. " << h_table[key].name << ": " << h_table[key].tele << endl;
	            h_table[key].name = " ";
	            h_table[key].tele = -1;
	            return;
	        }
	        key = (key + 1) % 10;
	    }
	    cout << "Person with given telephone number is not found." << endl;
	}

	void display()
	{	int i;
		cout<<"   Name "<<"  Telephone No. "<<endl;
		for(i=0;i<10;i++)
		{   cout<<i<<". ";
			if(h_table[i].tele!=-1)
            {
			cout<<h_table[i].name<<"  "<<h_table[i].tele;
			}
			cout<<endl;
		}
	}
};

int main() {
    hash_class h1;
    hash_class h2;
    string s;
    int t;
    int a;

    cout << "Which method you will prefer? \n1->Linear Probing without replacement.\n 2->Linear probing with replacement." << endl;
    cin >> a;

    if (a == 1) {
        while (true) {
            cout << "1.Insert Data\n2.Search Data\n3.Delete Data\n4.Display Data" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter the name: ";
                    cin >> s;
                    cout << "Enter the telephone Number: ";
                    cin >> t;
                    h1.insert_woutreplace(s, t);
                    break;
                case 2:
                    cout << "Enter the telephone Number to search : ";
                    cin >> t;
                    h1.search(t);
                    break;
                case 3:
                    cout << "Enter the telephone Number to search : ";
                    cin >> t;
                    h1.delet(t);
                    break;
                case 4:
                    h1.display();
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice, please try again." << endl;
                    break;
            }

            char ch;
            cout << "Do you want to continue the operation? (yes=>y No=>n)" << endl;
            cin >> ch;
            if (ch != 'y') {
                break;
            }

        }
    } else if (a == 2) {
        while (true) {
            cout << "1.Insert Data\n2.Search Data\n3.Delete Data\n4.Display Data" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter the name: ";
                    cin >> s;
                    cout << "Enter the telephone Number: ";
                    cin >> t;
                    h2.insert_wreplace(s, t);
                    break;
                case 2:
                    cout << "Enter the telephone Number to search : ";
                    cin >> t;
                    h2.search(t);
                    break;
                case 3:
                    cout << "Enter the telephone Number to search : ";
                    cin >> t;
                    h2.delet(t);
                    break;
                case 4:
                    h2.display();
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice, please try again." << endl;
                    break;
            }
            char ch;
                  cout << "Do you want to continue the operation? (yes=>y No=>n)" << endl;
                  cin >> ch;
                  if (ch != 'y') {
                      continue;
                  }
        }
    }
    else {
        cout << "Wrong Choice" << endl;
    }

    return 0;
}
