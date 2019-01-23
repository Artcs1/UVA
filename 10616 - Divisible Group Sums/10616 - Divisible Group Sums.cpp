
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

int arr[205];
int n,m,d,c;
int memo[205][205][15];

int dp(int i,int s,int w)
{
    if(w==c && s==0)
        return 1;
    if(i == n|| w == c)
        return 0;
    if(memo[i][s][w]!=-1)
        return memo[i][s][w];

    return memo[i][s][w] = dp(i+1,s%d,w)+dp(i+1,(s+arr[i])%d,w+1);

}


int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int vez= 1;
    while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
    {
        int t;
        REP(i,n)
            scanf("%d",&arr[i]);
        printf("SET %d:\n",vez);
        REP(i,m)
        {
            scanf("%d %d",&d,&c);
            mset(memo,-1);
            printf("QUERY %d: %d\n",i+1,dp(0,0,0));
        }
        vez++;
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


