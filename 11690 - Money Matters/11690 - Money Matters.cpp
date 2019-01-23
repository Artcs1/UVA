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

int p[10005],ran[10005],costo[10005];

void init(int n)
{
    REP(i,n)
        p[i]=i,ran[i]=0;
}
int findSet(int i)
{
    return (p[i]==i)?i:p[i]=findSet(p[i]);
}
void unionSet(int i,int j)
{
    int x=findSet(i),y=findSet(j);
    if(ran[x]>ran[y])
    {
        p[y]=x;
        costo[x]+=costo[y];
    }
    else
    {
        p[x]=y;
        costo[y]+=costo[x];
        if(ran[x]==ran[y]) ran[y]++;
    }
}

bool isSameSet(int i,int j)
{
    return findSet(i)==findSet(j);
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        init(a);
        REP(i,a)
        {
            scanf("%d",&costo[i]);
        }
        REP(i,b)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            if(!isSameSet(u,v)) unionSet(u,v);
        }
        bool band=true;
        REP(i,a)
        {
            int p=findSet(i);
            if(costo[p]!=0)
                band=false;
        }
        //adebug(costo,a);
        (band)?printf("POSSIBLE\n"):printf("IMPOSSIBLE\n");
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


