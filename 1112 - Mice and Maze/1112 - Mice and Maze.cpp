
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

vector< ii >ady[105];
int dist[105],n,e,t;

void dijstrak(int u)
{
    dist[u] = 0;
    priority_queue< ii ,vector<ii>,greater<ii> > pq;
    pq.push(ii(0,u));
    while(!pq.empty())
    {
        ii frente = pq.top();
        pq.pop();
        int d = frente.first;
        u = frente.second;
        if(d>dist[u])
            continue;
        REP(i,ady[u].size())
        {
            ii v = ady[u][i];
            if(dist[u] + v.second < dist[v.first])
            {
                dist[v.first ] = dist[u] + v.second ;
                pq.push(ii(dist[v.first],v.first));
            }
        }
    }
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d %d %d",&n,&e,&t);
        int edg;
        scanf("%d",&edg);
        REP(i,edg)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            u--;
            v--;
            ady[v].PB(ii(u,w));
        }
        REP(i,n)
            dist[i] = inf_i;
        dijstrak(e-1);
        int c =0 ;
        REP(i,n)
            if(dist[i]<=t)
                c++;
        printf("%d\n",c);
        if(cases)
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


