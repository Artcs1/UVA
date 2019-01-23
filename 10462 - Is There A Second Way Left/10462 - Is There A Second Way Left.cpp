
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


struct node{
    int u,v, w;
    node(int _u,int _v,int _w)
    {
        u=_u,v=_v,w=_w;
    }
};
int nodos;

bool cmp(node p1,node p2)
{
    return p1.w<p2.w;
}

int pset[105],mst;
bool vis[205];
vector<int> MST;
void initSet(int n)
{
    REP(i,n)
        pset[i] = i;
}

int findSet(int i)
{
    return (pset[i]==i)?i:pset[i]=findSet(pset[i]);
}

void unionSet(int i,int j)
{
    int x = findSet(i), y = findSet(j);
    pset[x]=y;
}

bool isSameSet(int i,int j)
{
    if(findSet(i)==findSet(j))
        return true;
    return false;
}

int kruskal(vector<node>E,int tipo)
{
        initSet(nodos+2);
        int scc = nodos;
        REP(j,E.size())
        {
            if(!isSameSet(E[j].u,E[j].v)&&vis[j]==false)
            {
                if(tipo == 1)
                    MST.PB(j);
                unionSet(E[j].u,E[j].v);
                scc--;
                mst+= E[j].w;
            }
        }
        return scc;
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
        vector<node>E;
        int edges,u,v,w;
        scanf("%d %d",&nodos,&edges);
        REP(j,edges)
        {
            scanf("%d %d %d",&u,&v,&w);
            u--;
            v--;
            E.PB(node(u,v,w));
        }
        sort(all(E),cmp);
        MST.clear();
        mset(vis,false);
        int scc = kruskal(E,1);

        printf("Case #%d : ",i+1);
        if(scc>1)
            printf("No way\n");
        else
        {
            int r = inf_i;
            REP(j,MST.size())
            {
                mset(vis,false);
                vis[MST[j]] = true;
                mst = 0;
                scc = kruskal(E,2);

                if(scc==1)
                    r = min(r,mst);
            }
            if(r == inf_i )
                printf("No second way\n");
            else
                printf("%d\n",r);
        }
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


