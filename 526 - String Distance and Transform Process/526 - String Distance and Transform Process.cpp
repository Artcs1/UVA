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


int t1,t2;
int memo[100][100];
string cad,cad1;

int dp(int i,int j)
{
    if(i==0 && j==0)
        return memo[i][j]= 0;
    if(i==0)
        return memo[i][j]= j;
    if(j==0)
        return memo[i][j]=i;
    if(memo[i][j]!=-1)
        return memo[i][j];
    int res = 1e9 ;
    if(cad[i]==cad1[j])
        res = dp(i-1,j-1);
    else
        res = 1+dp(i-1,j-1);
    res = min(res,1+min(dp(i-1,j),dp(i,j-1)));
    return memo[i][j] = res;
}

int main()
{
    while(getline(cin,cad)&&cad!="")
    {
        getline(cin,cad1);
        t1 = cad.size();
        t2 = cad1.size();
        memset(memo,-1,sizeof memo);
        printf("%d\n",dp(t1-1,t2-1));
        mdebug(memo,t1,t2);
    }
    return 0;
}
