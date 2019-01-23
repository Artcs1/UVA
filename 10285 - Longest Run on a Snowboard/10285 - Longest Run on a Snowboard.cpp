
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

int matriz[105][105],memo[105][105],f,c;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool inside(int x,int y )
{
    if(x>=0 && y>=0 && x<f && y<c)
        return true;
    return false;
}

int  dp(int x,int y)
{
    if(memo[x][y]!=-1)
        return memo[x][y];
    int res = 0;
    REP(i,4)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(inside(xx,yy)&&matriz[xx][yy]<matriz[x][y])
            res = max(res, dp(xx,yy));
    }
    res++;
    return memo[x][y] = res;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    scanf("%d",&n);
    REP(x,n)
    {
        string cad;

        cin>>cad;
        scanf("%d %d",&f,&c);
        REP(i,f)
            REP(j,c)
                scanf("%d",&matriz[i][j]);

        mset(memo,-1);
        bool band;
        REP(i,f)
            REP(j,c)
            {
                band = false;
                REP(k,4)
                {
                    int xx = i+dx[k];
                    int yy = j+dy[k];
                    if(inside(xx,yy)&&matriz[xx][yy]<matriz[i][j])
                        band = true;
                }
                if(!band)
                    memo[i][j] = 0;
            }


        int r = 0;

        REP(i,f)
            REP(j,c)
                r = max(r,dp(i,j));

        printf("%s: %d\n",cad.c_str(),r+1);

    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}

