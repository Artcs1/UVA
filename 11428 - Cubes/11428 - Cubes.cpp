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
    vector<lli>arr;
    arr.PB(0);
    lli val=1;
    while((val*val*val)-arr[arr.size()-1]<10000)
    {
        arr.PB((val*val*val));
        val++;
    }
    //adebug(arr,arr.size());
    lli n;
    while(~scanf("%lld",&n),n)
    {
        int ind = lower_bound(all(arr),n)-arr.begin(),ind2,ind3;
        //debug(ind);
        bool band=false;
        FOR(i,ind,arr.size())
        {
            lli val=arr[i]-n;
            ind2=lower_bound(all(arr),val)-arr.begin();
            if(arr[ind2]==val)
            {
                ind3=i;
                band=true;
                break;
            }
        }
        (band)?printf("%d %d\n",ind3,ind2):printf("No solution\n");
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}

