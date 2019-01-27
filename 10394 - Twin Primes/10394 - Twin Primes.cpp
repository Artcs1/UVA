#include<bits/stdc++.h>
using namespace std;

vector<int>primes;

void criba(long long int upperbound)
{
    static bool vis[20000005];
    memset(vis,false,sizeof vis);
    vis[0] = vis[1] = true;
    for(long long int i = 2; i <= upperbound ; i++)
    {
        if(!vis[i])
        {
            for(long long int j = i*i; j <= upperbound; j+=i)
            {
                vis[j]=true;
            }
            primes.push_back((int)i);
        }
    }
}

int main()
{
    vector< pair<int,int> > R;
    criba(2e7 + 5);
    int n,t = primes.size();
    
    for(int i=0;i<t-1;i++)
    {
        if(primes[i+1]-primes[i]==2)
            R.push_back( pair<int,int> (primes[i],primes[i+1]) );
    }
    while(~scanf("%d",&n))
    {
         printf("(%d, %d)\n",R[n-1].first,R[n-1].second);
    }
    return 0;
}
