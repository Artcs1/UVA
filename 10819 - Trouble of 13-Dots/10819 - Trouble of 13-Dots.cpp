
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

int n;
int C[105],P[105],memo[105][10205];
int amount;
int dp(int i,int j)
{
    if(j>amount&&amount<=1800)
        return -inf_i;
    if(j>amount+200)
        return -inf_i;
    if(i==n)
    {
        if(j>amount&&j<=2000)
            return -inf_i;
        return 0;
    }
    if( memo[i][j] != -1 )
        return memo[i][j];
    int v = max(dp(i+1,j),P[i]+dp(i+1,j+C[i]));
    return memo[i][j] = v;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    while(~scanf("%d %d",&amount,&n))
    {
        REP(i,n)
            scanf("%d %d",&C[i],&P[i]);
        mset(memo,-1);
        printf("%d\n",dp(0,0));
    }

    /*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


