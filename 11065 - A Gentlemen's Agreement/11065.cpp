#include<bits/stdc++.h>

using namespace std;

#define lli long long int

long long int Adj[65];

int nIS,mIS,n,c,u,v;

lli F;


void backtrack(int i,lli mask,int depth)
{
    if( mask  == F )
    {
        nIS++;
        mIS = max(mIS,depth);
    }
    else
    {
        for(int j=i;j<n;j++)
            if(!(mask & (1ll<<j)))
                backtrack(j+1, mask|Adj[j], depth+1);
    }
}

int main()
{  
    /*
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    */
    int cities;
    scanf("%d",&cities);
    while(cities--)
    {
        memset(Adj,0,sizeof Adj);
        scanf("%d %d",&n,&c);
        F = (1ll<<n)-1;
        for(int i=0;i<n;i++)
            Adj[i] |= (1ll<<i);
        for(int i=0;i<c;i++)
        {
            scanf("%d %d",&u,&v);
            Adj[u] |= (1ll<<v);
            Adj[v] |= (1ll<<u);
        }
        nIS=0,mIS=0;
        backtrack(0,0ll,0);
        printf("%d\n%d\n",nIS,mIS);
    }
    /*
    fclose(stdin);
    fclose(stdout);
    */
    return 0;
}
