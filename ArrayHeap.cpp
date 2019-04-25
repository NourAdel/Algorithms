// GROUP:   5
// ID:      20150282
// Assign:  01
// Assign:  ArrayHeap
// UVA:     10954
// Name:    Nour Adel Abdallah

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
            for (int i=0; i<n;i++)
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

template<class Elem>
struct Heap
{
	Array<Elem> a;
	bool (*IsBefore)(int&, int&);

	void Initialize(bool (*_IsBefore)(int&, int&))
	{
	    IsBefore=_IsBefore;
	    a.Initialize();
	}
	void Destroy()
	{
	    a.Destroy();
	}
	int Child(int i)
	{
	    return (2*i)+1;
	}
	int Parent(int i)
	{
	    return ((i-1)/2);
	}
	void MoveUp(int ind)
	{

        if (ind==0 || !IsBefore(a[ind], a[Parent(ind)]) )
            return;

        int temp=Parent(ind);
        Elem t=a[temp];
        a[temp]=a[ind];
        a[ind]=t;
        MoveUp(temp);

	    }
	void MoveDown(int ind)
	{
	    int t=Child(ind);
	    int x;
	    if(t >= a.n )
            return;

        if(t+1 < a.n && IsBefore(a[t+1],a[t]))
            x=t+1;
        else
            x=t;

        if( IsBefore(a[ind],a[x]) )
            return;

       Elem y=a[x];
       a[x]=a[ind];
       a[ind]=y;
       MoveDown(x);

	}
	void Add(Elem e)
	{
	    a.AddLast(e);
	    MoveUp(a.n-1);
	}
	Elem GetFirst()
	{
	    return a[0];
	}
	Elem RetrieveFirst()
	{
	    if (a.n==1)
            return a[0];
	    Elem tm=a[0];
	    a[0]=a[a.n-1];
	    a.n--;
	    MoveDown(0);
	    return tm;

	}

	void print ()
	{
	    a.print();
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsBeforeInt(int& a, int& b)
{
	return a<b;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Heap<int> a;
    a.Initialize(*IsBeforeInt);
    int x,y, sum=0, cost=0;
    cout<<"Enter the number of elements: "<<endl;
    cin>>x;

    for (int i=0; i<x; i++)
    {
        cin>>y;
        a.Add(y);
    }



    for (int i=0; i<x-1; i++)
    {
        sum+=a.RetrieveFirst();
        sum+=a.RetrieveFirst();
        cost+=sum;
        a.Add(sum);
        sum=0;

    }

    cout<<cost<<endl;






}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
