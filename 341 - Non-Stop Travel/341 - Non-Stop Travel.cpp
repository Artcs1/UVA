
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

int M[405][405];
int P[405][405];

void printpath(int i,int j)
{
    if(i!=j)
        printpath(i,P[i][j]);

    printf(" %d",j+1);
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,t,v,w,vez = 1;
    while(~scanf("%d",&n)&&n!=0)
    {

        REP(i,405)
            REP(j,405)
                P[i][j] = i,M[i][j]=inf_i;

        REP(i,405)
            M[i][i] = 0;

        REP(i,n)
        {
            scanf("%d",&t);
            REP(j,t)
            {
                scanf("%d %d",&v,&w);
                v--;
                M[i][v] = w;
            }
        }

        REP(k,n)
            REP(i,n)
                REP(j,n)
                    if(M[i][j]>M[i][k]+M[k][j])
                    {
                        M[i][j] = M[i][k] + M[k][j];
                        P[i][j] = P[k][j];
                    }

        int s,d;
        scanf("%d %d",&s,&d);
        s--,d--;

        printf("Case %d: Path =",vez++);
        printpath(s,d);
        printf("; %d second delay\n",M[s][d]);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


