
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
int in[10000], post[10000], n,temp;
int bst[10000][2], padre2,s , ans,suma ;

void build(int l,int r,int padre,int flag)
{
    if(l>r)
        return;
    int i,p2 = padre2;
    for(i = l ; i <= r ; i++)
        if(in[i] == post[padre2])
            break;

    if(padre!=-1)
        bst[post[padre]][flag] = post[padre2] ;
    padre2--;

    build(i+1,r,p2,1);
    build(l,i-1,p2,0);
}

void tree(int u)
{
    if(u == -1)
        return;

    if(bst[u][0] == -1 && bst[u][1] == -1)
        if(s>suma)
            s= suma, ans = u;

    suma+=bst[u][0];
    tree(bst[u][0]);
    suma-=bst[u][0];
    suma+=bst[u][1];
    tree(bst[u][1]);
    suma-=bst[u][1];

}

int main() {
    string cad,cad1;
    while(getline(cin,cad))
    {
        getline(cin,cad1);
        istringstream iss1(cad);
        istringstream iss2(cad1);
        int i = 0;
        while(iss1>>temp)
            in[i] = temp,i++;

        i=0;
        while(iss2>>temp)
            post[i] = temp,i++;

        n = i;
        padre2 = n-1;

        mset(bst,-1);
        build(0,n-1,-1,0);
        //mdebug(bst,n+1,2);
        suma = post[n-1],s = inf_i;
        int root = post[n-1];
        tree(root);
        printf("%d\n",ans);
    }
    return 0;
}
