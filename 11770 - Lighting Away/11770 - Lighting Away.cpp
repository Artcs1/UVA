
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

vector<int>ady[10005];
vector<int>topo;
bool vis[10005];

void dfs(int u,int tipo)
{
    if(vis[u])
        return;
    vis[u]=true;
    REP(i,ady[u].size())
    {
        int v = ady[u][i];
        dfs(v,tipo);
    }
    if(tipo==1)
        topo.PB(u);
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int cases;
    scanf("%d",&cases);
    REP(i,cases)
    {
        int scc = 0;
        int n,m,u,v;
        topo.clear();
        scanf("%d %d",&n,&m);
        REP(j,m)
        {
            scanf("%d %d",&u,&v);
            u--;
            v--;
            ady[u].PB(v);
        }
        /*REP(j,n)
        {
            printf("%d ->",j);
            REP(k,ady[j].size())
            {
                printf(" %d",ady[j][k]);
            }
            printf("\n");
        }*/
        mset(vis,false);
        REP(j,n)
        {
            if(!vis[j])
                dfs(j,1);
        }
        reverse(all(topo));
        //adebug(topo,topo.size());
        mset(vis,false);
        REP(j,n)
        {
            int val = topo[j];
            if(!vis[val])
                dfs(val,2),scc++;
        }
        printf("Case %d: %d\n",i+1,scc);
        REP(j,n)
            ady[j].clear();
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


