
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

int F(int n)
{
    int c1=0,c2=0,c3=0,c4=0;
    if(n<100)
        c1 = n;
    else if(n<10000)
        c1 = 100,c2 = n-100;
    else if(n<1000000)
        c1 = 100 , c2 = 9900 , c3 = n - 10000;
    else
        c1 = 100 , c2 = 9900 , c3= 990000, c4 = n-1000000;

    return c1*2+c2*3+c3*5+c4*7;
}
int F2(int W1,int w)
{
    int W2 = w - W1;
    return F(W2)-F(W1);
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,m;

    while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
    {
       int ini = 0,fin = 3e8;
       while(ini<=fin)
       {
            int mid = (ini + fin)/2;
            if(F(mid)>n)
                fin = mid -1;
            else
                ini = mid + 1;
       }
       int w= ini -1;
       ini = 0 , fin = w;
       while(ini<=fin)
       {
            int mid = (ini+fin)/2;
            if(F2(mid,w)<m)
               fin = mid -1 ;
            else
               ini = mid + 1;
       }
       printf("%d\n",F(ini-1));
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


