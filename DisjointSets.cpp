// GROUP:   5
// ID:      20150282
// Assign:  02
// Assign:  DisjointSets
// UVA:     10608
// Name:    Nour Adel Abdallah

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
	    int p1=Find(i-1);
	    int p2=Find(j-1);
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
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int numofcases;
    cin>>numofcases;
    for (int i=0; i<numofcases; i++)
    {
        DisjointSets x;
        int n,un,mx=-1;
        cin>>n;
        x.Initialize(n);

        cin>>un;
        for (int i=0; i<un; i++)
        { int z,y;
          cin>>z;
          cin>>y;
          x.Union(z,y);
        }

        for (int i=0; i<x.n; i++)
         {
             if(x.num_nodes[i]>=mx)
                mx=x.num_nodes[i];
         }

         cout<<mx<<endl;
    }

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
