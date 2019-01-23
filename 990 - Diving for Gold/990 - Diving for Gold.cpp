
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
    int n,m;
    int web = 0;
    while(~scanf("%d %d",&n,&m))
    {
        int v[35],w[35],knap[35][1005],d[35];
        int t;
        scanf("%d",&t);
        REP(i,t)
        {
            scanf("%d %d",&d[i],&v[i]);
            w[i] = d[i]*m + d[i]*(2*m);
            //debug(w[i]);
        }
        mset(knap,0);
        FOR(i,1,t+1)
            FOR(j,1,n+1)
                    if(j-w[i-1]>=0)
                        knap[i][j] = max(knap[i-1][j-w[i-1]]+v[i-1],knap[i-1][j]);
                    else
                        knap[i][j] = knap[i-1][j];
        int vis[35],weight = n;
        mset(vis,0);
        int c= 0;
        RFOR(i,t,1)
        {
            if(knap[i][weight]!=knap[i-1][weight])
            {
                vis[i-1]=1;
                c++;
                weight = weight - w[i-1];
            }
        }
        if(web)
            printf("\n");
        web++;
        printf("%d\n",knap[t][n]);
        printf("%d\n",c);
        REP(i,n)
        {
            if(vis[i])
                printf("%d %d\n",d[i],v[i]);
        }

    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


