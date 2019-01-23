
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

int y,n;
while(~scanf("%d %d",&y,&n))
{
    VE arr;
    int temp;
    REP(i,n)
    {
        scanf("%d",&temp);
        arr.PB(temp);
    }
    int x = 0,id1=0,id2=0;
    REP(i,n)
    {
        int v = arr[i]-y;
        int ind = upper_bound(all(arr),v)-arr.begin();
        int val = i - ind +1;
        if(val>x)
        {
            x = val;
            id2 = arr[i];
            id1 = arr[ind];
        }
    }
    printf("%d %d %d\n",x,id1,id2);
}
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


