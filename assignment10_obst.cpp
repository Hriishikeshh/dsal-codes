#include <iostream>
using namespace std;
class obst
{
    float a[20],b[20],wt[20][20],c[20][20];
    int r[20][20],n;
    public:
    obst(int x)
    {
        n=x;
    }
    void input_prob();
    void initialize();
    void con_obst();
    void display();
    void print(int l1,int r1);
};

//obst functions

void obst::input_prob()
{
    cout<<"Enter the probabilities for successful search:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"p["<<i<<"]"<<"=";
        cin>>a[i];
    }
    cout<<"Enter the probabilities for unsuccessful search:"<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<"q["<<i<<"]"<<"=";
        cin>>b[i];
    }
}
void obst::initialize()
{
    for(int i=0;i<n;i++)
    {
        c[i][i]=0.0;
        r[i][i]=0;
        wt[i][i]=b[i];
        wt[i][i+1]=b[i]+b[i+1]+a[i+1];
        c[i][i+1]=b[i]+b[i+1]+a[i+1];
        r[i][i+1]=i+1;
    }
    c[n][n]=0.0;
    r[n][n]=0;
    wt[n][n]=b[n];
}

void obst::con_obst()
{
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            wt[j][j+i]=b[j+i]+a[j+i]+wt[j][j+i-1];
            c[j][j+i]=9999;
            for(int k=j+1;k<=j+i;k++)
            {
                if(c[j][j+i]>(c[j][k-1]+c[k][j+i]))
                {
                    c[j][j+i]=c[j][k-1]+c[k][j+i];
                    r[j][j+i]=k;
                }
            }
            c[j][j+i]+=wt[j][j+i];
        }
    }
}

void obst::display()
{
    cout<<"Weight Matrix"<<endl;
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //         if(wt[i][j]>=10)
    //         {
    //             cout<<wt[i][j]<<" ";
    //         }
    //         else
    //         {
    //             cout<<wt[i][j]<<"  ";
    //         }
           
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    cout<<wt[0][n]<<endl;
    cout<<"Cost Matrix"<<endl;
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //         if(c[i][j]>=10)
    //         {
    //             cout<<c[i][j]<<" ";
    //         }
    //         else
    //         {
    //             cout<<c[i][j]<<"  ";
    //         }
           
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    cout<<c[0][n]<<endl;
    cout<<"Row Matrix"<<endl;
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //         if(r[i][j]>=10)
    //         {
    //             cout<<r[i][j]<<" ";
    //         }
    //         else
    //         {
    //             cout<<r[i][j]<<"  ";
    //         }
           
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    cout<<r[0][n]<<endl;

}

void obst::print(int l1,int r1)
{
    if(l1>=r1)
    {
        return;
    }
    if(r[l1][r[l1][r1]-1]!=0)
		cout<<"\n Left child of "<<r[l1][r1]<<" :: "<<r[l1][r[l1][r1]-1];
	if(r[r[l1][r1]][r1]!=0)
		cout<<"\n Right child of "<<r[l1][r1]<<" :: "<<r[r[l1][r1]][r1];
	print(l1,r[l1][r1]-1);
	print(r[l1][r1],r1);
	return;
	return;
}

int main()
{
    int x;
    cout<<"Enter number of nodes:";
    cin>>x;
    obst o(x);
    int c=1;
    while(c>0)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Input probabilities"<<endl;
        cout<<"2.Initialize"<<endl;
        cout<<"3.Obst"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Print"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>c;
        if(c==1)
        {
            o.input_prob();
        }
        else if(c==2)
        {
            o.initialize();
        }
        else if(c==3)
        {
            o.con_obst();
        }
        else if(c==4)
        {
            o.display();
        }
        else if(c==5)
        {
            o.print(0,x);
        }
    }
    return 0;
}