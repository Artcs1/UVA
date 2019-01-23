
//AUTOR:MURRUGARRA JEFFRI ERWIN
//UNIVERSIDAD: UNIVERSIDAD NACIONAL DE TRUJILLO
#include <bits/stdc++.h>

#define REP(i, a) for( int i = 0; i < a; i++ )
#define RFOR(i,x,y) for(int i = x; i>= y; i--)
#define FOR(i,x,y) for (int i = x; i < y; i++)
#define ITFOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define VE vector <int>
#define mset(A,x) memset(A, x, sizeof A)
#define PB push_back
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define LSOne(S) (S&(-S))

using namespace std;

#define ll long long
#define lli long long int
#define PI acos(-1.0)
#define ii pair<int,int>
#define inf_ll (((1LL<<62)-1)<<1)+1
#define inf_i (1<<30)-1

vector<int>primes;
bitset<10000>vis;

void sieve(int upperbound)
{
    vis[0]=vis[1]=1;
    for(lli i = 2;i<=upperbound;i++)
        if(!vis[i])
        {
            primes.PB((int )i);
            for(lli j = i*i;j<=upperbound;j+=i)
            {
                vis[j]=1;
            }
        }
}
int T,n,m;
int memo[205][1200][20];
int dp(int i,int s,int w)
{
    if(w==m&&s==n)
        return 1;
    if(i==T||w==m||s>n)
        return 0;
    if(memo[i][s][w]!=-1)
        return memo[i][s][w];
    return memo[i][s][w] = dp(i+1,s,w)+dp(i+1,s+primes[i],w+1);
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

sieve(1200);
T = primes.size();
while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
{
    mset(memo,-1);
    printf("%d\n",dp(0,0,0));
}

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


