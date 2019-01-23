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
#define inf_i (1<<31)-1

vector<int>ady[105];
char color[105];
VE arr;
int cases,n,e,u,v,ans;

void solution(int u)
{
    if(u==n)
    {
        int b=0,w=0;
        //adebug(color,n);
        REP(i,n)
            (color[i]=='B')?b++:w++;
        //debug(b);
        //debug(w);
        //debug(ans);
        //system("pause");
        if(b>ans)
        {
            ans=b;
            arr.clear();
            REP(i,n)
                if(color[i]=='B')
                    arr.PB(i+1);
        }
        //adebug(arr,arr.size());
        return;
    }
    bool canBlack=true;
    for(int i=0;i<ady[u].size();i++)
    {
        if(color[ady[u][i]]=='B')
            canBlack=false;
    }
    if(canBlack)
    {
        color[u]='B';
        solution(u+1);
    }
    color[u]='W';
    solution(u+1);
    color[u]='U';
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    scanf("%d",&cases);
    REP(i,cases)
    {
        arr.clear();
        scanf("%d %d",&n,&e);
        REP(j,n)
            ady[j].clear();
        REP(j,n)
            color[j]='U';
        REP(j,e)
        {
            scanf("%d %d",&u,&v);
            ady[u-1].PB(v-1);
            ady[v-1].PB(u-1);
        }
        ans=0;
        solution(0);
        printf("%d\n",arr.size());
        REP(j,arr.size())
            (j==0)?printf("%d",arr[j]):printf(" %d",arr[j]);
        printf("\n");
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}




