#include <iostream>
using namespace std;

class node
{
    int key;
    node *next;

public:
    node()
    {
        key = -1;
        next = NULL;
    }
    friend class queue;
    friend class stack;
    friend class graph;
};

class queue
{
    node *que[20];
    int rear, front;

public:
    queue()
    {
        rear = -1;
        front = -1;
    }

    bool isempty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(node *t)
    {
        if (rear == 19)
        {
            cout << "queue is  full";
        }
        else
        {
            rear++;
            if (rear == 0)
            {
                front = rear;
            }
            que[rear] = t;
        }
    }

    int delet()
    {
        if (isempty())
        {
            cout << "queue is empty";
            return 0;
        }
        else
        {
            node *p;
            p = que[front];
            front++;
            if (front > 19)
            {
                front = rear = -1;
            }
            return p->key;
        }
    }
    friend class graph;
};

class stack
{
    node *arr[20];
    int top;

public:
    stack()
    {
        top = -1;
    }

    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(node *t)
    {
        if (top >= 19)
        {
            cout << "stack full!" << endl;
        }
        else
        {
            top++;
            arr[top] = t;
        }
    }

    int pop()
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        else
        {
            int t = arr[top]->key;
            top--;
            return t;
        }
    }
};

class graph
{
    node *arr[20];

public:
    graph()
    {
        for (int i = 0; i < 20; i++)
        {
            arr[i] = new node;
            arr[i]->key = i;
        }
    }

    // create graph
    void create()
    {
        int n;
        cout << "enter total edges: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int s, d;
            cout << "source: ";
            cin >> s;
            cout << "destination: ";
            cin >> d;
            node *temps = new node;
            node *tempd = new node;
            temps->key = s;
            tempd->key = d;

            node *t = arr[s];
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = tempd;

            node *k = arr[d];
            while (k->next != NULL)
            {
                k = k->next;
            }
            k->next = temps;
        }
        display(n);
    }

    // display graph
    void display(int n)
    {
        for (int i = 0; i < n; i++)
        {
            node *t = arr[i]; // skip the dummy node with key -1
            cout << i << "->";
            while (t != NULL)
            {
                cout << t->key << " ";
                t = t->next;
            }
            cout << endl;
        }
    }

    // bfs traversal
    void bfs()
    {
        int visit[20];
        for (int i = 0; i < 20; i++)
        {
            visit[i] = 0;
        }

        queue q;
        node *temp = arr[1];
        q.push(temp);
        visit[temp->key] = 1;

        while (!q.isempty())
        {
            int x = q.delet();
            cout << x << " ";
            temp = arr[x];
            while (temp != NULL)
            {
                if (visit[temp->key] == 0)
                {
                    q.push(temp);
                    visit[temp->key] = 1;
                }
                temp = temp->next;
            }
        }
    }

    // dfs traversal
    void dfs()
    {
        int visited[20];
        for (int i = 0; i < 20; i++)
        {
            visited[i] = 0;
        }

        stack st;

        // Iterate over all nodes to handle disconnected components
        node *temp = arr[1];
        st.push(temp);
        visited[temp->key] = 1;

        while (!st.isempty())
        {
            int x = st.pop();
            cout << x << "-";
            temp = arr[x];

            while (temp != NULL)
            { // Traverse all adjacent nodes
                if (visited[temp->key] == 0)
                {
                    st.push(temp);
                    visited[temp->key] = 1;
                }
                temp = temp->next;
            }
        }
    }
};

int main()
{
    graph g;
    g.create();
    cout<<"BFS :";
    g.bfs();

    cout<<"DFS :";
    g.dfs();
}
