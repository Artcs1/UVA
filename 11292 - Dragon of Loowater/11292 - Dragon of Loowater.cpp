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
    int n,m;
    while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
    {
        int dragons[n],knights[m];
        REP(i,n)
            scanf("%d",&dragons[i]);
        REP(i,m)
            scanf("%d",&knights[i]);
        sort(dragons,dragons+n);
        sort(knights,knights+m);
        int d=0,k=0,pay=0;
        while(d<n&&k<m)
        {
            while(knights[k]<dragons[d]&&k<m)k++;
            if(k==m) break;
            pay+=knights[k];
            k++,d++;
        }
        (d==n)?printf("%d\n",pay):printf("Loowater is doomed!\n");
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}






