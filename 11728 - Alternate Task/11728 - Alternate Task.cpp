#include<bits/stdc++.h>

using namespace std;

vector<int>primes;

void criba(int upperbound)
{
    bool vis[10005];
    memset(vis,false,sizeof vis);
    vis[0]=vis[1]=true;
    for(int i=2;i<=upperbound;i++)
    {
        if(!vis[i])
        {
            for(int j=i*i;j<=upperbound;j+=i)
                vis[j]=true;
            primes.push_back(i);
        }
    }
}

int POW(int b,int p)
{
    if(p==0)
        return 1;
    else if(p==1)
        return b;
    else
    {
        int res=POW(b,p/2);
        res*=res;
        if(p%2==1)
            res*=b;
        return res;
    }

}


int SD(int N)
{
    int id=0,PF= primes[id],ans=1;
    while(PF*PF<=N)
    {
        int power=0;
        while(N%PF==0)
        {
            N/=PF;
            power++;
        }
        ans*= (POW(PF,power+1)-1)/(PF-1);
        PF=primes[++id];
    }
    if(N!=1)
        ans*= (POW(N,2)-1)/(N-1);

    return ans;
}

int main()
{
    map< int,int> mymap;
    int n;
    criba(10004);

    for(int i=1;i<1000;i++)
    {
        int sumdiv=SD(i);
        mymap[sumdiv]=i+1;
    }
    int cas = 1;
    while(scanf("%d",&n)&&n!=0)
    {
        printf("Case %d: %d\n",cas++,mymap[n]-1);
    }
    return 0;
}
