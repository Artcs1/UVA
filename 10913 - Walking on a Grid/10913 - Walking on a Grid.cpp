
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


int n,k;
int M[80][80];
int memo[80][80][15][10];

int vis[80][80];
int dx[]={0,0,1};
int dy[]={-1,1,0};

bool inside(int x,int y)
{
    if(x>=0 && y >=0 && x<n && y <n)
        return true;
    return false;
}
int dp(int x,int y,int v,int estado)
{
    if(v > k)
        return -inf_i;
    if(x == n-1 && y == n-1)
        return M[x][y];
    if(memo[x][y][v][estado]!=-1)
        return memo[x][y][v][estado];

    int r = -inf_i;
    REP(i,3)
    {
        int xx= x + dx[i];
        int yy= y + dy[i];
        if(inside(xx,yy)&&vis[xx][yy] == false)
        {
            vis[xx][yy] = true;
            r = max(r,dp(xx,yy,(M[xx][yy]<0)?v+1:v,i)+M[x][y]);
            vis[xx][yy] = false;
        }
    }
    return memo[x][y][v][estado] = r;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int vez = 1;
    while(~scanf("%d %d",&n,&k)&&(n!=0|| k!=0))
    {
        int maxi = 0;
        REP(i,n)
            REP(j,n)
                scanf("%d",&M[i][j]);

        mset(vis,false);
        mset(memo,-1);
        vis[0][0] = true;
        int val = dp(0,0,(M[0][0]<0)?1:0,1);
        printf("Case %d: ",vez++);
        (val < -1000000)?printf("impossible\n"):printf("%d\n",val);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


