
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

vector<int>ady[2505];
int recorrido[2505];

void bfs(int u)
{
    queue<int>q;
    q.push(u);
    recorrido[u]=0;
    while(!q.empty())
    {
        int u2 = q.front();
        q.pop();
        REP(i,ady[u2].size())
        {
            int v = ady[u2][i];
            if(recorrido[v] == -1)
            {
                recorrido[v]= recorrido[u2]+1;
                q.push(v);
            }
        }
    }
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
        int number,v;
        scanf("%d",&number);
        REP(j,number)
        {
            scanf("%d",&v);
            ady[i].PB(v);
        }
    }
    int q,source;
    int freq[2505];
    scanf("%d",&q);
    REP(i,q)
    {
        scanf("%d",&source);
        mset(recorrido,-1);
        bfs(source);

        mset(freq,0);
        REP(j,2505)
        {
            if(recorrido[j]!=-1)
                freq[recorrido[j]]++;
        }
        if(freq[1]==0)
            printf("0\n");
        else
        {
            int daily=0,boom;
            FOR(j,1,2505)
            {
                if(freq[j]>daily)
                {
                    daily = freq[j];
                    boom = j;
                }
            }
            printf("%d %d\n",daily,boom);
        }
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


