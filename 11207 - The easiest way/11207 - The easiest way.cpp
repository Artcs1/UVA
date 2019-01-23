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

int n;
while(scanf("%d",&n),n)
{
    double x,y,maxl=0.0;
    int ind;
    REP(i,n)
    {
        scanf("%lf %lf",&x,&y);
        if(maxl<min(x/4.0,y))
        {
            maxl=min(x/4.0,y);
            ind=i+1;
        }
        if(maxl<min(x,y/4.0))
        {
            maxl=min(x,y/4.0);
            ind=i+1;
        }
        if(maxl<min(x,y)/2.0)
        {
            maxl=min(x,y)/2.0;
            ind=i+1;
        }

    }
    printf("%d\n",ind);
}
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


