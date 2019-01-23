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
#define MAX_N 2


lli mod;
struct Matrix{
    lli mat[MAX_N][MAX_N];
};

Matrix matMul(Matrix a, Matrix b)
{
    Matrix ans; int i, j, k;
    for (i = 0; i < MAX_N; i++)
        for (j = 0; j < MAX_N; j++)
            for (ans.mat[i][j] = k = 0; k < MAX_N; k++)
                ans.mat[i][j] = (ans.mat[i][j]%mod+(a.mat[i][k]%mod * b.mat[k][j]%mod)%mod)%mod;
    return ans;
}

Matrix matPow(Matrix base, lli p)
 {
    Matrix ans; int i, j;
        for (i = 0; i < MAX_N; i++)
            for (j = 0; j < MAX_N; j++)
                ans.mat[i][j] = (i == j);
    while (p)
    {
        if (p & 1ll) ans = matMul(ans, base);
        base = matMul(base, base);
        p>>=1ll;
    }
    return ans;
}
lli powt(lli base,lli exp)
{
    lli res=1;
    REP(i,exp)
        res*=base;
    return res;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    lli p,m;

while(~scanf("%lld %lld",&p,&m))
{
    if(p==0)
        printf("0\n");
    else
    {
        mod=powt(2,m);
        Matrix b;
        b.mat[0][0]=b.mat[0][1]=b.mat[1][0]=1;
        b.mat[1][1]=0;
        Matrix r=matPow(b,p-1);
        printf("%lld\n",r.mat[0][0]);
    }

}
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}

