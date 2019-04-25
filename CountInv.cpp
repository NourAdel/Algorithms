// GROUP:   5
// ID:      20150282
// Assign:  04
// Assign:  CountInv
// UVA:     10810
// Name:    Nour Adel AbdAllah
// UVA User Name: NourAdel

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long CountInvMerge(long long* x, int n)
{
    long long counter=0;
    int a=0, med=n/2;
    int b=med;
    long long *tem= new long long[n];
    for (int i=0; i<n; i++)
    {
        if(b==n || (a<med && x[a]<x[b]))
            tem[i]=x[a++];
        else
        {
            tem[i]=x[b++];
            if(a<med)
                counter+=med-a;
        }
    }
        for (int i=0; i<n; i++)
            x[i]=tem[i];
        delete [] tem;
        return counter;
}
long long CountInv(long long* a, int n)
{
    long long x=0;
    if(n<=1)
        return x;
    int med=n/2;
     x=CountInv(a,med);
     x+=CountInv(a+med,n-med);
     x+=CountInvMerge(a,n);


     return x;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  /*  long long *t=new long long [4];
    t[0]=4;
    t[1]=3;
    t[2]=2;
    t[3]=5;
    CountInv(t,4);
    cout<<t[0]<<t[1]<<t[2]<<t[3];

   */ long long * arr;
    int x,y;
    cin>>x;
    while(x!=0)
    {
        arr= new long long [x];
        for (int i =0; i<x; i++)
        {
            cin>>y;
            arr[i]=y;
        }
       cout<<CountInv(arr,x)<< endl;

        cin>>x;
    }
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
