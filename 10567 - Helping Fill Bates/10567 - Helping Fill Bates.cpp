
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

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    VE arr,arr2;
    string cad;
    cin>>cad;
    int t=cad.size();
    vector<int>matriz[64];
    int ind[64];
    mset(ind,0);
    REP(i,t)
        matriz[cad[i]-'A'].PB(i);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string cad1;
        cin>>cad1;
        int tam = cad1.size();
        bool band = true;
        int ini;
        int ind = 0;
        REP(i,tam)
        {
            int v = cad1[i]-'A';
            int lo = lower_bound(all(matriz[v]),ind)-matriz[v].begin();
            if(matriz[v][lo]<ind)
                band = false;
            ind = matriz[v][lo]+1;
            if(i==0)
                ini = ind;
        }
        (!band)?printf("Not matched\n"):printf("Matched %d %d\n",ini-1,ind-1);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


