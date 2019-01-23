
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
#define inf_i (1<<31)-1

int matriz[205][205];
int amount,g;
int memo[205][205];
int dp(int money,int gar)
{
    if(money<0)
        return -1000000000;
    if(gar==g)
        return amount-money;
    if(memo[money][gar]!=-1)
        return memo[money][gar];
    int ans =-1;
    for(int i=1;i<=matriz[gar][0];i++)
        ans = max(dp(money-matriz[gar][i],gar+1),ans);
    return memo[money][gar]=ans;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    scanf("%d",&n);
    REP(i,n)
    {
        scanf("%d %d",&amount,&g);
        REP(j,g)
        {
            scanf("%d",&matriz[j][0]);
            REP(k,matriz[j][0])
            {
                scanf("%d",&matriz[j][k+1]);
            }
        }
        mset(memo,-1);
        int r= dp(amount,0);
        (r<0)?printf("no solution\n"):printf("%d\n",r);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


