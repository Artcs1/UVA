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
static int p[5005],ran[5005],f[5005];

int init(int n)
{
    REP(i,n)
        p[i]=i,ran[i]=0,f[i]=1;
}

int findSet(int i)
{
    return (p[i]==i)?i:(p[i]=findSet(p[i]));
}
void unionSet(int i , int j)
{
    int x=findSet(i),y=findSet(j);
    if(ran[x]>ran[y])
    {
        p[y]=x;
        f[x]+=f[y];
    }
    else
    {
        p[x]=y;
        f[y]+=f[x];
        if(ran[x]==ran[y]) ran[y]++;
    }
}
bool isSameSet(int i,int j)
{
    return findSet(i) == findSet(j);
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

    int t,n,m,v1,v2;

    while(scanf("%d %d",&n,&m)&&(n!=0||m!=0))
    {
        string cad,cad1;
        map<string ,int > mymap;
        int index=0;
        REP(i,n)
        {
            cin>>cad;
            if(mymap.count(cad)<=0)
                mymap[cad]=index++;
        }
        init(n);
        REP(i,m)
        {
            cin>>cad>>cad1;
            if(!isSameSet(mymap[cad],mymap[cad1])) unionSet(mymap[cad],mymap[cad1]);
        }
        //adebug(f,n);
        int res=1;
        REP(i,n)
            res=max(res,f[i]);
        printf("%d\n",res);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


