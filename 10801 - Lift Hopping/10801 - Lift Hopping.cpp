
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

int weight[10];
int dist[505];
vector< ii > ady[505];
priority_queue< ii,vector<ii> , greater<ii> > pq;

void dijstrak()
{
   while(!pq.empty())
   {
       ii frente = pq.top();
       pq.pop();
       int d = frente.first;
       int u = frente.second;
       if(d>dist[u])
          continue;
       REP(i,ady[u].size())
       {
            ii v = ady[u][i];
            if(dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
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

    int n,dest;
    while(~scanf("%d %d",&n,&dest))
    {
        REP(i,n)
            scanf("%d",&weight[i]);
        vector<int>same[105];
        cin.ignore();
        REP(i,n)
        {
            string cad;
            getline(cin,cad);
            istringstream iss(cad);
            int ant,next;
            iss>> ant ;
            same[ant].PB(ant+(i*100));
            while( iss >> next)
            {
                ady[ant+(i*100)].PB(ii(next+(i*100),weight[i]*(abs(next -ant))));
                ady[next+(i*100)].PB(ii(ant+(i*100),weight[i]*(abs(next -ant))));
                ant = next;
                same[next].PB(next+(i*100));
            }
        }
        REP(i,100)
        {
            for(int j=0;j<int(same[i].size());j++)
            {
                for(int k=j+1;k<int(same[i].size());k++)
                {
                     ady[same[i][j]].PB(ii(same[i][k],60));
                     ady[same[i][k]].PB(ii(same[i][j],60));
                }
            }
        }
        REP(i,500)
            dist[i]=inf_i;
        REP(i,n)
        {
            pq.push(ii(0,(i*100)));
            dist[i*100] = 0;
        }
        dijstrak();
        int mini = inf_i;
        REP(i,n)
            mini = min(mini,dist[dest+(i*100)]);

        (mini == inf_i)?printf("IMPOSSIBLE\n"):printf("%d\n",mini);

        REP(i,105)
            same[i].clear();
        REP(i,505)
            ady[i].clear();
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


