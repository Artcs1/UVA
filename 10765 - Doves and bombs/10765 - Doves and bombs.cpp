
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

vector<int>ady[10005];
int dfs_num[10005],dfs_low[10005],parent[10005],articulation[10005];
int dfscount,children,dfsRoot;


void dfs(int u)
{
    dfs_num[u]=dfs_low[u]=dfscount++;
    REP(i,ady[u].size())
    {
        int v=ady[u][i];
        if(dfs_num[v]==-1)
        {
            parent[v]=u;
            if(u==dfsRoot)
                children++;
            dfs(v);
            if(dfs_low[v]>=dfs_num[u])
                articulation[u]++;
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }
        else if(parent[u]!=v)
        {
            dfs_low[u]=min(dfs_num[v],dfs_low[u]);
        }
    }
}


bool cmp(ii p1,ii p2)
{
    if(p1.second == p2.second)
        return p1.first<p2.first;
    return p1.second>p2.second;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,m;
    while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
    {
        int u,v;
        while(~scanf("%d %d",&u,&v)&&(u!=-1||v!=-1))
        {
            ady[u].PB(v);
            ady[v].PB(u);
        }
        mset(dfs_low,-1);
        mset(dfs_num,-1);
        mset(parent,-1);
        mset(articulation,0);
        dfscount=0;
        REP(i,n)
            if(dfs_num[i]==-1)
            {
                children = 0 ,dfsRoot = i;
                dfs(i);
                articulation[i] = children-1;
            }

        vector< ii >arr;
        REP(i,n)
            arr.PB(ii(i,articulation[i]+1));
        sort(all(arr),cmp);
        REP(i,m)
            printf("%d %d\n",arr[i].first,arr[i].second);
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


