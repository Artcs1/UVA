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
#define inf_i (1<<29)-1

int n,m;
int l[15][105],memo[105][105][15];

int dp(int i,int j,int k)
{
    if((k==n&&i>j)||(k<n&&i>=j))
        return -inf_i;
    if(k==n)
        return 0;
    if(memo[i][j][k]!=-1)
        return memo[i][j][k];
    int res=-inf_i;
    if(l[k][i]>=5)
        res=max(l[k][i]+dp(0,j-i-1,k+1),dp(i+1,j,k));
    else
        res=dp(i+1,j,k);
    return memo[i][j][k]=res;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mset(memo,-1);
        mset(l,-1);
        scanf("%d %d",&n,&m);
        REP(i,n)
            REP(j,m)
                scanf("%d",&l[i][j]);
        int result=dp(0,m,0);
        //debug(result);
        if(result>0)
            printf("Maximal possible average mark - %.2lf.\n",((double)result/n)+1e-9 );
        else
            printf("Peter, you shouldn't have played billiard that much.\n");
    }
/*
    fclose(stdin);
    fclose(stdout);
*/
    return 0;
}


