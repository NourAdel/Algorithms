// GROUP:   5
// ID:      20150282
// Assign:  04
// Assign:  Kruskal
// UVA:     11631
// Name:    Nour Adel AbdAllah
// UVA User Name: NourAdel

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct DisjointSets
{
	int n;
	int* parent;
	int* num_nodes;

	void Initialize(int _n)
	{
	    n=_n;
	    parent=new int[n];
	    num_nodes=new int[n];
	    for (int i=0; i<n; i++)
        {
            parent[i]=i;
            num_nodes[i]=1;
        }
	}
	void Destroy()
	{
	    delete [] parent;
	    delete [] num_nodes;
	}
	int Find(int i)
	{
	    if(parent[i]==i )
            return i;
        Find(parent[i]);
	}
	bool Union(int i, int j)
	{
	    int p1=Find(i);
	    int p2=Find(j);
	    if (p1==p2)
            return false;
        if (num_nodes[p1]>= num_nodes[p2])
        {
            parent[p2]=parent[p1];
            num_nodes[p1]+=num_nodes[p2];

        }
        else
        {
            parent[p1]=parent[p2];
            num_nodes[p2]+=num_nodes[p1];
        }
        return true;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Type>
void Merge(Type* x, int n, bool (*IsBefore)(Type& a, Type& b))
{
    int a=0, med=n/2;
    int b=med;
    Type *tem= new Type[n];
    for (int i=0; i<n; i++)
    {
        if(b==n || (a<med && IsBefore(x[a],x[b])))
            tem[i]=x[a++];
        else

            tem[i]=x[b++];


    }
        for (int i=0; i<n; i++)
            x[i]=tem[i];
        delete [] tem;

}

template<class Type>
void MergeSort(Type* a, int n, bool (*IsBefore)(Type& a, Type& b))
{
    if(n<=1)
        return;
    int med=n/2;
    MergeSort(a,med,IsBefore);
    MergeSort(a+med,n-med,IsBefore);
    Merge(a,n,IsBefore);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Edge
{
	int u, v;
	int w;
};

bool IsBeforeEdge(Edge& a, Edge& b)
{
	return a.w<b.w;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int n;
    for (int l=0; l<n; l++)
   {

    int x,cost=0,totalcost=0;
    cin >>x;
    DisjointSets d;
    d.Initialize(x);

    cin>>x;
    Edge * arr=new Edge[x];

    for (int i=0; i<x; i++)
    {

        Edge e;
        cin>>e.u;
        cin>>e.v;
        cin>>e.w;
        totalcost+=e.w;
        arr[i]=e;

    }

    MergeSort<Edge>(arr, x,IsBeforeEdge);


   for (int i=0; i<x; i++)
    {


        int x=arr[i].u;
        int y= arr[i].v;
       if (d.Union(y,x))
           cost+=arr[i].w;

    }
    cout<<totalcost-cost<<endl;
   }
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
