
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

vector<int>ady[100005];
int memo[100005];

int dp(int u)
{
    if(ady[u].size()==0)
        return memo[u] = 1;
    if(memo[u]!=-1)
        return memo[u];

    int r = 0 ;
    REP(i,ady[u].size())
    {
        r+= dp(ady[u][i]);
    }
    return memo[u] = r;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,m,v;
    int vez = 0;
    while(~scanf("%d",&n))
    {
        REP(i,n)
        {
            scanf("%d",&m);
            REP(j,m)
            {
                scanf("%d",&v);
                ady[i].PB(v);
            }
        }

        mset(memo,-1);

        if(vez++)
            printf("\n");
        printf("%d\n",dp(0));

        REP(i,100005)
            ady[i].clear();

    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


