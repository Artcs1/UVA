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


struct node{
    double x,y;
    node(double _x,double _y)
    {
        x=_x,y=_y;
    }
};
vector<node>arr;
int s;
VE p,r;
void init(int m)
{
    p.resize(m);
    r.resize(m);
    REP(i,m)
        p[i]=i,r[i]=0;
}
int findSet(int i)
{
    return p[i]==i?i:p[i]=findSet(p[i]);
}
void unionSet(int i,int j)
{
    int x=findSet(i),y=findSet(j);
    if(r[x]>r[y])
        p[y]=x;
    else{
        p[x]=y;
        if(r[x]==r[y]) r[y]++;
    }
}
bool isSameSet(int i,int j)
{
    return findSet(i)==findSet(j);
}
bool func(int mid)
{
    p.clear();
    r.clear();
    int tam=arr.size();
    init(tam+2);
    REP(i,tam)
    {
        FOR(j,i+1,tam)
        {
            double d2=hypotl(arr[j].x-arr[i].x,arr[j].y-arr[i].y);
            int d3=(int )d2;
            if(d2-(double)d3!=0.0)
                d3++;
            if(d3<=mid)
                if(!isSameSet(i,j)) unionSet(i,j);
        }
    }
    set<int>myset;
    REP(i,tam)
        myset.insert(findSet(i));
    if(myset.size()<=s)
       return true;
    else
       return false;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double x1,y1;
        scanf("%d",&s);
        arr.clear();
        while(scanf("%lf",&x1)&&x1!=-1)
        {
            scanf("%lf",&y1);
            arr.PB(node(x1,y1));
        }
        int ini=0,fin=300000;
        while(ini<=fin)
        {
            double mid=(ini+fin)/2;
            if(func(mid))
                fin=mid-1;
            else
                ini=mid+1;
        }
        printf("%d\n",ini);

    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


