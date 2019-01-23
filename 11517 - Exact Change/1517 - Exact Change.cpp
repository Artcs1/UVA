
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

#define inf 10000

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test;
    scanf("%d", &test);
    int payable, N;
    int M[10001], A[101];
    while(test--){
        scanf("%d %d", &payable, &N);
        for(int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
        //memset(M, 0, sizeof(M));
        for(int i = 1; i <= 10000; i++)
            M[i] = inf;
        M[0] = 0;

        for(int i = 1; i <= N; i++)
            for(int j = 10000; j > 0; j--)
                if(j - A[i] >= 0 && M[j - A[i]] + 1 < M[j])
                    M[j] = M[j - A[i]] + 1 ;

        int i;
        for(i = payable; M[i] == inf; i++);

        printf("%d %d\n", i, M[i]);

    }

	return 0;
}


