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

lli gcd(lli a,lli b)
{
    return b==0?a:gcd(b,a%b);
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    scanf("%d",&n);
    string cad;
    while(n--)
    {
        cin>>cad;
        lli l1=0,r1=1,l2=1,r2=1,l3=1,r3=0;
        REP(i,cad.size())
        {
            if(cad[i]=='R')
            {
                l1=l2,r1=r2;
                l2=(l1+l3),r2=(r1+r3);
            }
            else if(cad[i]=='L')
            {
                l3=l2,r3=r2;
                l2=(l1+l3),r2=(r1+r3);
            }
        }
        printf("%lld/%lld\n",l2/gcd(l2,r2),r2/gcd(l2,r2));
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


