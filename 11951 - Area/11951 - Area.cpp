
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
    int cases;
    scanf("%d",&cases);
    REP(i,cases)
    {
        int n,t;
        lli p;
        scanf("%d %d %lld",&n,&t,&p);
        lli m[105][105];
        mset(m,0);
        REP(i,n)
            REP(j,t)
                scanf("%lld",&m[i+1][j+1]);
        FOR(i,1,n+1)
            FOR(j,1,t+1)
                m[i][j]=m[i][j]+m[i-1][j]+m[i][j-1]-m[i-1][j-1];

        lli aream = 0,r=inf_ll;
        REP( i, n)
            REP(j,t)
                FOR(k,i,n)
                    FOR(l,j,t)
                        {
                            lli qarea= m[k+1][l+1]-m[i][l+1]-m[k+1][j]+m[i][j];
                            lli area = (lli)(k-i+1)*(lli)(l-j+1);
                            if(aream<=area&&qarea<=p)
                            {
                                if(aream==area)
                                    r = min(r,qarea);
                                else
                                    r = qarea;
                                aream=max(aream,area);

                                //system("pause");
                            }

                        }
        printf("Case #%d: %lld %lld\n",i+1,aream,(r==inf_ll)?0:r);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


