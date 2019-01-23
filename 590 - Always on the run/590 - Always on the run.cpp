
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

int n , m, q,temp;
vector<int>ady[20][20];
int memo[20][1005];

int dp(int ciudad,int time)
{
    if(ciudad ==n-1 && time == m)
        return 0;
    if(time == m)
        return inf_i;
    if(memo[ciudad][time]!=-1)
        return memo[ciudad][time];
    int r = inf_i;
    REP(i,n)
    {
        int tam = ady[ciudad][i].size();
        if(i!=ciudad&&ady[ciudad][i][time%tam]!=0)
            r = min(r , dp(i,time+1)+ady[ciudad][i][time%tam]);
    }
    return memo[ciudad][time] = r;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int vez = 1;
    while(~scanf("%d %d",&n,&m)&&(n!=0 || m!=0))
    {
        REP(i,n)
            REP(j,n)
            {
                if(i!=j)
                {
                    scanf("%d",&q);
                    REP(k,q)
                    {
                        scanf("%d",&temp);
                        ady[i][j].PB(temp);
                    }
                }
            }

        mset(memo,-1);
        printf("Scenario #%d\n",vez++);
        int val = dp(0,0);
        (val == inf_i)?printf("No flight possible.\n"):printf("The best flight costs %d.\n",val);

        printf("\n");


        REP(i,20)
            REP(j,20)
                ady[i][j].clear();
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


