
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

vector<int>ady[105];
bool articulation[105];
int dfs_low[105],dfs_num[105],raiz,children,cnt,parent[105];

void dfs(int u)
{
    dfs_num[u]=dfs_low[u]=cnt++;
    REP(i,ady[u].size())
    {
        int v=ady[u][i];
        if(dfs_num[v]==-1)
        {
            parent[v]=u;
            if(u==raiz)
                children++;
            dfs(v);
            if(dfs_low[v]>=dfs_num[u])
                articulation[u]=true;
            dfs_low[u]=min(dfs_low[v],dfs_low[u]);
        }
        else if(v!=parent[u])
        {
            dfs_low[u] = min(dfs_num[v],dfs_low[u]);
        }
    }

}


int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    string cad;
    int n,value;
    while(~scanf("%d",&n),n)
    {
        REP(i,105)
            ady[i].clear();
        cin.ignore();
        while(getline(cin,cad))
        {
            int ind;
            istringstream iss(cad);
            iss>>ind;
            if(ind==0)
                break;
            while(iss>>value)
            {
                ady[ind-1].PB(value-1);
                ady[value-1].PB(ind-1);
            }
        }
        mset(parent,-1);
        mset(dfs_num,-1);
        mset(dfs_low,-1);
        mset(articulation,false);
        cnt=0;
        REP(i,n)
        {
            if(dfs_num[i]==-1)
            {
                raiz = i, children = 0;
                dfs(i);
                articulation[i] = (children>1);
            }
        }
        int c = 0;
        REP(i,n)
            if(articulation[i])
                c++;
        printf("%d\n",c);
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


