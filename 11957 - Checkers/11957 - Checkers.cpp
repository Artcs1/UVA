
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


vector<string > arr;

int memo[105][105];

int n,x,y;
int dx[]={-1,-1,-2,-2};
int dy[]={+1,-1,+2,-2};

bool inside(int x,int y )
{
    if(x>=0 && y>=0 && y<n && x < n)
        return true;
    return false;
}

int dp(int x,int y)
{
    if(x == 0)
        return memo[x][y] = 1;
    if(memo[x][y]!=-1)
        return memo[x][y];

    int r =0;
    REP(i,4)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(inside(xx,yy))
        {
            if(i<2&&arr[xx][yy]=='.')
            {
                r = r + dp(xx,yy);
            }
            else if(i==2&&arr[xx][yy]=='.'&&arr[xx+1][yy-1] == 'B')
            {
                r = r + dp(xx,yy);
            }
            else if(i==3&&arr[xx][yy]=='.'&&arr[xx+1][yy+1] == 'B')
            {
                r = r + dp(xx,yy);
            }
        }
    }
    r = r % 1000007;
    return memo[x][y] = r;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int cases;
    scanf("%d",&cases);
    REP(q,cases)
    {
        string cad;
        arr.clear();
        scanf("%d",&n);
        REP(i,n)
        {
            cin>>cad;
            arr.PB(cad);
            REP(j,n)
            {
                if(arr[i][j] == 'W')
                    x= i, y = j;
            }
        }
        mset(memo,-1);
        printf("Case %d: %d\n",q+1,dp(x,y));
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


