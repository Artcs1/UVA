
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


vector<int>ady[305];
bool cor[305];
bool vis[305];
bool blag;
bool isBipartite(int u)
{
    vis[u]= true;
    bool blag = true;
    REP(i,ady[u].size())
    {
        int v = ady[u][i];
        if(!vis[v])
        {
            cor[v]=1-cor[u];
            blag&= isBipartite(v);
        }
        else if(cor[u]==cor[v])
            blag&= false;
    }
    return blag;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    while(scanf("%d",&n),n!=0)
    {
        REP(i,305)
            ady[i].clear();
        int u,v;
        while(~scanf("%d %d",&u,&v)&&(u!=0||v!=0))
        {
            ady[u-1].PB(v-1);
            ady[v-1].PB(u-1);
        }
        mset(vis,false);
        cor[0]=0;
        blag=isBipartite(0);;

        (blag)?printf("YES\n"):printf("NO\n");
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


