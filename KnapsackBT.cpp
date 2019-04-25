// GROUP:   5
// ID:      20150282
// Assign:  12
// Assign:  KnapsackBT
// UVA:     10130
// Name:    Nour Adel Abdallah
// UVA Username: NourAdel
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Type>
void Merge(Type* a, int n, bool (IsBefore)(Type& a, Type& b))
{
    int mid = (n+1)/2;
    int i = 0, j = mid;
    int k = 0;
    Type *arr = new Type[n];
    while(i < mid || j < n)
    {
        if(i >= mid && j < n)
        {
            arr[k++] = a[j++];
        }
        else if ((j >= n && i < mid) || IsBefore(a[i], a[j]))
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = a[j++];
        }
    }
    for(int l = 0 ; l < n ; l++)
    {
        a[l] = arr[l];
    }
    delete[] arr;
}

template<class Type>
void MergeSort(Type* a, int n, bool (*IsBefore)(Type& a, Type& b))
{
    if(n<=1)
    {
        return;
    }
    int mid = (n+1)/2;
    MergeSort<Type>(a,mid,IsBefore);
    MergeSort<Type>(a+mid,n-mid,IsBefore);
    Merge<Type>(a,n,IsBefore);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Obj
{
	int v;
	int w;
};

int n;       // number of objects (input)
Obj a[1000]; // objects (input)

////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsBefore(Obj& a, Obj& b)
{
    return a.v/a.w>b.v/b.w;
} // return true if unit value of a is greater than unit value of b

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int best_val; // the best total value found until now

int Bound(int i, int w)
{
    int cv=0, cur=w;
    for (int j=i; j<n; j++)
    {
        if (cur==0)
            break;
        if (cur>= a[j].w)
        {
            cur-=a[j].w;
            cv+=a[j].v;
        }
        else
        {
            cv+=cur*(a[j].v/a[j].w);
            cur-=cur;
        }
    }
} // upper bound on the total value of items [i..n-1] that can fit in w

void BackTrack(int i, int w, int cur_val)
{
    if (i==n)
    {
        if (best_val<cur_val)
            best_val=cur_val;
        return;
    }
    if(cur_val+Bound(i,w)<=best_val)
        return;

    if (a[i].w<=w)
        BackTrack(i+1,w-a[i].w,cur_val+a[i].v);
    else
        BackTrack(i+1,w,cur_val);


} // starting from item i, remaining weight w, cur_value of objects[0..i-1]

int ComputeKnapsack(int N, int W)
{

    best_val=-1;
    MergeSort(a,N, IsBefore);
    n=N;
    BackTrack(0,W,0);
    return best_val;
} // solve knapsack of N objects and W weight

void Compute()
{
    int numberOftestCases;
    int numberOfObject;
    int* arrFinal;
    Obj x;
    int numberOfPeople;
    int maxWeight;
    cin>>numberOftestCases;
    arrFinal = new int[numberOftestCases];
    for(int i=0 ; i<numberOftestCases ; i++)
    {
        int result = 0;
        cin>>numberOfObject;
        for(int j = 0 ; j<numberOfObject ; j++)
        {
            cin>>a[j].v;
            cin>>a[j].w;
        }
        cin>>numberOfPeople;
        for(int j = 0 ; j<numberOfPeople ; j++)
        {
            cin>>maxWeight;
            result+=ComputeKnapsack(numberOfObject,maxWeight);

        }
        arrFinal[i]=result;
    }
    for(int i = 0 ; i<numberOftestCases ; i++)
    {
        cout<<arrFinal[i]<<endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	//freopen("input_assign12_10130.txt", "r", stdin);
	Compute();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
