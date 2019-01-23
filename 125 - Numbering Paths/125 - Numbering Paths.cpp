
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
    int n,u,v,vez=0;
    while(~scanf("%d",&n))
    {
        int M[405][405],maxi=0;
        mset(M,0);
        REP(i,n)
        {
            scanf("%d %d",&u,&v);
            maxi = max(maxi,u);
            maxi = max(maxi,v);
            M[u][v] += 1;
        }

        maxi++;
        REP(k,maxi)
            REP(i,maxi)
                REP(j,maxi)
                    if(M[i][k]*M[k][j])
                        M[i][j] += (M[i][k]*M[k][j]);

        REP(k,maxi)
            if(M[k][k])
                REP(i,maxi)
                    REP(j,maxi)
                    if(M[i][k]&&M[k][j])
                        M[i][j] = -1;

        printf("matrix for city %d\n",vez++);
        REP(i,maxi)
            REP(j,maxi)
                (j==maxi-1)?printf("%d\n",M[i][j]):printf("%d ",M[i][j]);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


