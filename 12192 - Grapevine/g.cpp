

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
    int n,m,temp,u,v;
    while(~scanf("%d %d",&n,&m))
    {
        if(n == 0 && m == 0) break;
        int matriz[n][m];
        REP(i,n)
            REP(j,m)
                scanf("%d",&matriz[i][j]);
        int q;
        scanf("%d",&q);
        REP(i,q)
        {
            scanf("%d %d",&u,&v);
            int carry=0;
            REP(j,n)
            {
                int l=lower_bound(matriz[j],matriz[j]+m,u)-matriz[j];
                FOR(k,carry,n)
                {
                    if(j+k>=n||l+k>=m||matriz[j+k][l+k]>v) break;
                    if(k+1>carry) carry = k+1;
                }
            }
            printf("%d\n",carry);
        }
        printf("-\n");
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}

