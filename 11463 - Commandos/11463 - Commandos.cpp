
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

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int cases,n,m,u,v;
    scanf("%d",&cases);
    REP(c,cases)
    {
        int M[105][105];

        REP(i,105)
            REP(j,105)
                M[i][j] = inf_i;

        REP(i,105)
            M[i][i] = 0;

        scanf("%d %d",&n,&m);

        REP(j,m)
        {
            scanf("%d %d",&u,&v);
            M[u][v] = 1;
            M[v][u] = 1;
        }

        REP(k,n)
            REP(i,n)
                REP(j,n)
                    M[i][j] = min(M[i][j],M[i][k]+M[k][j]);

        int s,d;
        scanf("%d %d",&s,&d);

        int r = 0;
        REP(i,n)
        {
            if(M[s][i]!=inf_i&&M[i][d]!=inf_i)
                r = max(r,M[s][i]+M[i][d]);
        }
        printf("Case %d: %d\n",c+1,r);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


