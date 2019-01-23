
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
#define cubo(x) (x)*(x)*(x)
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

int junctions[205];
vector<ii>ady[205];
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,edges,query,u,v,vez=1,d;
    while(~scanf("%d",&n))
    {
        REP(i,n)
            scanf("%d",&junctions[i]);
        scanf("%d",&edges);
        REP(i,edges)
        {
            scanf("%d %d",&u,&v);
            u--;
            v--;
            ady[u].PB(ii(v,cubo(junctions[v]-junctions[u])));
        }
        int dist[205];
        REP(i,205)
            dist[i] = inf_i;
        dist[0] = 0;

        REP(k,int(n-1))
            REP(i,n)
            {
                REP(j,(int)ady[i].size())
                {
                    if(dist[i]!=inf_i)
                        dist[ady[i][j].first] = min(dist[ady[i][j].first],dist[i]+ady[i][j].second);
                }
            }
        int dist2[205];
        REP(i,205)
            dist2[i] = dist[i];
        bool Negative = false;
            REP(i,n)
                REP(j,(int)ady[i].size())
                    if(dist2[i]!=inf_i)
                        dist2[ady[i][j].first] = min(dist2[ady[i][j].first],dist2[i]+ady[i][j].second);

        scanf("%d",&query);
        printf("Set #%d\n",vez++);
        REP(i,query)
        {
            Negative = false;
            scanf("%d",&d);
            d--;
            if(dist[d]>dist2[d])
                Negative = true;
            (dist[d]<3||dist[d]==inf_i||Negative)?printf("?\n"):printf("%d\n",dist[d]);
        }
        REP(i,205)
            ady[i].clear();
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


