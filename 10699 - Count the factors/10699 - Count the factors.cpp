#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int numDiff[1000005];
void criba(lli upperbound)
{
    memset(numDiff,0,sizeof numDiff);
    for(lli i=2;i<=upperbound;i++)
    {
        if(numDiff[i]==0)
            for(lli j=i;j<=upperbound;j+=i)
                numDiff[j]++;
    }
}

int main()
{
    criba(1e6+5);
    int n;
    while(~scanf("%d",&n)&&n!=0)
    {
        printf("%d : %d\n",n,numDiff[n]);
    }
    return 0;
}
