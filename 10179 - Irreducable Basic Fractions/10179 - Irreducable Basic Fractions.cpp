#include<bits/stdc++.h>

using namespace std;

#define lli long long int

vector<long long int> primes;

void criba(long long int upperbound)
{
    static bool vis[10000005];
    memset(vis,false,sizeof vis);
    vis[0]=vis[1]=true;
    for(long long int i=2;i<=upperbound;i++)
    {
        if(!vis[i])
        {
            for(long long int j = i*i;j<=upperbound;j+=i)
                vis[j] = true;
            primes.push_back(i);
        }
    }
}

int main()
{
    criba(1e7+4);
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        int id=0, PF= primes[id],ans = n;
        while((lli)PF*(lli)PF<=(lli)n)
        {
            if(n%PF==0)
                ans-=ans/PF;
            while(n%PF==0)
                n/=PF;
            PF = primes[++id];
        }
        if(n!=1)
            ans -= ans/n;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
