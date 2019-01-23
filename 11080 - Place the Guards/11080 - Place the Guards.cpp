
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

vector<int>ady[205];
vector<int>color;
int val;
bool bipartite(int u)
{
    queue<int>q;
    color[u]=0;
    q.push(u);
    int zero=0,uno=0;
    while(!q.empty())
    {
        u= q.front();
        if(color[u]==0)
            zero++;
        else if(color[u]==1)
            uno++;
        q.pop();
        REP(i,ady[u].size())
        {
            int v=ady[u][i];
            if(color[v]==inf_i)
            {
                color[v]= 1 - color[u];
                q.push(v);
            }
            else if(color[v]==color[u])
                return false;
        }
    }
    if(zero==0||uno==0)
        val = 1;
    else
        val = min(zero,uno);

    return true;
}


int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    scanf("%d",&n);
    REP(i,n)
    {
        REP(i,205)
            ady[i].clear();
        int c,p;
        scanf("%d %d",&c,&p);
        REP(j,p)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            ady[u].PB(v);
            ady[v].PB(u);
        }
        color.clear();
        color.resize(c,inf_i);

        bool band =true;
        int r =0;
        REP(j,c)
            if(color[j]==inf_i)
            {
                val = inf_i;
                band&=bipartite(j);
                r+=val;
            }


        if(!band)
            printf("-1\n");
        else
            printf("%d\n",r);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


