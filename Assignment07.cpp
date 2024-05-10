#include <iostream>
#define I 9999
using namespace std;


class graph
{
    int arr[7][7];
    int near[7];
    int visited[2][6];
    public:
    graph()
    {
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
            {
                arr[i][j]=I;
            }
        }
        for(int i=0;i<7;i++)
        {
            near[i]=I;
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<6;j++)
            {
                arr[i][j]=0;
            }
        }
    }
    void insert();
    void display();
    void prims();
    void cost();
};

void graph::insert()
{
    for(int i=0;i<7;i++)
    {
        for(int j=i;j<7;j++)
        {
            if(i==j)
            {
                arr[i][j]=I;
            }
            else
            {
                int ans;
                cout<<"Is there a edge between "<<i<<" and "<<j<<"(0/1):";
                cin>>ans;
                if(ans==1)
                {
                    cout<<"Enter weight:";
                    int weight;
                    cin>>weight;
                    arr[i][j]=arr[j][i]=weight;
                }
                else
                {
                    arr[i][j]=I;
                }
            }
        }
    }
}

void graph::display()
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(arr[i][j]==I)
            {
                cout<<"  "<<"I";
            }
            else
            {
                if(arr[i][j]>=10)
                {
                    cout<<" "<<arr[i][j];
                }
                else
                {
                    cout<<"  "<<arr[i][j];
                }
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void graph::prims()
{
    int u,v;
    int min=I;
    for(int i=0;i<7;i++)
    {
        for(int j=i;j<7;j++)
        {
            if(arr[i][j]<min)
            {
                min=arr[i][j];
                u=i;
                v=j;
            }
        }
    }
    visited[0][0]=u;
    visited[1][0]=v;
    near[u]=near[v]=-1;
   
    //For each vertex i that is not yet part of the minimum spanning tree (near[i]!=-1), this part of the code updates the near array to store the vertex (either u or v) that is closest to vertex i.

    for(int i=1;i<7;i++)
    {
        if(near[i]!=-1)
        {
            if(arr[i][u]<arr[i][v])
            {
                near[i]=u;
            }
            else
            {
                near[i]=v;
            }
        }
    }

     //repeat
     //The loop iterates over the remaining vertices that are not yet included in the minimum spanning tree. Since the algorithm starts with two vertices, the loop runs for i from 1 to 5, inclusively.
    for(int i=1;i<6;i++)
    {
        min=I;
        int k;
        for(int j=0;j<7;j++)
        {
            if(near[j]!=-1 && (arr[j][near[j]]<min))
            {
                min=arr[j][near[j]];
                k=j;

            }
        }
        visited[0][i]=k;
        visited[1][i]=near[k];
        near[k]=-1;
        for(int i=0;i<7;i++)
        {
            if(near[i]!=-1&&(arr[i][k]<arr[i][near[i]]))
            {
                near[i]=k;
            }
        }
    }
    for(int i=0;i<6;i++)
    {
        cout<<"("<<visited[0][i]<<","<<visited[1][i]<<")"<<endl;
    }
}

void graph::cost()
{
    int cost1=0;
    for(int i=0;i<6;i++)
    {
        cost1+=arr[visited[0][i]][visited[1][i]];
    }
    cout<<cost1;
}


int main()
{
    graph g;
    g.insert();
    g.display();
    g.prims();
    g.cost();
    return 0;
}