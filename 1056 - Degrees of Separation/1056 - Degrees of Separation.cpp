
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

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,m,vez=1;
    while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
    {
        map<string , int > mymap;
        string cad,cad1;
        int M[55][55],index =0;
        mset(M,0);
        REP(i,55)
            REP(j,55)
                if(i!=j)
                M[i][j] = inf_i;

        REP(i,m)
        {
            cin>>cad>>cad1;
            if(mymap.count(cad)<=0)
                mymap[cad]=index++;
            if(mymap.count(cad1)<=0)
                mymap[cad1]=index++;
            M[mymap[cad]][mymap[cad1]] = 1;
            M[mymap[cad1]][mymap[cad]] = 1;
        }

        //mdebug(M,n,n);
        REP(k,n)
            REP(i,n)
                REP(j,n)
                    M[i][j] = min(M[i][j],M[i][k]+M[k][j]);

        int r = 0;
        REP(i,n)
            REP(j,n)
                r = max(r,M[i][j]);

        printf("Network %d: ",vez++);
        if(r == inf_i)
            printf("DISCONNECTED\n\n");
        else
            printf("%d\n\n",r);

    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


