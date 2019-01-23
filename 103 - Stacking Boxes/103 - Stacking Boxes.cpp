
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

vector<int>ady[35],ady2[35];
int n,m,temp;
int memo[35],pai[35];

bool func(int i,int j)
{
    bool band = true;
    REP(k,m)
    {
        if(ady[i][k] >= ady[j][k])
            band = false;
    }
    return band;
}

int dp(int u )
{
    if(memo[u]!=-1)
        return memo[u];
    int r = 0;
    REP( i, ady2[u].size())
    {
        int v = ady2[u][i],val = dp(v);
        if(r<val)
        {
            r = val;
            pai[u] = v;
        }
    }
    r++;
    return memo[u] = r;
}

void printpath(int u)
{
    if(pai[u] == -1)
        printf("%d\n",u+1);
    else
    {
        printf("%d ",u+1);
        printpath(pai[u]);
    }
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    while(~scanf("%d %d",&n,&m))
    {
        REP(i,n)
        {
            REP(j,m)
            {
                scanf("%d",&temp);
                ady[i].PB(temp);
            }
            sort(all(ady[i]));
        }

        REP(i,n)
            REP(j,n)
                if(i!=j && func(i,j))
                    ady2[i].PB(j);

        int r = 0;
        mset(memo,-1);
        mset(pai,-1);
        REP(i,n)
            r = max(r,dp(i));

        printf("%d\n",r);
        REP(i,n)
            if(memo[i] == r)
            {
                printpath(i);
                break;
            }

        REP(i,n)
            ady[i].clear(),ady2[i].clear();

    }
/*
    fclose(stdin);
    fclose(stdout);
*/
    return 0;
}


