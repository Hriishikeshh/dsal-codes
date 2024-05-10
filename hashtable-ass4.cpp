#include <iostream>
using namespace std;

class hashtable
{
    int hash[10];
    int collisions[10];

public:
    hashtable()
    {
        for (int i = 0; i < 10; i++)
        {
            hash[i] = 0;
        }
        for (int i = 0; i < 10; i++)
        {
            collisions[i] = 0;
        }
    }

    int hashcode(int key)
    {
        return key % 10;
    }

    int getemptyindex(int key)
    {
        int flag = 0;
        int index = hashcode(key);
        for (int i = index; i < 10; i++)
        {
            if (hash[i] == 0)
                return i;
        }
        for (int i = 0; i < index; i++)
        {
            if (hash[i] == 0)
                return i;
        }
    }

    bool isfull()
    {
        for (int i = 0; i < 10; i++)
        {
            if (hash[i] == 0)
                return false;
        }
        return true;
    }

    void display()
    {
        cout << "Index  ->  Key  ->  collisions\n";
        for (int i = 0; i < 10; i++)
        {
            cout << i << " -> " << hash[i] << " -> " << collisions[i] << endl;
        }
    }

    // insert data without replacement
    void insertwithoutreplacement(int key)
    {
        int index = hashcode(key);

        if (isfull())
            cout << "Hash Table is Full\n";

        else if (hash[index] == 0)
        {
            hash[index] = key;
            collisions[index] = 0;
        }
        else
        {
            int emptyindex = getemptyindex(key);
            hash[emptyindex] = key;
            collisions[index] = abs(emptyindex - index);
        }
    }

    // with replacement
    void insertwithreplacement(int key)
    {
        int index = hashcode(key);

        if (hash[index] == 0)
        {
            hash[index] = key;
            collisions[index] = 0;
        }
        else if (hash[index] != 0)
        {
            if (hashcode(hash[index]) == index)
            {
                int emptyindex = getemptyindex(key);
                hash[emptyindex] = key;
                collisions[emptyindex] = abs(emptyindex - index);
            }
            else if (hashcode(hash[index]) != index)
            {
                int temp = hash[index];
                int priorindex = hashcode(hash[index]);
                hash[index] = key;
                collisions[index] = 1;
                int newindex = getemptyindex(temp);
                hash[newindex] = temp;
                collisions[newindex] = abs(newindex - priorindex);
            }
        }
    }

    // search and delete
    void search(int key)
    {
        int index;
        for (int i = 0; i < 10; i++)
        {
            if (hash[i] == key)
            {
                
                cout << "Key found" << key << "at index " << i << endl;
                index = i;
                break;
            }
        }
        int ch;
        cout << "1. delete\n2. update\n";
        cin >> ch;
        if (ch == 1)
        {
            hash[index] = 0;
            collisions[index] = 0;
        }
        else if (ch == 2)
        {
            cout << "Enter the new key: ";
            int newkey;
            cin >> newkey;
            hash[index] = newkey;
            collisions[index] = 0;
        }
    }
};

int main()
{
    hashtable h;
    cout << "1. without replacement\n2. with replacement\n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        do
        {
            cout << "1. Insert\n2. display\n3. exit\n";
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                cout << "Enter the key: ";
                int key;
                cin >> key;
                h.insertwithoutreplacement(key);
            }
            else if (ch == 2)
                h.display();
            else if (ch == 3)
                break;
            else
                cout << "Invalid Choice\n";
        } while (true);
    }
    else if (choice == 2)
    {
        do
        {
            cout << "1. Insert\n2. display\n3. exit\n";
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                cout << "Enter the key: ";
                int key;
                cin >> key;
                h.insertwithreplacement(key);
            }
            else if (ch == 2)
                h.display();
            else if (ch == 3)
                break;
            else
                cout << "Invalid Choice\n";
        } while (true);
    }
}