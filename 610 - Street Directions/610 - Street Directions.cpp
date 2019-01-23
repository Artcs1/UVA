
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
vector<int>ady[1005];
int dfs_num[1005],dfs_low[1005],parent[1005],dfscount=0;
int vis[1005];
// EXPLORED -> UNV = tree edge
// EXPLORED -> EXPLORED = back edge
// EXPLORED -> visited = forward / cross
// UNV -> 0 EXP->1 VIS->2
void dfs(int u)
{
    dfs_num[u]=dfs_low[u]=dfscount++;
    vis[u]=1;
    REP(i,ady[u].size())
    {
        int v = ady[u][i];
        if(dfs_num[v]==-1)
        {
            parent[v]=u;
            dfs(v);
            if(dfs_low[v]>dfs_num[u])
            {
                printf("%d %d\n",u+1,v+1);
                printf("%d %d\n",v+1,u+1);
            }
            else
            {
                printf("%d %d\n",u+1,v+1);
            }
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }
        else if(parent[u]!=v&&vis[v]==1)
        {
                dfs_low[u]=min(dfs_low[u],dfs_low[v]);
                printf("%d %d\n",u+1,v+1);
        }
    }
    vis[u] = 2;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int vez = 1;
    while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
    {
        int u,v;
        REP(i,m)
        {
            scanf("%d %d",&u,&v);
            u--;
            v--;
            ady[u].PB(v);
            ady[v].PB(u);
        }
        mset(dfs_num,-1);
        mset(dfs_low,-1);
        mset(parent,-1);
        mset(vis,0);
        dfscount = 0;
        printf("%d\n\n",vez++);
        REP(i,n)
            if(dfs_num[i]==-1)
                dfs(i);

        printf("#\n");
        REP(i,n)
            ady[i].clear();
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


