
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

struct Edge{
    int u,v,w;
    Edge(int _u,int _v,int _w)
    {
        u=_u,v=_v,w=_w;
    }
};

int pset[1005];

void initSet(int n)
{
    REP(i,n)
        pset[i]=i;
}

int findSet(int i)
{
    return (pset[i]==i)?i:pset[i]=findSet(pset[i]);
}
void unionSet(int i,int j)
{
    int x=findSet(i),y=findSet(j);
    pset[x]=y;
}

bool isSameSet(int i,int j)
{
    if( findSet(i)==findSet(j))
        return true;
    return false;
}
bool cmp(Edge p1,Edge p2)
{
    return p1.w<p2.w;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,m;
    while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
    {
        initSet(n+2);
        vector<Edge>EdgeList;
        VE res;
        int u,v,w;
        REP(i,m)
        {
            scanf("%d %d %d",&u,&v,&w);
            EdgeList.PB(Edge(u,v,w));
        }
        sort(all(EdgeList),cmp);
        REP(i,EdgeList.size())
        {
            if(!isSameSet(EdgeList[i].u,EdgeList[i].v))
                unionSet(EdgeList[i].u,EdgeList[i].v);
            else
                res.PB(EdgeList[i].w);
        }
        if(res.size()==0)
            printf("forest\n");
        else
            REP(i,res.size())
                (i==(int)(res.size()-1))?printf("%d\n",res[i]):printf("%d ",res[i]);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


