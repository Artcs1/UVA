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
static int p[30005],ran[30005],f[30005];

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

   int n,m;
   while(scanf("%d %d",&n,&m),(n!=0||m!=0))
   {
        init(n);
        int temp,temp2,tam;
        REP(i,m)
        {
            scanf("%d",&tam);
            if(tam>0)
                scanf("%d",&temp);
            REP(j,tam-1)
            {
                temp2=temp;
                scanf("%d",&temp);
                if(!isSameSet(temp,temp2)) unionSet(temp,temp2);

            }
        }
        int x=findSet(0);
        printf("%d\n",f[x]);
   }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}



