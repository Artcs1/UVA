
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
    scanf("%d",&n);
    while(n--)
    {
        string cad;
        cin>>cad;
        int t = cad.size();
        int m[t+1][t+1];
        mset(m,0);
        int i = 0;
        do
        {
            REP(j,t)
                m[i+1][j+1]=cad[j]-'0';
            i++;
        }while(i<t&&cin>>cad);

        FOR(i,1,t+1)
            FOR(j,1,t+1)
                m[i][j]=m[i][j]+m[i-1][j]+m[i][j-1]-m[i-1][j-1];

        int maxi = 0;
        REP( i, t)
            REP(j,t)
                FOR(k,i,t)
                    FOR(l,j,t)
                        {
                            int qarea= m[k+1][l+1]-m[i][l+1]-m[k+1][j]+m[i][j];
                            int area= (k-i+1)*(l-j+1);
                            if(area==qarea)
                            {
                                maxi=max(maxi,area);
                                //system("pause");
                            }

                        }
        printf("%d\n",maxi);
        if(n)
            printf("\n");
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


