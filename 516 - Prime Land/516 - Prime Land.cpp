#include<bits/stdc++.h>

using namespace std;

vector<long long int>primes;

long long int P(long long int b,long long int p)
{
    if(p == 0 ) return 1ll;
    else if(p == 1) return b;
    else{
        long long int res = P(b,p/2);
        res*=res;
        if(p%2ll == 1)
            res*=b;
        return res;
    }
}

void criba(long long int upperbound)
{
    static bool vis[10000000+5];
    memset(vis,false,sizeof vis);
    vis[0]=vis[1]=true;

    for(long long int i=2;i<=upperbound;i++)
    {
        if(!vis[i])
        {
            for(long long int j=i*i;j<=upperbound;j+=i)
                vis[j] = false;
            primes.push_back(i);
        }
    }
}

int main()
{
    criba(1e7+4);
    string s;
    while(getline(cin,s))
    {
        if(s[0]=='0')
            break;
        long long int base, power;
        istringstream iss(s);
        long long int N = 1;
        while(iss>>base)
        {
            iss>>power;
            N*=P(base, power);
        }
        N--;
        vector< pair< long long int, long long int > >factors;
        long long int id=0,PF=primes[id];
        while(PF*PF<=N)
        {
            long long int c =0;
            while(N%PF==0){N/=PF;c++;}
            if(c!=0)
                factors.push_back(pair<long long int,long long int>(PF,c));
            PF= primes[++id];
        }
        if(N!=1)
            factors.push_back(pair<long long int,long long int>(N,1));
        for(int i=(int)factors.size()-1;i>=1;i--)
            printf("%lld %lld ",factors[i].first,factors[i].second);
        printf("%lld %lld\n",factors[0].first,factors[0].second);

    }
    return 0;
}
