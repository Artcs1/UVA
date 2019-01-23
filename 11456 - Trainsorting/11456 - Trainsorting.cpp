
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
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        int arr[2005];
        int lisA[2005],lisB[2005];
        scanf("%d",&n);
        REP(i,n)
        {
            scanf("%d",&arr[i]);
        }
        VE A,B;
        reverse(arr,arr+n);
        vector<int>::iterator it,it2;
        int maxi =0 ;
        REP(i,n)
        {
            int val = arr[i];
            it = lower_bound(all(A),-val);
            it2 = lower_bound(all(B),val);
            int i1=it-A.begin(),i2=it2-B.begin();
            if(it == A.end())
                A.PB(-val);
            else
            {
                A.erase(it);
                A.insert(it,-val);
            }
            if(it2 == B.end())
                B.PB(val);
            else
            {
                B.erase(it2);
                B.insert(it2,val);
            }
            lisA[i] = i1+1;
            lisB[i] = i2+1;
            maxi = max(maxi,lisA[i]+lisB[i]-1);
        }
        printf("%d\n",maxi);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


