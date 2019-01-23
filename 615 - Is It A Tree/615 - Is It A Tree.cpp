
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

int pset[100005];

void initSet(int n)
{
    REP(i,n)
        pset[i] = i ;
}

int findSet(int i)
{
    return (pset[i] == i )? i : pset[i] = findSet(pset[i]);
}

void unionSet(int i,int j)
{
    int x = findSet(i),y = findSet(j);
    pset[x]= y;
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
    int n,m,vez =1 ;
    while(~scanf("%d %d",&n,&m)&&(n>=0||m>=0))
    {
        if(n == 0 && m ==0 )
        {
            printf("Case %d is a tree.\n",vez++);
            continue;
        }
        bool band = true;
        int index = 0;
        initSet(100005);
        map<int,int> mymap;
        do{
            if(mymap.count(n)<=0)
                mymap[n] = index++;
            if(mymap.count(m)<=0)
                mymap[m] = index++;
            if(!isSameSet(mymap[n],mymap[m]))
                unionSet(mymap[n],mymap[m]);
            else
                band = false;
        } while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0));
        set<int>myset;
        REP(i,index)
            myset.insert(findSet(i));
        if(myset.size()!=1)
            band = false;
        (band)?printf("Case %d is a tree.\n",vez++):printf("Case %d is not a tree.\n",vez++);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


