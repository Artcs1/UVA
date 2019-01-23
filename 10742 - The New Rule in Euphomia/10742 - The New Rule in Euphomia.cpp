
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
bool vis[1000005];

void sieve(lli upperbound)
{
    mset(vis,0);
    vis[0]=vis[1]=true;
    for(lli i= 2;i<upperbound+1;i++)
    {
        if(!vis[i])
        {
            primes.PB((int)i);
            for(lli j = i*i ; j<upperbound+1 ; j+=i)
                vis[j] = true;
        }
    }
}


int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    sieve(1000005);
    int n;
    int vez=1;
    while(~scanf("%d",&n)&&n!=0)
    {
        lli r = 0;
        REP(i,primes.size())
        {
            int val = n- primes[i];
            if(val <= primes[i])
                break;
            int ind = upper_bound(all(primes),val)-primes.begin();
            ind--;
            r+= (lli )(ind - i);
        }
        printf("Case %d: %lld\n",vez++,r);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


