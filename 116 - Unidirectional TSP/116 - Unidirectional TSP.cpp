
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

int M[105][105];
int n,m;
int memo[105][105];
int temp[105][105];
int dp(int i,int j)
{
    if(j==m)
        return 0;
    if(memo[i][j]!=-1)
        return memo[i][j];
    int v=inf_i;
    v = M[i][j]+min(dp((i-1+n)%n,j+1),min(dp((i+1)%n,j+1),dp(i,j+1)));
    return memo[i][j]=v;
}

vector<int> recover(int i)
{
    VE res;
    REP(x,m-1)
    {
        res.PB(i+1);
        vector<int>sorted;
        sorted.PB(i);
        sorted.PB((i+1)%n);
        sorted.PB((i-1+n)%n);
        sort(all(sorted));
        if(memo[i][x]-M[i][x]==memo[sorted[0]][x+1])
            i = sorted[0];
        else if(memo[i][x]-M[i][x]==memo[sorted[1]][x+1])
            i = sorted[1];
        else
            i = sorted[2];
    }
    res.PB(i+1);
    return res;
}


int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    while(~scanf("%d %d",&n,&m))
    {
        REP(i,n)
            REP(j,m)
                scanf("%d",&M[i][j]);
        int amount = inf_i;
        int ind = 0;
        REP(i,n)
        {
            mset(memo,-1);
            int v = dp(i,0);
            if(amount>v)
            {
                amount = v;
                ind = i;
            }
        }
        mset(memo,-1);
        dp(ind,0);
        VE R = recover(ind);
        REP(i,R.size())
            (i==(int)R.size()-1)?printf("%d\n",R[i]):printf("%d ",R[i]);
        printf("%d\n",amount);
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}



