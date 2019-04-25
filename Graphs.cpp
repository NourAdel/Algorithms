// GROUP:   5
// ID:      2050282
// Assign:  03
// Assign:  Graphs
// UVA:     924
// Name:    Nour Adel Abdallah
// UVA User Name: NourAdel

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Value>
struct Array
{
    int  n, sz;
    Value* arr;

    void Initialize()
    {
        sz=1;
        n=0;
        arr=new Value[sz];
    }
    void Destroy()
    {
        delete [] arr;
    }
    void AddLast(Value v)
    {
        if (n==sz)
        {
            sz*=2;
            Value* new_arr=new Value[sz];
            for (int i=0; i<n; i++)
                new_arr[i]=arr[i];
            delete [] arr;
            arr=new_arr;
        }
        arr[n++]=v;
    }
    void RemoveLast()
    {
        n--;
    }
    Value& operator[](int i)
    {
        return arr[i];
    }

    void print ()
    {
        for (int i=0; i<n; i++)
            cout<<arr[i]<<endl;
    }
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node
{
    Array<int> adj;


    void Initialize()
    {
        adj.Initialize();
    }
    void Destroy()
    {
        adj.Destroy();
    }
    void addN (int n)
    {
        adj.AddLast(n);
    }
};

struct Graph
{
    int n;
    Node* nodes;

    void Initialize(int _n)
    {
        n=_n;
        nodes=new Node[n];
        for (int i=0; i<n; i++)
        {
            nodes[i].Initialize();
        }
    }
    void Destroy()
    {
        for(int i=0; i<n; i++)
        {
            nodes[i].Destroy();
        }
        delete [] nodes;
    }
    void addE (int i, int j)
    {
        nodes[i].addN(j);
    }

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Type>
struct Queue
{
    int f, n,l;
    Type* elems;

    void Initialize(int sz)
    {
        n=sz;
        elems=new Type[n];
        f=l=-1;
    }
    void Destroy()
    {
        delete [] elems;
    }
    void Add(Type t)
    {
        if(f==-1)
        {
            elems[0]=t;
            f=0;
            l++;
        }
        else
        {
            elems[++l]=t;
        }



    }
    Type Pop()
    {
        Type x=elems[f];
        f++;
        return x;

    }
    Type Peek()
    {
        return elems[f];
    }
    int Num()
    {
        return (l-f)+1;
    }
};

void BFS (Graph g, int start)
{
    if(g.nodes[start].adj.n==0)
    {
        cout<<"0"<<endl;
        return;
    }
    Queue <int>q;
    int x;
    q.Initialize(g.n);
    q.Add(start);
    bool arr[g.n];
    int days[g.n];
    for (int i=0; i<g.n; i++)
    {
        arr[i]=false;
        days[i]=0;
    }
    arr[start]=true;

    while(q.Num()>0)
    {
        x = q.Pop();
        for (int i=0; i<g.nodes[x].adj.n; i++)
        {

            if(arr[g.nodes[x].adj[i]]==false)
            {

                arr[g.nodes[x].adj[i]]=true;
                q.Add(g.nodes[x].adj[i]);
                days[g.nodes[x].adj[i]]=days[x]+1;
            }

        }
    }

    int fd[g.n];
    for (int i=0; i<g.n; i++)
    {
        fd[i]=0;
    }
    for (int i=0; i<g.n; i++)
    {
        fd[days[i]]++;
    }

    int mx=0,day=-1;

    for (int i=1; i<g.n; i++)
    {
        if(fd[i]>mx)
        {
            mx=fd[i];
            day=i;
        }

    }

    cout<<mx<<" "<<day<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
    Graph g;
    int siz;
    cin>>siz;
    g.Initialize(siz);
    int x,y;
    for(int i=0; i<siz;i++)
    {

        cin>>x;
        for(int j=0; j<x; j++)
        {

            cin>>y;
            g.addE(i,y);
        }
    }

    int cases;
    int* z;
    cin>>cases;
    z=new int[cases];
    for(int i=0; i<cases; i++)
    {
        cin>>z[i];
    }

    for(int i=0; i<cases; i++)
    {
        BFS(g,z[i]);
    }



}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
