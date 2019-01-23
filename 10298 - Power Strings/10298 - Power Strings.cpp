
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

string P,T;
vector<int>b;
int n,m,c;

void kmpProcess()
{
    int i=0,j=-1;b[0]=-1;
    while(i<m)
    {
        while( j>=0 && P[i]!=P[j])j=b[j];
        i++;j++;
        b[i] = j;
    }
}

void kmpSearch()
{
    int i=0,j=0;
    while(i<n)
    {
        while(j>=0 && T[i]!=P[j]) j=b[j];
        i++;j++;
        if(j==m)
            c++,j=b[j];
     }
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

    while(cin>>P)
    {
        if(P[0]=='.'&&P.size()==1)
            break;

        T = P+P;
        n = T.size();
        m = P.size();
        b.resize(m+1,0);

        kmpProcess();
        c = 0;
        kmpSearch();

        printf("%d\n",c-1);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}




