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


int intmax = (int) 1e9;
int N, x, T, K;
int dp[103][23][1005];
int p[105];
int f[105];

int ks(int i, int n, int S){
	int trail = S + (N+1)*T;
	trail = ceil((double) trail * 1.1L); // hmmmmm
	if(trail > (N+1)*x || n > 2*(N+1) ) return -inf_i;
	if(trail == (N+1)*x || i < 0 || n == 2*(N+1)) return 0;
	if(dp[i][n][S] != -1) return dp[i][n][S];
	int temp = max( f[i] + ks(i-1, n+1, S + p[i]), max( 2*f[i] + ks(i-1, n+2, S+2*p[i]), ks(i-1,n,S)));
	return dp[i][n][S] = temp;
}

int main(){
	while(scanf("%d%d%d%d",&N,&x,&T,&K), N+x+T+K != 0){
		for(int i=0;i<K;++i){
			scanf("%d", &p[i]);
			int tot = 0;
			for(int j=0;j<N+1;++j){
				int f;
				scanf("%d",&f);
				tot += f;
			}
			f[i] = tot;
		}

		mset(dp,-1);
		int ans = ks(K-1, 0, 0);
		printf("%.2lf\n", (double) ans / (double) (N+1));
	}
	return 0;
}
