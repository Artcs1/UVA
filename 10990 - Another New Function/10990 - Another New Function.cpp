#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int Phi[2000005];
void criba(lli upperbound)
{
    for(int i=0;i<=upperbound;i++)
        Phi[i] = i;
    for(lli i=2;i<=upperbound;i++)
    {
        if(Phi[i]==i)
            for(lli j=i;j<=upperbound;j+=i)
                Phi[j] = (Phi[j]/i) *(i-1);                
    }
}

int main()
{
    criba(2e6+5);
    int cases;
    scanf("%d",&cases);
    int memo[2000004];
    memset(memo,-1,sizeof memo);
    memo[0]=0;
    memo[1]=0;
    for(int i=2;i<=2000000;i++)
         memo[i] = memo[Phi[i]] + 1;
    for(int i=1;i<=2000000;i++)
        memo[i] += memo[i-1];
    while(cases--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        printf("%d\n",memo[m]-memo[n-1]);
    }
    return 0;

}
