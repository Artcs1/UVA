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
int ady[10005];
int p[10005],r[10005],n,a,b,c;

void init(int m)
{
    REP(i,m)
        p[i]=i,r[i]=0;
}
int findSet(int i)
{
    if(i==-1)
        return -1;
    return p[i]==i?i:(p[i]=findSet(p[i]));
}
void unionSet(int i,int j)
{
    int x=findSet(i),y=findSet(j);
    if(r[x]>r[y])
        p[y]=x;
    else
    {
        p[x]=y;
        if(r[x]==r[y]) r[y]++;
    }
}
bool isSameSet(int i,int j)
{
    return findSet(i)==findSet(j);
}
bool enimies(int i,int j)
{
    int x=findSet(i),y=findSet(j);
    REP(k,n)
    {
        if(x==findSet(k)&&findSet(ady[k])==y)
            return true;
    }
    return false;
}
void addenemies(int i,int j)
{
    //debug(i);
    int x,y;
    REP(k,n)
    {
        x=findSet(i),y=findSet(j);
        if(y==findSet(ady[k]))
        {
            if(!isSameSet(x,findSet(k)))
                unionSet(x,findSet(k));
        }
        if(x==findSet(ady[k]))
        {
            if(!isSameSet(y,findSet(k)))
                unionSet(y,findSet(k));
        }

    }
    ady[findSet(i)]=findSet(j);
    ady[findSet(j)]=findSet(i);
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    scanf("%d",&n);
    init(n+2);
    mset(ady,-1);
    //debug(findSet(-1));
    while(scanf("%d %d %d",&a,&b,&c)& (a+b+c!=0))
    {
        if(a==1)
        {
            if(!isSameSet(b,c)&&!enimies(b,c))
                unionSet(b,c);
            else if(enimies(b,c))
                printf("-1\n");
        }
        else if(a==2)
        {
            if(!isSameSet(b,c)&&!enimies(b,c))
                addenemies(b,c);
            else if(isSameSet(b,c))
                printf("-1\n");
        }
        else if(a==3)
            (isSameSet(b,c))?printf("1\n"):printf("0\n");
        else if(a==4)
            (enimies(b,c))?printf("1\n"):printf("0\n");

        //cout<<a<<b<<c<<endl;
        //adebug(p,n);
        //adebug(ady,n);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


