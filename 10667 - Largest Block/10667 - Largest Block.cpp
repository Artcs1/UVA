
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

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        int matriz[n+1][n+1];
        mset(matriz,0);
        FOR(i,1,n+1)
            FOR(j,1,n+1)
                matriz[i][j] = 1  ;
        int m;
        scanf("%d",&m);
        REP(i,m)
        {
            int r1,c1,r2,c2;
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            FOR(j,r1,r2+1)
                FOR(k,c1,c2+1)
                    matriz[j][k] = 0;
        }
        FOR(i,1,n+1)
            FOR(j,1,n+1)
                {
                    matriz[i][j] = matriz[i][j] + matriz[i-1][j] + matriz[i][j-1] - matriz[i-1][j-1];
                }


        int maxi=0;
        FOR(i,1,n+1)
            FOR(j,1,n+1)
                FOR(k,i,n+1)
                    FOR(l,j,n+1)
                    {
                        int r = matriz[k][l] - matriz[k][j-1] - matriz[i-1][l] + matriz[i-1][j-1];
                        if(r == (k-i+1)*(l-j+1))
                            maxi = max(maxi,r);
                    }
        printf("%d\n",maxi);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


