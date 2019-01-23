
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

int n,m;
vector<int>ady[105],topo;
bool vis[105];
void dfs(int u)
{

    if(vis[u])
        return;
    vis[u] = true;
    REP(i,ady[u].size())
    {
        int v = ady[u][i];
        dfs(v);
    }
    topo.PB(u);
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int vez = 1;
    while(~scanf("%d",&n)&&n!=0)
    {
        scanf("%d",&m);
        m--;
        int u,v;
        while(~scanf("%d %d",&u,&v)&&(u!=0||v!=0))
        {
            u--,v--;
            ady[u].PB(v);
        }
        mset(vis,false);

        dfs(m);

        int dist[105];
        mset(dist,0);
        reverse(all(topo));

        //adebug(topo,topo.size());
        int r = 0,s = m;
        REP(i,topo.size())
        {
            u = topo[i];
            REP(j,ady[u].size())
            {
                v = ady[u][j];
                if(dist[u]+1>=dist[v])
                {
                    dist[v] = dist[u]+1;
                    if(r<dist[v])
                    {
                        r = dist[v];
                        s = v;
                    }
                    else if(r == dist[v])
                        s = min(s,v);
                }
            }

        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",vez++,m+1,r,s+1);
        topo.clear();
        REP(i,105)
            ady[i].clear();
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


