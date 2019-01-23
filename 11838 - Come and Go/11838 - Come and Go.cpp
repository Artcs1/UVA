
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

bool vis[2005];
vector<int>topo;
void dfs(int u,vector<int>ady[],int tipo)
{
    if(vis[u])
        return;
    vis[u]=true;
    REP(i,ady[u].size())
    {
        int v = ady[u][i];
        dfs(v,ady,tipo);
    }
    if(tipo == 1)
        topo.PB(u);
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,m;
    while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
    {
        topo.clear();
        vector<int>ady[2005],ady2[2005];
        int u,v,w;
        REP(i,m)
        {
            scanf("%d %d %d",&u,&v,&w);
            u--;
            v--;
            if(w==2)
                ady[u].PB(v),ady[v].PB(u),ady2[v].PB(u),ady2[u].PB(v);
            else if(w==1)
                ady[u].PB(v),ady2[v].PB(u);
        }
        mset(vis,false);
        REP(i,n)
            dfs(i,ady,1);
        VE topo2 = topo;
        reverse(all(topo2));
        mset(vis,false);
        int scc=0;
        REP(i,topo2.size())
        {
            if(!vis[topo2[i]])
                dfs(topo2[i],ady2,2),scc++;
        }
        (scc==1)?printf("1\n"):printf("0\n");
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


