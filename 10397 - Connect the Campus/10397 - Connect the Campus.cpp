
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
    int u,v;
    double w;
    node(int _u,int _v,double _w)
    {
        u=_u,v=_v,w=_w;
    }
};

bool cmp(node p1,node p2)
{
    return p1.w<p2.w;
}

int pset[800];

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
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    while(~scanf("%d",&n))
    {
        initSet(n+2);
        int x,y,u,v;
        vector<ii>arr;
        vector<node>E;
        REP(i,n)
        {
            scanf("%d %d",&x,&y);
            arr.PB(ii(x,y));
        }
        REP(i,n)
        {
            FOR(j,i+1,n)
            {
                double weight = hypotl(double(arr[i].first-arr[j].first),double(arr[i].second-arr[j].second));
                E.PB(node(i,j,weight));
            }
        }
        int m;
        scanf("%d",&m);
        REP(i,m)
        {
            scanf("%d %d",&u,&v);
            u--;
            v--;
            unionSet(u,v);
        }
        int t = E.size();
        double mst = 0.0;
        sort(all(E),cmp);
        REP(i,t)
        {
            if(!isSameSet(E[i].u,E[i].v))
            {
                unionSet(E[i].u,E[i].v);
                mst+= E[i].w;
            }
        }
        printf("%.2lf\n",mst);
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


