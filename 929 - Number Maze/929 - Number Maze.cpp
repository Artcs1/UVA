
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

int matriz[1000005];
int dist[1000005];
int n,m;

void dijstrak(int u)
{
    dist[u]=matriz[u];
    priority_queue< ii, vector<ii>, greater<ii> >pq;
    pq.push(ii(0,u));
    while(!pq.empty())
    {
        ii frente = pq.top();
        pq.pop();
        int d = frente.first;
        u = frente.second;
        if( d > dist[u]) continue;
        REP(j,4)
        {
            int v = u;
            if(j==0)
            {
                if( u%m !=0)
                    v = u - 1 ;
                else
                    v = -1;
            }
            else if(j==1)
            {
                if( (u+1)%m != 0 )
                    v = u + 1;
                else
                    v = -1;
            }
            else if(j==2)
                v = u + m;
            else if(j==3)
                v = u - m ;

            if(v>=0 && v <(n*m))
            {
                if(dist[u]+matriz[v] < dist[v])
                {
                    dist[v] = dist[u]+matriz[v];
                    pq.push(ii(dist[v],v));
                }
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
    REP(i,cases)
    {
        scanf("%d %d",&n,&m);
        REP(j,n)
            REP(k,m)
                scanf("%d",&matriz[j*m+k]),dist[j*m+k] = inf_i;
        dijstrak(0);
        printf("%d\n",dist[(n*m)-1]);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


