
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
#define inf_i (1<<28)-1

vector<int>ady[105];
bool band;
bool vis[105];
void dfs(int u)
{
    if(vis[u])
        return;
    vis[u] = true;
    REP(i,ady[u].size())
    {
        int v= ady[u][i];
        dfs(v);
    }
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    while(~scanf("%d",&n)&&n!=-1)
    {
        int edges,source=0,fin=n-1,v,amount;
        int energy[105];
        REP(i,n)
        {
            scanf("%d %d",&energy[i],&edges);
            energy[i]*=-1;
            REP(j,edges)
            {
                scanf("%d",&v);
                v--;
                ady[i].PB(v);
            }
        }

        int dist[105];
        REP(i,105)
            dist[i] = inf_i;
        dist[source]= -100;

        REP(i,n-1)
            REP(j,n)
                REP(k,ady[j].size())
                {
                    if(dist[j]+energy[ady[j][k]]<0)
                        dist[ady[j][k]] = min(dist[ady[j][k]],dist[j]+energy[ady[j][k]]);
                }
        if(dist[fin]<0)
            printf("winnable\n");
        else
        {
            band = false;
            REP(j,n)
                REP(k,ady[j].size())
                {
                    if(dist[j]+energy[ady[j][k]]<0&&dist[j]+energy[ady[j][k]]<dist[ady[j][k]])
                    {
                        mset(vis,0);
                        dfs(j);
                        band|= vis[fin];
                    }
                }
            (band)?printf("winnable\n"):printf("hopeless\n");
        }

        REP(i,n)
            ady[i].clear();
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


