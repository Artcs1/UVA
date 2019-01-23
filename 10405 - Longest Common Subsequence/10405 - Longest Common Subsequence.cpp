
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


string lcs ="";
string c1,c2;
int t1,t2;
int memo[1005][1005];
int posiciones[1005][1005];

int dp(int i,int j)
{
	if( i == t1 || j == t2 )
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
	int res = 0;
	if(c1[i] == c2[j])
		res = 1 + dp(i+1,j+1);
	res = max(res,max(dp(i+1,j),dp(i,j+1)));
	memo[i][j] =res;
	return memo[i][j];
}

void solve(int i,int j)
{
	if(i==t1||j==t2)
		return;
	if(c1[i]==c2[j])
	{
		lcs += c1[i];
		solve(i+1,j+1);
	}
	else 
	{
		if(memo[i+1][j]>memo[i][j+1])
			solve(i+1,j);
		else
			solve(i,j+1);
	}
}
int main()
{

	while(getline(cin,c1))
	{
		getline(cin,c2);
		t1 = c1.size();
		t2 = c2.size();
		memset(memo,-1,sizeof memo);
		printf("%d\n",dp(0,0));
		mdebug(memo,t1,t2);
		solve(0,0);
		printf("%s\n",lcs.c_str());
		lcs = "";
	}


}
