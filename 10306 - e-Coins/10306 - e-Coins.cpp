
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


int m,e;
vector< ii > arr;
int memo[305][305];

int dp(int ex,int ey)
{
    if(ex<0||ey<0)
        return inf_i;
    if(ex == 0 && ey ==0)
        return 0;
    if(memo[ex][ey]!=-1)
        return memo[ex][ey];
    int men = inf_i;
    for(int i=0;i<m;i++)
        men = min(men,1 + dp(ex - arr[i].first,ey - arr[i].second));
    return memo[ex][ey] =men;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    scanf("%d",&n);
    while(n--)
    {
        mset(memo,-1);
        arr.clear();
        scanf("%d %d",&m,&e);
        REP(i,m)
        {
            int x,y;
            scanf("%d  %d",&x,&y);
            arr.PB( ii (x,y));
        }
        int val = inf_i;
        for( int i=0; i<=e; ++i ){
			int J = e*e - i*i;
			int j = (int)(sqrt(J) + 1e-7);
			if( j*j == J )
				val = min( val, dp(i, j) );
		}
        (val == inf_i)?printf("not possible\n"):printf("%d\n",val);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


