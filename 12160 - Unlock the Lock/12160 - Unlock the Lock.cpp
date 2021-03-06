
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

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int inicio,fin,path;
    int vez = 1;
    while(scanf("%d %d %d",&inicio,&fin,&path)&&(inicio!=0||fin!=0||path!=0))
    {
        vector<int>cam;
        int v;
        REP(i,path)
        {
            scanf("%d",&v);
            cam.PB(v);
        }
        int vis[10005];
        mset(vis,-1);
        queue<int>q;
        q.push(inicio);
        vis[inicio]=0;
        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            REP(i,path)
            {
                int newv = (val + cam[i])%10000;
                if(vis[newv] == -1)
                {
                    q.push(newv);
                    vis[newv] = vis[val]+1;
                }
            }
        }
        if(vis[fin] == -1)
            printf("Case %d: Permanently Locked\n",vez++);
        else
            printf("Case %d: %d\n",vez++,vis[fin]);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


