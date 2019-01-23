
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

vector<int>ady[5005];
int x;
bool vis[5005];
void dfs(int u,int distancias[])
{
    vis[u] = true;
    REP(i,ady[u].size())
    {
        int v= ady[u][i];
        if(!vis[v])
        {
            distancias[v] = distancias[u]+1;
            dfs(v,distancias);
        }

    }
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,m,v;
    while(~scanf("%d",&n))
    {
        REP(i,n)
        {
            scanf("%d",&m);
            REP(j,m)
            {
                scanf("%d",&v);
                v--;
                ady[i].PB(v);
            }
        }
        int dist[5005],d1[5005],d2[5005];
        mset(vis,false);
        dist[0] = 0;
        dfs(0,dist);

        int maxi =0 , ind ;
        REP(i,n)
            if(maxi<dist[i])
                maxi = dist[i],ind = i;

        mset(vis,false);
        d1[ind]  = 0;
        dfs(ind,d1);

        maxi = 0;
        REP(i,n)
            if(maxi<d1[i])
                maxi = d1[i],ind = i;

        mset(vis,false);
        d2[ind] = 0 ;
        dfs(ind,d2);


        int mini = inf_i ;
        maxi = 0;
        REP(i,n)
        {
            dist[i] = max(d1[i],d2[i]);
            maxi = max(maxi,dist[i]);
            mini = min(mini,dist[i]);
        }

        printf("Best Roots  :");
        REP(i,n)
            if(dist[i] == mini)
                printf(" %d",i+1);
        printf("\n");


        printf("Worst Roots :");
        REP(i,n)
            if(dist[i] == maxi)
                printf(" %d",i+1);
        printf("\n");

        REP(i,n)
            ady[i].clear();
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


