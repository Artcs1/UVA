
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
#define inf_i (1<<29)-1


VE arr;
int func(int val)
{
    int t = arr.size();
    REP(i,t)
    {
        if(val==arr[i])
            val--;
        else if(val<arr[i])
            return false;
    }
    return true;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,m,temp;
    scanf("%d",&n);
    REP(i,n)
    {
        VE T;
        scanf("%d",&m);
        arr.clear();
        T.PB(0);
        REP(j,m)
        {
            scanf("%d",&temp);
            T.PB(temp);
        }

        REP(j,m)
            arr.PB(T[j+1]-T[j]);
        int ini = 0, fin =inf_i;
        while(ini<=fin)
        {
            int mid=(ini+fin)/2;
            if(func(mid))
                fin = mid-1;
            else
                ini = mid+1;
        }
        printf("Case %d: %d\n",i+1,fin+1);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


