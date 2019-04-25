// GROUP:   5
// ID:      20150282
// Assign:  10
// Assign:  MatChain
// UVA:     348
// Name:    Nour Adel Abdallah
// UVA Username: NourAdel

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int p[11]; // the dimensions of matrices

int T[11][11]; // T[a][b]=the optimal number of multiplication of p[a]...p[b]
int D[11][11]; // D[a][b]=the decision (value of k) that gets T[a][b]

// Top down version
int MatChain(int a, int b)
{
    if(a+1==b)
    {
        T[a][b]=0;
        return 0;
    }
    if (T[a][b]>0)
        return T[a][b];
    int k;
    T[a][b]=100000000000000000;
    for(k=a+1; k<b; k++)
    {
        int v=MatChain(a,k)+MatChain(k,b)+p[a]*p[k]*p[b];
        if (v<T[a][b])
        {
            T[a][b]=v;
            D[a][b]=k;
        }
    }
    return T[a][b];
} // Recursive, cost of multiplying the b-a matrices with indexes: a...b-1
void MatChainTopDown(int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            T[i][j]=-1;
        }
    }
    MatChain(0,n);
} // Initialize T then call MatChain(0,n)

// BottomUp version
void MatChainBottomUp(int n)
{
    for (int s=1; s<n; s++)
    {
        for (int i=0; i+s<=n; i++)
        {
            int j=s+i;
            if (i+1==j)
            {
                T[i][j]=0;
                continue;
            }
            int k;
            T[i][j]=100000000000000000;
            for(k=i+1; k<j; k++)
            {
                int v= T[i][k]+T[k][j]+p[i]*p[k]*p[j];
                if (v<T[i][j])
                {
                    T[i][j]=v;
                    D[i][j]=k;
                }
            }
        }
    }
}

// Recursive to output the solution for both versions
void MatChainSol(int a, int b)
{
   int k=D[a][b];
   if(a+1==b)
   {
       cout<<"A"<<a;
       return;
   }
   cout<<"(";
   MatChainSol(a,k); cout<<"X";
   MatChainSol(k,b); cout<<")";
   return;
}

void Compute()
{
    int N,a,b;
    int i=1;
    while(true)
    {
        cin>>N;
        if(N==0)
            break;
        if(N>10)
            break;
        for(int i=0; i<N; i++)
        {
            cin>>a>>b;
            p[i]=a;
        }
        p[N]=b;
        MatChainBottomUp(N);
        cout<<"Case 1:";
        MatChainSol(0,N);
        cout<<" "<<endl;
        i++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //freopen("input_assign10_00348.txt", "r", stdin);
    Compute();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
